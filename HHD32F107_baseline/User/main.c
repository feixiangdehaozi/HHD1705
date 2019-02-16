/*******************************************************************************
  * Company: Hiwafer Technology Co., Ltd.
  ******************************************************************************
  * 文件名称：main.c
  * 功能说明：
  * 版    本：V1.0
  * 作    者：EnderWigg	
  * 日    期：1019.1.21

********************************************************************************/
#include <stdio.h>
#include "hhd32f1xx.h"
#include "hhd32f10x_conf.h"
#include "netconf.h"
#include "hhd32f107.h"
#include "simulator_spi.h"
#include "load_server.h"
#include "IO_Init.h"
#include "Gpio_IO.h"
#include "lib_xvc.h"


/* Private variables ---------------------------------------------------------*/
__IO uint32_t LocalTime = 0; /* this variable is used to create a time reference incremented by 10ms */

/*****************************************************************************************************
*
*	Pin  功能配置表
*   工程中所有用到的Pin应该在此指定功能
*****************************************************************************************************/
ST_PINS pins_table[] = 
{
//			port,   pin,  af,   dir,			Mode	
	__HHD_PIN(A,	9,    1,	AF_FUNCATIOON,	GPIO_Mode_PUE),		//uart1_tx
	__HHD_PIN(A,    10,   1,    AF_FUNCATIOON,  GPIO_Mode_PUE),		//uart1_rx
	__HHD_PIN(E,    2,    0,    OUTPUT,  		GPIO_Mode_DEF),		//LED
	__HHD_PIN(C,    6,    0,    OUTPUT,  		GPIO_Mode_DEF),		//88E1111 HW_CONFIG[4]
#ifdef MII_MODE		
	__HHD_PIN(C,    9,    0,    OUTPUT,  		GPIO_Mode_DEF),		////88E1111复位引脚	
	__HHD_PIN(B,    12,   2,    AF_FUNCATIOON,  GPIO_Mode_DEF),		//MII_TXD0
	__HHD_PIN(B,    13,   2,    AF_FUNCATIOON,  GPIO_Mode_DEF),		//MII_TXD1
	__HHD_PIN(C,    2,    4,    AF_FUNCATIOON,  GPIO_Mode_DEF),		//MII_TXD2
	__HHD_PIN(B,    8,    2,    AF_FUNCATIOON,  GPIO_Mode_DEF),		//MII_TXD3	
	__HHD_PIN(C,    3,    4,    AF_FUNCATIOON,  GPIO_Mode_DEF),		//TX CLK in
	__HHD_PIN(B,    11,   2,    AF_FUNCATIOON,  GPIO_Mode_DEF),		//MII_TXDEN
	
	__HHD_PIN(C,    4,    4,    AF_FUNCATIOON,  GPIO_Mode_DEF),		//MII_RXD0
	__HHD_PIN(C,    5,    4,    AF_FUNCATIOON,  GPIO_Mode_DEF),		//MII_RXD1
	__HHD_PIN(B,    0,    4,    AF_FUNCATIOON,  GPIO_Mode_DEF),		//MII_RXD2
	__HHD_PIN(B,    1,    4,    AF_FUNCATIOON,  GPIO_Mode_DEF),		//MII_RXD3
	__HHD_PIN(A,    7,    3,    AF_FUNCATIOON,  GPIO_Mode_DEF),		//RX_DV
	__HHD_PIN(A,    1,    4,    AF_FUNCATIOON,  GPIO_Mode_DEF),		//RX_CLK
	
	__HHD_PIN(B,    10,   2,    AF_FUNCATIOON,  GPIO_Mode_DEF),		//RX_EEROR
	__HHD_PIN(C,    1,    4,    AF_FUNCATIOON,  GPIO_Mode_DEF),		//MDC
	__HHD_PIN(A,    2,    4,    AF_FUNCATIOON,  GPIO_Mode_DEF),		//MDIO
	__HHD_PIN(A,    0,    4,    AF_FUNCATIOON,  GPIO_Mode_DEF),		//CRS
	__HHD_PIN(A,    3,    4,    AF_FUNCATIOON,  GPIO_Mode_DEF),		//COL
#else
	__HHD_PIN(B,    11,   0,    AF_FUNCATIOON,  GPIO_Mode_DEF),		//RMII_TXDEN
	__HHD_PIN(B,    12,   0,    AF_FUNCATIOON,  GPIO_Mode_DEF),		//RMII_TXD0
	__HHD_PIN(B,    13,   0,    AF_FUNCATIOON,  GPIO_Mode_DEF),		//RMII_TXD1
	__HHD_PIN(A,    1,    0,    AF_FUNCATIOON,  GPIO_Mode_DEF),		//RX_CLK
	__HHD_PIN(C,    4,    0,    AF_FUNCATIOON,  GPIO_Mode_DEF),		//RMII_RXD0
	__HHD_PIN(C,    5,    0,    AF_FUNCATIOON,  GPIO_Mode_DEF),		//RMII_RXD1
	__HHD_PIN(D,    8,    0,    AF_FUNCATIOON,  GPIO_Mode_DEF),		//CRS_RDV
	__HHD_PIN(C,    1,    0,    AF_FUNCATIOON,  GPIO_Mode_DEF),		//MDC
	__HHD_PIN(A,    2,    0,    AF_FUNCATIOON,  GPIO_Mode_DEF),		//MDIO
#endif
};

/*******************************************************************************************************
*
*	MCU 硬件接口初始化
*
*******************************************************************************************************/
void peripheral_init(void)
{
	GPIO_ResetPin(GPIOE, PIN2);
	simulator_Init();
	System_Setup();
}
/*******************************************************************************************************
*
*	应用代码初始化
*
*******************************************************************************************************/
void application_init(void)
{
	LwIP_Init();

	tcp_LoadServer_init();
//	jtagServer_init();					
}



int main(void)
{
	IO_init(pins_table, sizeof(pins_table)/sizeof(ST_PINS));
	peripheral_init();
	application_init();
	
	printf("UART1 Init OK!!!\n\r");
	
	while(1)
	{
		Delay(500);
		GPIO_ResetPin(GPIOE, PIN2);
		Delay(500);
		GPIO_SetPin(GPIOE, PIN2);
	}
}



/*********************************************************************************************************
  * @brief  Updates the system local time
  * @param  None
  * @retval None
  ********************************************************************************************************/
void Time_Update(void)
{
  LocalTime += SYSTEMTICK_PERIOD_MS;
}

/*********************************************************************************************************
  * @brief  Handles the periodic tasks of the system
  * @param  None
  * @retval None
  ********************************************************************************************************/
void System_Periodic_Handle(void)
{ 
  /* LwIP periodic services are done here */
  LwIP_Periodic_Handle(LocalTime);
}
/*********************************************************************************************************
*
*	获取SysTick
*
**********************************************************************************************************/
uint32_t Get_Tick(void)
{
	return LocalTime;
}

/**********************************************************************************************************
*
*	基于SysTick的延时
*
***********************************************************************************************************/
void Delay(uint32_t nCount)
{
	uint32_t timingdelay = 0;
  /* Capture the current local time */
  timingdelay = LocalTime + nCount;  

  /* wait until the desired delay finish */  
  while(timingdelay > LocalTime)
  {     
  }
}
/***********************************************************************************************************
*
*	Printf 定向到串口Uart1
*
************************************************************************************************************/
int fputc(int data , FILE * fd)
{
	while (UART1->STAT.bit.TXF)
	{
	
	}
	UART1->DAT.all= (data & 0xFF);
	return data;
}