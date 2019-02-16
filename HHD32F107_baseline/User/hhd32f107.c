/**
  ******************************************************************************
  * @file    g32f107.c
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    11/20/2009
  * @brief   HH32F107 hardware configuration
  ******************************************************************************
  * @copy
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2009 STMicroelectronics</center></h2>
  */

/* Includes ------------------------------------------------------------------*/
#include "hhd32f107.h"
#include "hhd_sys.h"
#include "hhd_eth.h"
#include "hhd32f10x_conf.h"


/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
void GPIO_Configuration(void);
void NVIC_Configuration(void);
void Ethernet_Configuration(void);

/*---LCD延时函数 1MS*nCount-----*/
void Delay_1ms(uint32_t nCount)
{
	volatile int i;	 	
	for (i=0;i<nCount*10;i++);
}




/*********************************************************************************************
  * @brief  Setup HHD1705 system (clocks, Ethernet, GPIO, NVIC) and STM3210C-EVAL resources.
  * @param  None
  * @retval None
  *******************************************************************************************/
void System_Setup(void)
{
	SysTick_Config(75000000 /100);  /* SystTick configuration: an interrupt every 10ms */

	/* ---------- Set Uart1 Baudrate to 115200, no parity check ------------- */
	UART_Open(UART1,115200,UART_NO_PARITY,UART_RX_HALF_FULL);
	UART_EnableInt(UART1, UART_RX_NOT_EMPTY);
	NVIC_EnableIRQ(UART1_IRQn);
	
	NVIC_Configuration();  
	Ethernet_Configuration();        /* Configure the Ethernet peripheral */

	NVIC_SetPriority (SysTick_IRQn, 1);/* Update the SysTick IRQ priority should be higher than the Ethernet IRQ */
}

/**********************************************************************************************
*
*	自动获取PHY地址
*
**********************************************************************************************/
uint16_t get_phyaddr(void)
{
	int i = 0;
	uint16_t temp = 0;
	for(i=0; i<=0x1F; i++)
	{
		temp = ETH_ReadPHYRegister(i, 0x02);

		if( temp != 0xFFFF )
		{
			return i;	
		}
	}
	return -1;
}


/**
  * @brief  Configures the Ethernet Interface
  * @param  None
  * @retval None
  */

void Ethernet_Configuration(void)
{
	uint32_t timeout = 0;
	uint16_t phyaddr = 0;
	ETH_InitTypeDef ETH_InitStructure;

#ifdef MII_TO_SGMII	
	GPIO_ResetPin(GPIOC, PIN6);
#else
	GPIO_SetPin(GPIOC, PIN6);
#endif
	
#ifdef MII_MODE
	(*(unsigned int*)0x40021280)=0x0303;		//25M	
	SYSCON->GMACCTRL.bit.MODE = 0;  			//0是MII模式
#else
	SYSCON->GMACCTRL.bit.MODE = 4;				//4是RMII MODE
#endif
	SYSCON->SYSAHBCLKDIV.all  = 1;
	 
	GPIO_SetPin(GPIOC, PIN9);
	Delay_1ms(5000);
	GPIO_ResetPin(GPIOC, PIN9);
	Delay_1ms(5000);
	GPIO_SetPin(GPIOC, PIN9);
	Delay_1ms(5000);
  /* Reset ETHERNET on AHB Bus */
  ETH_DeInit();

  /* Software reset */
  ETH_SoftwareReset();

  /* Wait for software reset */
  timeout = Get_Tick();
  while ((ETH_GetSoftwareResetStatus() == SET) && (Get_Tick()-timeout) < ETH_TIMEOUT )
  {
	
  }

  /* ETHERNET Configuration ------------------------------------------------------*/
  /* Call ETH_StructInit if you don't like to configure all ETH_InitStructure parameter */
  ETH_StructInit(&ETH_InitStructure);

  /* Fill ETH_InitStructure parametrs */
  /*------------------------   MAC   -----------------------------------*/
  ETH_InitStructure.ETH_AutoNegotiation = ETH_AutoNegotiation_Disable  ;
  ETH_InitStructure.ETH_LoopbackMode = ETH_LoopbackMode_Disable;
  ETH_InitStructure.ETH_RetryTransmission = ETH_RetryTransmission_Disable;
  ETH_InitStructure.ETH_AutomaticPadCRCStrip = ETH_AutomaticPadCRCStrip_Disable;
  ETH_InitStructure.ETH_ReceiveAll = ETH_ReceiveAll_Disable;
  ETH_InitStructure.ETH_BroadcastFramesReception = ETH_BroadcastFramesReception_Enable;
  ETH_InitStructure.ETH_PromiscuousMode = ETH_PromiscuousMode_Disable;
  ETH_InitStructure.ETH_MulticastFramesFilter = ETH_MulticastFramesFilter_Perfect;
  ETH_InitStructure.ETH_UnicastFramesFilter = ETH_UnicastFramesFilter_Perfect;
#ifdef CHECKSUM_BY_HARDWARE
  ETH_InitStructure.ETH_ChecksumOffload = ETH_ChecksumOffload_Enable;
#endif

  /*------------------------   DMA   -----------------------------------*/  
  
  /* When we use the Checksum offload feature, we need to enable the Store and Forward mode: 
  the store and forward guarantee that a whole frame is stored in the FIFO, so the MAC can insert/verify the checksum, 
  if the checksum is OK the DMA can handle the frame otherwise the frame is dropped */
  ETH_InitStructure.ETH_DropTCPIPChecksumErrorFrame = ETH_DropTCPIPChecksumErrorFrame_Enable; 
  ETH_InitStructure.ETH_ReceiveStoreForward = ETH_ReceiveStoreForward_Enable;         
  ETH_InitStructure.ETH_TransmitStoreForward = ETH_TransmitStoreForward_Enable;     
 
  ETH_InitStructure.ETH_ForwardErrorFrames = ETH_ForwardErrorFrames_Disable;       
  ETH_InitStructure.ETH_ForwardUndersizedGoodFrames = ETH_ForwardUndersizedGoodFrames_Disable;   
  ETH_InitStructure.ETH_SecondFrameOperate = ETH_SecondFrameOperate_Enable;                                                          
  ETH_InitStructure.ETH_AddressAlignedBeats = ETH_AddressAlignedBeats_Enable;      
  ETH_InitStructure.ETH_FixedBurst = ETH_FixedBurst_Enable;                
  ETH_InitStructure.ETH_RxDMABurstLength = ETH_RxDMABurstLength_32Beat;          
  ETH_InitStructure.ETH_TxDMABurstLength = ETH_TxDMABurstLength_32Beat;                                                                 
  ETH_InitStructure.ETH_DMAArbitration = ETH_DMAArbitration_RoundRobin_RxTx_2_1;

  phyaddr = get_phyaddr();
  if(phyaddr > 0x1F)
  {
	phyaddr = 0;
	while(1);
  }
  /* Configure Ethernet */
  ETH_Init(&ETH_InitStructure, phyaddr);

  /* Enable the Ethernet Rx Interrupt */
  ETH_DMAITConfig(ETH_DMA_IT_NIS | ETH_DMA_IT_R, ENABLE);
}

void NVIC_Configuration(void)
{
	NVIC_EnableIRQ(ETH_IRQn);
}

/***********************END OF FILE**********************************************/
