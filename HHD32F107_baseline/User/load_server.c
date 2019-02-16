/***************************************************************************************
//                                                                                    //
//								 SPI TCP Server (RAW) ��                              //
//                                                                                    //
//                                                                                    //
// ��TCP����������ת���������ݵ�SPI�ӿ�												  //
// 1�����ӵ��������󣬿ͻ���ͨ��"getinfo:"����ѯ������ÿ���ܽ��յ�������ݳ��Ⱥ�spi�� //
//    �ڲ���λ������������һ���ܽ��յ�������ݳ��Ⱥ�spi����λ��					  //
// 2���ͻ��˸��ݻ�ȡ������󻺳���Ϣ���������ݵķ��ʹ��������ô���ͨ��"fileinfo:"xxxx //
//    ��������������ͬʱ�ͻ��˱�֤���ݰ�����λ�����								  //
// 3����������������ʱ������֡����Ƿ��������������᷵�ظ��ͻ��˴��󣬲�ָ��������֡//
//    ����ţ������������յ�����ͨ��SPI������ɺ󣬲Żᷴ���ͻ��˽�����ɣ��ͻ��˱��� //
//    ���յ�Ӧ����ٷ�����һ֡����													  //
// 4�����������յ����ݵ�֡������"fileinfo:"xxxx��ָʾ����������Ϊ���ݽ�����ɣ��ȴ�   //
//    "fileinfo:"xxxx ָ��������µ�ͨ��                                            //
// 5���������ݹ����У�����ȡ�����ؿͻ��˷���ȡ��ָ��"!!!!"(0x21212121),�������ص��ȵ� //
//    ��fileinfo:��״̬                                                                 //
//	@Ender     																		  //			
 **************************************************************************************/


#include <string.h>
#include "lwip/debug.h"
#include "lwip/stats.h"
#include "lwip/tcp.h"
#include "simulator_spi.h"
#include "load_server.h"

#define  uint8_t	u8_t
#define  uint16_t	u16_t


#if LWIP_TCP

static struct tcp_pcb *tcp_echoserver_pcb;

/* ECHO protocol states */
enum tcp_echoserver_states
{
  ES_NONE = 0,
  ES_ACCEPTED,
  ES_RECEIVED,
  ES_CLOSING
};



/* structure for maintaing connection infos to be passed as argument 
   to LwIP callbacks*/
struct tcp_echoserver_struct
{
  u8_t state;             /* current connection state */
  u8_t retries;
  struct tcp_pcb *pcb;    /* pointer on the current tcp_pcb */
  struct pbuf *p;         /* pointer on the received/to be transmitted pbuf */
};


static err_t tcp_echoserver_accept(void *arg, struct tcp_pcb *newpcb, err_t err);
static err_t tcp_echoserver_recv(void *arg, struct tcp_pcb *tpcb, struct pbuf *p, err_t err);
static void tcp_echoserver_error(void *arg, err_t err);
static err_t tcp_echoserver_poll(void *arg, struct tcp_pcb *tpcb);
static err_t tcp_echoserver_sent(void *arg, struct tcp_pcb *tpcb, u16_t len);
static void tcp_echoserver_send(struct tcp_pcb *tpcb, struct tcp_echoserver_struct *es);
static void tcp_echoserver_connection_close(struct tcp_pcb *tpcb, struct tcp_echoserver_struct *es);





//uint8_t *temp_buff = NULL; 
uint16_t totaFrameCount = 0;
uint8_t data_buff[MAX_PACKAGE_LEN] = {0};
enum tcp_work_states en_WorkState = ES_GETINFO;
uint8_t buff[10] = {0};

static int read_data(struct tcp_pcb *tpcb, struct tcp_echoserver_struct *es, uint8_t *data)
{
	struct pbuf *ptr;
	int count = 0;
	u16_t plen;
	u8_t freed;
 
	while ((es->p != NULL) && 
			(es->p->len <= tcp_sndbuf(tpcb)))
	{
		/* get pointer on pbuf from es structure */
		ptr = es->p;
		memcpy(data+count, ptr->payload, ptr->len);  

		count += ptr->len;
		plen = ptr->len;

		es->p = ptr->next;
		if(es->p != NULL)
		{
			pbuf_ref(es->p);
		}
		do
		{
			freed = pbuf_free(ptr);
		}
		while(freed == 0);
		
		tcp_recved(tpcb, plen);
	}
	
	return count;
}

int info_deal(uint8_t *data)
{
	
	uint32_t startaddr = 0;
	if(memcmp(data, "getinfo:", 8) == 0)
	{
		((uint16_t *)data)[0] = MAX_PACKAGE_LEN-10;	//��������С
		((uint16_t *)data)[1] = 8;				        //���ݶ���
		
		return 4;
	}
	else if(memcmp(data, "fileinfo:", 9) == 0)
	{
		startaddr = *(uint32_t*)(data+9);
		totaFrameCount = *(uint16_t*)(data+13);
		
		memcpy(data, data+9, 6);
		memcpy(buff, "STAT", 4);
		memcpy(buff+4, data, 4);			
		
		writeArray(buff, 8);				//д������ʼд���ַ
		return 6; 
	}
	else 
	{
		return 4;
	}
}
/**************************************************************************************
*
*	֡�·�����
*
*
**************************************************************************************/
int frame_handler(uint8_t *data)
{
	static uint16_t frame_count = 0;
	uint16_t count = 0;
	uint16_t len = 0;
	
	if(*(uint32_t *)data == 0x21212121)    //"!!!!"
	{
		writeArray(data, 4);				//��ʾ���նˣ������ѽ��յ�����
		frame_count = 0;
		totaFrameCount = 0;
		return -2;
	}
	
	count = *(uint16_t *)data;
	len   = *((uint16_t *)(data+2));
	
	if(frame_count == count)
	{
//		writeArray(data+4, len);
		
		frame_count++;
		totaFrameCount--;
		
		data[2] = 0;
		data[3] = 0;
	}
	else
	{
		*(uint16_t *)data = frame_count;
		*((uint16_t *)data+2) = 1;
	}

	if(totaFrameCount == 0)
	{
		frame_count = 0;
		totaFrameCount = 0;
		
		memcpy(buff,"ENDT",4);
		writeArray(buff, 4);				//д������ʼд���ַ
		return 6;
	}
	else
	{
		return 4;
	}	
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
//												���繦��										    //
//																									//
//////////////////////////////////////////////////////////////////////////////////////////////////////
/**
  * @brief  Initializes the tcp load server
  * @param  None
  * @retval None
  */
void tcp_LoadServer_init(void)
{
  /* create new tcp pcb */
  tcp_echoserver_pcb = tcp_new();

  if (tcp_echoserver_pcb != NULL)
  {
    err_t err;
    
    /* bind echo_pcb to port 7 (ECHO protocol) */
    err = tcp_bind(tcp_echoserver_pcb, IP_ADDR_ANY, SPI_PORT);
    
    if (err == ERR_OK)
    {
      /* start tcp listening for echo_pcb */
      tcp_echoserver_pcb = tcp_listen(tcp_echoserver_pcb);
      
      /* initialize LwIP tcp_accept callback function */
      tcp_accept(tcp_echoserver_pcb, tcp_echoserver_accept);
    }
    else 
    {
      /* deallocate the pcb */
      memp_free(MEMP_TCP_PCB, tcp_echoserver_pcb);
    }
  }
}

/**
  * @brief  This function is the implementation of tcp_accept LwIP callback
  * @param  arg: not used
  * @param  newpcb: pointer on tcp_pcb struct for the newly created tcp connection
  * @param  err: not used 
  * @retval err_t: error status
  */
static err_t tcp_echoserver_accept(void *arg, struct tcp_pcb *newpcb, err_t err)
{
  err_t ret_err;
  struct tcp_echoserver_struct *es;

  LWIP_UNUSED_ARG(arg);
  LWIP_UNUSED_ARG(err);

  /* set priority for the newly accepted tcp connection newpcb */
  tcp_setprio(newpcb, TCP_PRIO_MIN);

  /* allocate structure es to maintain tcp connection informations */
  es = (struct tcp_echoserver_struct *)mem_malloc(sizeof(struct tcp_echoserver_struct));
  if (es != NULL)
  {
    es->state = ES_ACCEPTED;
    es->pcb = newpcb;
    es->retries = 0;
    es->p = NULL;
    
    /* pass newly allocated es structure as argument to newpcb */
    tcp_arg(newpcb, es);
    
    /* initialize lwip tcp_recv callback function for newpcb  */ 
    tcp_recv(newpcb, tcp_echoserver_recv);
    
	   /* initialize LwIP tcp_sent callback function */
    tcp_sent(newpcb, tcp_echoserver_sent);
    /* initialize lwip tcp_err callback function for newpcb  */
    tcp_err(newpcb, tcp_echoserver_error);
    
    /* initialize lwip tcp_poll callback function for newpcb */
    tcp_poll(newpcb, tcp_echoserver_poll, 0);
    
    ret_err = ERR_OK;
  }
  else
  {
    /*  close tcp connection */
    tcp_echoserver_connection_close(newpcb, es);
    /* return memory error */
    ret_err = ERR_MEM;
  }
  return ret_err;  
}


/**
  * @brief  This function is the implementation for tcp_recv LwIP callback
  * @param  arg: pointer on a argument for the tcp_pcb connection
  * @param  tpcb: pointer on the tcp_pcb connection
  * @param  pbuf: pointer on the received pbuf
  * @param  err: error information regarding the reveived pbuf
  * @retval err_t: error code
  */
static err_t tcp_echoserver_recv(void *arg, struct tcp_pcb *tpcb, struct pbuf *p, err_t err)
{
	struct tcp_echoserver_struct *es;
	err_t ret_err;
	int ret = 0;
	
  LWIP_ASSERT("arg != NULL",arg != NULL);
  
  es = (struct tcp_echoserver_struct *)arg;
  
  /* if we receive an empty tcp frame from client => close connection */
  if (p == NULL)
  {
    /* remote host closed connection */
    es->state = ES_CLOSING;
    if(es->p == NULL)
    {
       /* we're done sending, close connection */
       tcp_echoserver_connection_close(tpcb, es);
    }
    else
    {
      /* we're not done yet */
      /* acknowledge received packet */
      tcp_sent(tpcb, tcp_echoserver_sent);
      
      /* send remaining data*/
      tcp_echoserver_send(tpcb, es);
    }
    ret_err = ERR_OK;
  }   
  /* else : a non empty frame was received from client but for some reason err != ERR_OK */
  else if(err != ERR_OK)
  {
    /* free received pbuf*/
    if (p != NULL)
    {
      es->p = NULL;
      pbuf_free(p);
    }
    ret_err = err;
  }
  else if((es->state == ES_RECEIVED) || (es->state == ES_ACCEPTED) )
  {
    /* first data chunk in p->payload */
    es->state = ES_RECEIVED;
    
    /* store reference to incoming pbuf (chain) */
	if(es->p == NULL)
	{	
		es->p = p;
		/* send back received data */
	////////////////////////////////////////////////////////////////////////////////////////////////
		ret =  read_data(tpcb, es, data_buff);                    //��������
		if((ret > 0) && en_WorkState !=  ES_SENDDATA)			   
		{
			ret = info_deal(data_buff);                            //Э��ͨ�Ų���
			if(ret == 4)
			{
				en_WorkState = ES_FILEINFO;
			}
			else
			{
				en_WorkState = ES_SENDDATA;	
			}
			tcp_write(tpcb, data_buff, ret, 1);
		}
		else if ((ret > 0) && en_WorkState ==  ES_SENDDATA)
		{
			ret = frame_handler(data_buff);						  //�����·�����
			if(ret > 0)
			{
				if(ret >= 5)
				{
					en_WorkState =  ES_FILEINFO;
				}
			}
			else
			{
				en_WorkState =  ES_CANCEL;
				
			}
			tcp_write(tpcb, data_buff, 4, 1);
		} 
	}
    else
    {
      struct pbuf *ptr;

      /* chain pbufs to the end of what we recv'ed previously  */
      ptr = es->p;
      pbuf_chain(ptr,p);
    }
///////////////////////////////////////////////////////////////////////////////////////////////	  
   
    ret_err = ERR_OK;
  }

  else if(es->state == ES_CLOSING)
  {
    /* odd case, remote side closing twice, trash data */
    tcp_recved(tpcb, p->tot_len);
    es->p = NULL;
    pbuf_free(p);
    ret_err = ERR_OK;
  }
  else
  {
    /* unkown es->state, trash data  */
    tcp_recved(tpcb, p->tot_len);
    es->p = NULL;
    pbuf_free(p);
    ret_err = ERR_OK;
  }
  return ret_err;
}

/**
  * @brief  This function implements the tcp_err callback function (called
  *         when a fatal tcp_connection error occurs. 
  * @param  arg: pointer on argument parameter 
  * @param  err: not used
  * @retval None
  */
static void tcp_echoserver_error(void *arg, err_t err)
{
  struct tcp_echoserver_struct *es;

  LWIP_UNUSED_ARG(err);

  es = (struct tcp_echoserver_struct *)arg;
  if (es != NULL)
  {
    /*  free es structure */
    mem_free(es);
  }
}

/**
  * @brief  This function implements the tcp_poll LwIP callback function
  * @param  arg: pointer on argument passed to callback
  * @param  tpcb: pointer on the tcp_pcb for the current tcp connection
  * @retval err_t: error code
  */
static err_t tcp_echoserver_poll(void *arg, struct tcp_pcb *tpcb)
{
  err_t ret_err;
  struct tcp_echoserver_struct *es;

  es = (struct tcp_echoserver_struct *)arg;
  if (es != NULL)
  {
    if (es->p != NULL)
    {
      tcp_sent(tpcb, tcp_echoserver_sent);
      /* there is a remaining pbuf (chain) , try to send data */
      tcp_echoserver_send(tpcb, es);
    }
    else
    {
      /* no remaining pbuf (chain)  */
      if(es->state == ES_CLOSING)
      {
        /*  close tcp connection */
        tcp_echoserver_connection_close(tpcb, es);
      }
    }
    ret_err = ERR_OK;
  }
  else
  {
    /* nothing to be done */
    tcp_abort(tpcb);
    ret_err = ERR_ABRT;
  }
  return ret_err;
}

/**
  * @brief  This function implements the tcp_sent LwIP callback (called when ACK
  *         is received from remote host for sent data) 
  * @param  None
  * @retval None
  */
static err_t tcp_echoserver_sent(void *arg, struct tcp_pcb *tpcb, u16_t len)
{
  struct tcp_echoserver_struct *es;

  LWIP_UNUSED_ARG(len);

  es = (struct tcp_echoserver_struct *)arg;
  es->retries = 0;
  
  if(es->p != NULL)
  {
    /* still got pbufs to send */
    tcp_sent(tpcb, tcp_echoserver_sent);
    tcp_echoserver_send(tpcb, es);
  }
  else
  {
    /* if no more data to send and client closed connection*/
    if(es->state == ES_CLOSING)
      tcp_echoserver_connection_close(tpcb, es);
  }
  return ERR_OK;
}


/**
  * @brief  This function is used to send data for tcp connection
  * @param  tpcb: pointer on the tcp_pcb connection
  * @param  es: pointer on echo_state structure
  * @retval None
  */
static void tcp_echoserver_send(struct tcp_pcb *tpcb, struct tcp_echoserver_struct *es)
{
  struct pbuf *ptr;
  err_t wr_err = ERR_OK;
 
  while ((wr_err == ERR_OK) &&
         (es->p != NULL) && 
         (es->p->len <= tcp_sndbuf(tpcb)))
  {
    
    /* get pointer on pbuf from es structure */
    ptr = es->p;

    /* enqueue data for transmission */
    wr_err = tcp_write(tpcb, ptr->payload, ptr->len, 1);
    
    if (wr_err == ERR_OK)
    {
      u16_t plen;
      u8_t freed;
		
		
      plen = ptr->len;
     
      /* continue with next pbuf in chain (if any) */
      es->p = ptr->next;
      
      if(es->p != NULL)
      {
        /* increment reference count for es->p */
        pbuf_ref(es->p);
      }
      
     /* chop first pbuf from chain */
      do
      {
        /* try hard to free pbuf */
        freed = pbuf_free(ptr);
      }
      while(freed == 0);
     /* we can read more data now */
     tcp_recved(tpcb, plen);
   }
   else if(wr_err == ERR_MEM)
   {
      /* we are low on memory, try later / harder, defer to poll */
     es->p = ptr;
   }
   else
   {
     /* other problem ?? */
   }
  }
}

/**
  * @brief  This functions closes the tcp connection
  * @param  tcp_pcb: pointer on the tcp connection
  * @param  es: pointer on echo_state structure
  * @retval None
  */
static void tcp_echoserver_connection_close(struct tcp_pcb *tpcb, struct tcp_echoserver_struct *es)
{
  
  /* remove all callbacks */
  tcp_arg(tpcb, NULL);
  tcp_sent(tpcb, NULL);
  tcp_recv(tpcb, NULL);
  tcp_err(tpcb, NULL);
  tcp_poll(tpcb, NULL, 0);
  
  /* delete es structure */
  if (es != NULL)
  {
    mem_free(es);
  }  
  
  /* close tcp connection */
  tcp_close(tpcb);
}

#endif /* LWIP_TCP */
