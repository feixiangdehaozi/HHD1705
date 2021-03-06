/*
 *-----------------------------------------------------------------------------
 * The confidential and proprietary information contained in this file may
 * only be used by a person authorised under and to the extent permitted
 * by a subsisting licensing agreement from ARM Limited.
 *
 *            (C) COPYRIGHT 2010-2011 ARM Limited.
 *                ALL RIGHTS RESERVED
 *
 * This entire notice must be reproduced on all copies of this file
 * and copies of this file may only be made by a person if such person is
 * permitted to do so under the terms of a subsisting license agreement
 * from ARM Limited.
 *
 *-----------------------------------------------------------------------------
 */


#ifndef __CMSDK_H__
#define __CMSDK_H__

#ifdef __cplusplus
 extern "C" {
#endif

/** @addtogroup CMSDK_Definitions CMSDK Definitions
  This file defines all structures and symbols for CMSDK:
    - Registers and bitfields
    - peripheral base address
    - peripheral ID
    - PIO definitions
  @{
*/


/******************************************************************************/
/*                Processor and Core Peripherals                              */
/******************************************************************************/
/** @addtogroup CMSDK_CMSIS CMSDK CMSIS Definitions
  Configuration of the Cortex-M0 Processor and Core Peripherals
  @{
*/

/*
 * ==========================================================================
 * ---------- Interrupt Number Definition -----------------------------------
 * ==========================================================================
 */

typedef enum IRQn
{
/******  Cortex-M0 Processor Exceptions Numbers ***************************************************/
  NonMaskableInt_IRQn           = -14,    /*!< 2 Non Maskable Interrupt                           */
  HardFault_IRQn                = -13,    /*!< 3 Cortex-M3 Hard Fault Interrupt                   */
  MemoryManagement_IRQn         = -12,    /*!< 4 Cortex-M3 Memory Management Interrupt            */ 
  BusFault_IRQn                 = -11,    /*!< 5 Cortex-M3 Bus Fault Interrupt                    */
  UsageFault_IRQn               = -10,    /*!< 6 Cortex-M3 Usage Fault Interrupt                  */
  SVCall_IRQn                   = -5,     /*!< 11 Cortex-M3 SV Call Interrupt                     */
  DebugMonitor_IRQn             = -4,     /*!< 12 Cortex-M3 Debug Monitor Interrupt               */
  PendSV_IRQn                   = -2,     /*!< 14 Cortex-M3 Pend SV Interrupt                     */
  SysTick_IRQn                  = -1,     /*!< 15 Cortex-M3 System Tick Interrupt                 */

/******  CMSDK Specific Interrupt Numbers *******************************************************/
  WWDT_IRQn                     = 0,     /*!< Window watchdog Interrupt                           */	
  BOD_IRQn                      = 1,     /*!< BOD Interrupt                                       */ 
  DAC_IRQn                      = 2,     /*!< BOD Interrupt                                       */     	
  RTC_IRQn                      = 3,     /*!< RTC global Interrupt                                */   
  EXTI0_IRQn                    = 6,     /*!< EXTI line0 Interrupt                                */
  EXTI1_IRQn                    = 7,     /*!< EXTI line1 Interrupt                                */
  EXTI2_IRQn                    = 8,     /*!< EXTI line2 Interrupt                                */
  EXTI3_IRQn                    = 9,     /*!< EXTI line3 Interrupt                                */
  EXTI4_IRQn                    = 10,    /*!< EXTI line4 Interrupt                                */
  DMA1_CHANNEL1_IRQn            = 11,    /*!< DMA1 channel1 Interrupt                             */
  DMA1_CHANNEL2_IRQn            = 12,    /*!< DMA1 channel2 Interrupt                             */
  DMA1_CHANNEL3_IRQn            = 13,    /*!< DMA1 channel3 Interrupt                             */
  DMA1_CHANNEL4_IRQn            = 14,    /*!< DMA1 channel4 Interrupt                             */
  DMA1_CHANNEL5_IRQn            = 15,    /*!< DMA1 channel5 Interrupt                             */
  DMA1_CHANNEL6_IRQn            = 16,    /*!< DMA1 channel6 Interrupt                             */
  DMA1_CHANNEL7_IRQn            = 17,    /*!< DMA1 channel7 Interrupt                             */
  ADC1_2_IRQn                   = 18,    /*!< ADC1 and ADC2 global Interrupt                      */
  USB_IRQn                      = 19,    /*!< USB Interrupt                                       */
    CAN1_IRQn                      = 21,    /*!< CAN bus Interrupt                                   */
  EXTI9_5_IRQn                  = 23,    /*!< EXTI line9 and line5 Interrupt                      */
  TIM1FAULT_TIM9_IRQn           = 24,    /*!< TIM1 fault & TIM9 Interrupt                         */
  TIM10_IRQn                    = 25,    /*!< TIM10 Interrupt                                     */
  TIM11_IRQn                    = 26,    /*!< TIM11 Interrupt                                     */
  TIM1_IRQn                     = 27,    /*!< TIM1 Interrupt                                      */
  TIM2_IRQn                     = 28,    /*!< TIM2 Interrupt                                      */
  TIM3_IRQn                     = 29,    /*!< TIM3 Interrupt                                      */
  TIM4_IRQn                     = 30,    /*!< TIM4 Interrupt                                      */
  I2C1_IRQn                     = 31,    /*!< I2C1 Interrupt                                      */
  I2C2_IRQn                     = 33,    /*!< I2C2 Interrupt                                      */
  SPI1_IRQn                     = 35,    /*!< SPI1 Interrupt                                      */
  SPI2_IRQn                     = 36,    /*!< SPI2 Interrupt                                      */
  UART1_IRQn                    = 37,    /*!< UART1 Interrupt                                     */
  UART2_IRQn                    = 38,    /*!< UART2 Interrupt                                     */
  UART3_IRQn                    = 39,    /*!< UART3 Interrupt                                     */
  EXTI15_10_IRQn                = 40,    /*!< EXTERNAL Line[15:10] Interrupts                     */
  USBWAKEUP_IRQn                = 42,    /*!< USB WAKE up line Interrupt                          */
  TIM8FAULT_TIM12_IRQn          = 43,    /*!< TIM8 fault & TIM12 Interrupt                        */
  TIM13_IRQn                    = 44,    /*!< TIM13 Interrupt                                     */
  TIM14_IRQn                    = 45,    /*!< TIM14 Interrupt                                     */
  TIM8_IRQn                     = 46,    /*!< TIM8 Interrupt                                      */
  ADC3_IRQn                     = 47,    /*!< ADC3 Interrupt                                      */
  TIM5_IRQn                     = 50,    /*!< TIM5 Interrupt                                      */
  SPI3_IRQn                     = 51,    /*!< SPI3 Interrupt                                      */
  UART4_IRQn                    = 52,    /*!< UART4 Interrupt                                     */
  UART5_IRQn                    = 53,    /*!< UART5 Interrupt                                     */
  TIM6_IRQn                     = 54,    /*!< TIM6 Interrupt                                      */
  TIM7_IRQn                     = 55,    /*!< TIM7 Interrupt                                      */
  DMA2_CHANNEL1_IRQn            = 56,    /*!< DMA2 channel1 Interrupt                              */
  DMA2_CHANNEL2_IRQn            = 57,    /*!< DMA2 channel2 Interrupt                              */
  DMA2_CHANNEL3_IRQn            = 58,    /*!< DMA2 channel3 Interrupt                              */
  DMA2_CHANNEL4_5_IRQn          = 59,    /*!< DMA2 channel4 Interrupt                              */
  ETH_IRQn                      = 62,    /*!< ETHERNET Interrupt                                   */
  ETH_PMT_IRQn                  = 63,    /*!< ETHERNET Power MANAGEMENT Interrupt                 */
  CAN2_IRQn                     = 65,    /*!< CAN bus Interrupt                                   */

} IRQn_Type;


/*
 * ==========================================================================
 * ----------- Processor and Core Peripheral Section ------------------------
 * ==========================================================================
 */

/* Configuration of the Cortex-M0 Processor and Core Peripherals */
#define __MPU_PRESENT             1         /*!< MPU present or not                               */
#define __NVIC_PRIO_BITS          3         /*!< Number of Bits used for Priority Levels          */
#define __Vendor_SysTickConfig    0         /*!< Set to 1 if different SysTick Config is used     */

/*@}*/ /* end of group CMSDK_CMSIS */


#include "core_cm3.h"                       /* Cortex-M3 processor and core peripherals           */
#include "system_hhd32F1xx.h"                   /* System Header                                      */
/** @addtogroup Exported_types
  * @{
  */  

/*!< G32F10x Standard Peripheral Library old types (maintained for legacy purpose) */
typedef int32_t  s32;
typedef int16_t s16;
typedef int8_t  s8;

typedef const int32_t sc32;  /*!< Read Only */
typedef const int16_t sc16;  /*!< Read Only */
typedef const int8_t sc8;   /*!< Read Only */

typedef __IO int32_t  vs32;
typedef __IO int16_t  vs16;
typedef __IO int8_t   vs8;

typedef __I int32_t vsc32;  /*!< Read Only */
typedef __I int16_t vsc16;  /*!< Read Only */
typedef __I int8_t vsc8;   /*!< Read Only */

typedef uint32_t  u32;
typedef uint16_t u16;
typedef uint8_t  u8;

typedef const uint32_t uc32;  /*!< Read Only */
typedef const uint16_t uc16;  /*!< Read Only */
typedef const uint8_t uc8;   /*!< Read Only */

typedef __IO uint32_t  vu32;
typedef __IO uint16_t vu16;
typedef __IO uint8_t  vu8;

typedef __I uint32_t vuc32;  /*!< Read Only */
typedef __I uint16_t vuc16;  /*!< Read Only */
typedef __I uint8_t vuc8;   /*!< Read Only */

typedef enum {RESET = 0, SET = !RESET} FlagStatus, ITStatus;

typedef enum {DISABLE = 0, ENABLE = !DISABLE} FunctionalState;
#define IS_FUNCTIONAL_STATE(STATE) (((STATE) == DISABLE) || ((STATE) == ENABLE))

typedef enum {ERROR = 0, SUCCESS = !ERROR} ErrorStatus;

/******************************************************************************/
/*                Device Specific Peripheral Registers structures             */
/******************************************************************************/

#if defined ( __CC_ARM   )
#pragma anon_unions
#endif

/*------------- System Control (SYSCON) --------------------------------------*/
/** @addtogroup GT_SYSCON XT103ZG System Control Block 
  @{
*/
typedef struct
{
  __IO uint32_t SYSMEMREMAP;            /*!< Offset: 0x000 System memory remap (R/W) */
  __IO uint32_t PRESETCTRL;             /*!< Offset: 0x004 Peripheral reset control (R/W) */
  __IO uint32_t SYSPLLCTRL;             /*!< Offset: 0x008 System PLL control (R/W) */
  __IO uint32_t SYSPLLSTAT;             /*!< Offset: 0x00C System PLL status (R/ ) */
	
       uint32_t RESERVED0[4];

    __IO uint32_t SYSOSCCTRL;             /*!< Offset: 0x020 System oscillator control (R/W) */
    __IO uint32_t WDTOSCCTRL;             /*!< Offset: 0x024 Watchdog oscillator control (R/W) */
    __IO uint32_t IRCCTRL;                /*!< Offset: 0x028 IRC control (R/W) */
    uint32_t RESERVED1[1];           /*!< Offset: 0x02C RTC oscillator control (R/W) */

    __IO uint32_t SYSRESSTAT;             /*!< Offset: 0x030 System reset status Register (R/ ) */
    uint32_t RESERVED2[3];

    __IO uint32_t SYSPLLCLKSEL;           /*!< Offset: 0x040 System PLL clock source select (R/W) */
    __IO uint32_t
    SYSPLLCLKUEN;           /*!< Offset: 0x044 System PLL clock source update enable (R/W) */

    uint32_t RESERVED3[10];

  __IO uint32_t MAINCLKSEL;             /*!< Offset: 0x070 Main clock source select (R/W) */
  __IO uint32_t MAINCLKUEN;             /*!< Offset: 0x074 Main clock source update enable (R/W) */
  __IO uint32_t SYSAHBCLKDIV;           /*!< Offset: 0x078 System AHB clock divider (R/W) */
  __IO uint32_t ADCCLKDIV;              /*!< Offset: 0x07c ADC clock divider (R/W) */

  __IO uint32_t SYSAHBCLKCTRL;          /*!< Offset: 0x080 System AHB clock control (R/W) */
  __IO uint32_t SYSAPB2CLKCTRL;         /*!< Offset: 0x084 System APB2 clock control (R/W) */
  __IO uint32_t SYSAPB1CLKCTRL;         /*!< Offset: 0x088 System APB1 clock control (R/W) */
  __IO uint32_t SYSAPB2RESET;           /*!< Offset: 0x08c System APB2 reset control (R/W) */
	
  __IO uint32_t SYSAPB1RESET;           /*!< Offset: 0x090 System APB1 reset control (R/W) */                      
  __IO uint32_t RCCCFGR;                /*!< Offset: 0x094 RCC CFGR control (R/W) */
  __IO uint32_t UARTCLKDIV;             /*!< Offset: 0x098 UART1 clock divider (R/W) */

       uint32_t RESERVED7[17];       
            
  __IO uint32_t CLKOUTCLKSEL;           /*!< Offset: 0x0E0 CLKOUT clock source select (R/W) */
  __IO uint32_t CLKOUTUEN;              /*!< Offset: 0x0E4 CLKOUT clock source update enable (R/W) */
  __IO uint32_t CLKOUTDIV;              /*!< Offset: 0x0E8 CLKOUT clock divider (R/W) */   
	
       uint32_t RESERVED8[24];   

  __IO uint32_t IOCONFIGCLKDIV;	
    	  	            
  __IO uint32_t BODCTRL;                /*!< Offset: 0x150 BOD control (R/W) */
       uint32_t RESERVED10[8];              

  __IO uint32_t INTNMI;                 /*!< Offset: 0x174 NMI interrupt source configuration control (R/W) */
       uint32_t RESERVED12[34];          

  __IO uint32_t EXTICTL;                /*!< Offset: 0x200 EXTI Control ;DSWAKECTL(R/W) */
  __IO uint32_t EXTIEN;                 /*!< Offset: 0x204 EXTI interrupt enable;DSWAKEEN (R/W) */
  __O  uint32_t EXTICLR;                /*!< Offset: 0x208 EXTI interrupt clear;DSWAKECLR (R/W) */
  __I  uint32_t EXTISTAT;               /*!< Offset: 0x208 EXTI interrupt state;DSWAKE (R/W) */
       uint32_t RESERVED13[8];

    __IO uint32_t
    PDSLEEPCFG;             /*!< Offset: 0x230 Power-down states in Deep-sleep mode (R/W) */
    __IO uint32_t PDAWAKECFG;             /*!< Offset: 0x234 Power-down states after wake-up (R/W) */
    __IO uint32_t PDRUNCFG;               /*!< Offset: 0x238 Power-down configuration Register (R/W) */
} HHD_SYSCON_TypeDef;
/*@}*/ /* end of group HHD_SYSCON */

/*------------- Micro DMA controller (DMA) --------------------------*/
/** @addtogroup GT_DMA XT103ZG Micro DMA controller 
  @{
*/
typedef struct
{
    __I  uint32_t STATUS;              /*!< Offset: 0x000 DMA status register (R/) */
    __O  uint32_t CFG;
    __IO uint32_t CTRL_BASE_PTR;
    __I  uint32_t ALT_CTRL_BASE_PTR;
    __I  uint32_t WAITONREQ_STATUS;
    __O  uint32_t CHNL_SW_REQUEST;
    __IO uint32_t CHNL_USEBURST_SET;
    __O  uint32_t CHNL_USEBURST_CLR;

    __IO uint32_t CHNL_REQ_MASK_SET;   /*!< Offset: 0x020 Channel request mask set register (R/W) */
    __O  uint32_t CHNL_REQ_MASK_CLR;
    __IO uint32_t CHNL_ENABLE_SET;
    __O  uint32_t CHNL_ENABLE_CLR;
    __IO uint32_t CHNL_PRI_ALT_SET;
    __O  uint32_t CHNL_PRI_ALT_CLR;
    __IO uint32_t CHNL_PRIORITY_SET;
    __O  uint32_t CHNL_PRIORITY_CLR;   /*!< Offset: 0x034 Channel priority clear register (W) */

    uint32_t RESERVE0[16];          /* 0x40 */

    __IO uint32_t CHNL_IRQ_STATUS;     /*!< Offset: 0x080 Channel DMA interrupt status register (R/W) */
    __IO uint32_t IRQ_ERR_ENABLE;
    __IO uint32_t CHNL_IRQ_ENABLE;
} HHD_DMA_TypeDef;
/*@}*/ /* end of group HHD_DMA */

/*------------- Pin Connect Block (AFIO) --------------------------------*/
/** @addtogroup GT_AFIO XT103ZG I/O Configuration Block 
  @{
*/
typedef struct
{
  __IO uint32_t PA0;
  __IO uint32_t PA1;
  __IO uint32_t PA2;
  __IO uint32_t PA3;
  __IO uint32_t PA4;
  __IO uint32_t PA5;
  __IO uint32_t PA6;
  __IO uint32_t PA7;
  __IO uint32_t PA8;
  __IO uint32_t PA9;
  __IO uint32_t PA10;
  __IO uint32_t PA11;
  __IO uint32_t PA12;
  __IO uint32_t PA13;
  __IO uint32_t PA14;
  __IO uint32_t PA15;
  __IO uint32_t PB0;
  __IO uint32_t PB1;
  __IO uint32_t PB2;
  __IO uint32_t PB3;
  __IO uint32_t PB4;
  __IO uint32_t PB5;
  __IO uint32_t PB6;
  __IO uint32_t PB7;
  __IO uint32_t PB8;
  __IO uint32_t PB9;
  __IO uint32_t PB10;
  __IO uint32_t PB11;
  __IO uint32_t PB12;
  __IO uint32_t PB13;
  __IO uint32_t PB14;
  __IO uint32_t PB15;
  __IO uint32_t PC0;
  __IO uint32_t PC1;
  __IO uint32_t PC2;
  __IO uint32_t PC3;
  __IO uint32_t PC4;
  __IO uint32_t PC5;
  __IO uint32_t PC6;
  __IO uint32_t PC7;
  __IO uint32_t PC8;
  __IO uint32_t PC9;
  __IO uint32_t PC10;
  __IO uint32_t PC11;
  __IO uint32_t PC12;
  __IO uint32_t PC13;
  __IO uint32_t PC14;
  __IO uint32_t PC15;
  __IO uint32_t PD0;
  __IO uint32_t PD1;
  __IO uint32_t PD2;
  __IO uint32_t PD3;
  __IO uint32_t PD4;
  __IO uint32_t PD5;
  __IO uint32_t PD6;
  __IO uint32_t PD7;
  __IO uint32_t PD8;
  __IO uint32_t PD9;
  __IO uint32_t PD10;
  __IO uint32_t PD11;
  __IO uint32_t PD12;
  __IO uint32_t PD13;
  __IO uint32_t PD14;
  __IO uint32_t PD15;
  __IO uint32_t PE0;
  __IO uint32_t PE1;
  __IO uint32_t PE2;
  __IO uint32_t PE3;
  __IO uint32_t PE4;
  __IO uint32_t PE5;
  __IO uint32_t PE6;
  __IO uint32_t PE7;
  __IO uint32_t PE8;
  __IO uint32_t PE9;
  __IO uint32_t PE10;
  __IO uint32_t PE11;
  __IO uint32_t PE12;
  __IO uint32_t PE13;
  __IO uint32_t PE14;
  __IO uint32_t PE15;
  __IO uint32_t PF0;
  __IO uint32_t PF1;
  __IO uint32_t PF2;
  __IO uint32_t PF3;
  __IO uint32_t PF4;
  __IO uint32_t PF5;
  __IO uint32_t PF6;
  __IO uint32_t PF7;
  __IO uint32_t PF8;
  __IO uint32_t PF9;
  __IO uint32_t PF10;
  __IO uint32_t PF11;
  __IO uint32_t PF12;
  __IO uint32_t PF13;
  __IO uint32_t PF14;
  __IO uint32_t PF15;
  __IO uint32_t PG0;
  __IO uint32_t PG1;
  __IO uint32_t PG2;
  __IO uint32_t PG3;
  __IO uint32_t PG4;
  __IO uint32_t PG5;
  __IO uint32_t PG6;
  __IO uint32_t PG7;
  __IO uint32_t PG8;
  __IO uint32_t PG9;
  __IO uint32_t PG10;
  __IO uint32_t PG11;
  __IO uint32_t PG12;
  __IO uint32_t PG13;
  __IO uint32_t PG14;
  __IO uint32_t PG15;
  __IO uint32_t FTMODE;
  
} HHD_AFIO_TypeDef;
/*@}*/ /* end of group HHD_AFIO */


/*------------- General Purpose Input/Output (GPIO) --------------------------*/
/** @addtogroup HHD_GPIO XT103ZG General Purpose Input/Output
  @{
*/
typedef struct
{
    __IO uint32_t MASK;       /*!< Offset: 0x000 Pin value mask register (R/W) */
    __I  uint32_t PIN;
    __IO uint32_t OUT;
    __O  uint32_t SET;
    __O  uint32_t CLR;        /*!< Offset: 0x010 Pin output value clear register (R/W) */
    __O  uint32_t NOT;
    uint32_t RESERVE[2];
    __IO uint32_t DIR;        /*!< Offset: 0x020 Data direction register (R/W) */
    __IO uint32_t IS;
    __IO uint32_t IBE;
    __IO uint32_t IEV;
    __IO uint32_t IE;
    __I  uint32_t RIS;
    __I  uint32_t MIS;
    __O  uint32_t IC;
} HHD_GPIO_TypeDef;
/*@}*/ /* end of group HHD_GPIO */

/*------------- Flash Control --------------------------*/
/** @addtogroup GT_FMC XT103ZG General Purpose Input/Output 
  @{
*/
typedef struct
{
    __IO uint32_t FLASHCTRL;      /*!< Offset: 0x000 Flash control register (R/W) */
    __IO uint32_t PRGDATA;	      /*!< Offset: 0x004 flash program data register (R/W) */
    __IO uint32_t FLASHADDR;	    /*!< Offset: 0x008 flash program/erase address register (R/W) */
    __IO uint32_t RDCYCCFG;       /*!< Offset: 0x00c Read flash cycle config (R/W) */
} HHD_FMC_TypeDef;
/*@}*/ /* end of group HHD_FMC */



/*------------- Comparator (COMP) --------------------------*/
/** @addtogroup GT_COMP XT103ZG Comparator 
  @{
*/
typedef struct
{
    __IO uint32_t CMP;        /*!< Offset: 0x000 Comparator control register (R/W) */
    __IO uint32_t VLAD;       /*!< Offset: 0x004 Voltage ladder register (R/W) */
} HHD_COMP_TypeDef;
/*@}*/ /* end of group HHD_COMP */

/*------------- Timer (TMR) --------------------------------------------------*/
/** @addtogroup GT_TMR XT103ZG 16/32-bit Counter/Timer 
  @{
*/
typedef struct
{
    __IO uint32_t IR;                     /*!< Offset: 0x000 Interrupt Register (R/W) */
    __IO uint32_t TCR;                    /*!< Offset: 0x004 Timer Control Register (R/W) */
    __IO uint32_t TC;                     /*!< Offset: 0x008 Timer Counter Register (R/W) */
    __IO uint32_t PR;                     /*!< Offset: 0x00C Prescale Register (R/W) */
    __IO uint32_t PC;                     /*!< Offset: 0x010 Prescale Counter Register (R/W) */
    __IO uint32_t MCR;                    /*!< Offset: 0x014 Match Control Register (R/W) */
    __IO uint32_t MR[4];                  /*!< Offset: 0x018 Match Register 0 (R/W) */
    __IO uint32_t CCR;                    /*!< Offset: 0x028 Capture Control Register (R/W) */
    __I  uint32_t CR[4];                  /*!< Offset: 0x02C Capture Register 0 (R/ ) */
    __IO uint32_t EMR;                    /*!< Offset: 0x03C External Match Register (R/W) */
    uint32_t RESERVED2[12];
    __IO uint32_t CTCR;                   /*!< Offset: 0x070 Count Control Register (R/W) */
    __IO uint32_t PWMC;                   /*!< Offset: 0x074 PWM Control Register (R/W) */
} HHD_TMR_TypeDef;
/*@}*/ /* end of group HHD_TMR */

/*------------- Timer (TMR) --------------------------------------------------*/
/** @addtogroup GT_BASETMR XT103ZG Base Timer 
  @{
*/
typedef struct
{
    __IO uint32_t IR;                     /*!< Offset: 0x000 Interrupt Register (R/W) */
    __IO uint32_t TCR;                    /*!< Offset: 0x004 Timer Control Register (R/W) */
    __IO uint32_t TC;                     /*!< Offset: 0x008 Timer Counter Register (R/W) */
    __IO uint32_t PR;                     /*!< Offset: 0x00C Prescale Register (R/W) */
    __IO uint32_t PC;                     /*!< Offset: 0x010 Prescale Counter Register (R/W) */
    __IO uint32_t MCR;                    /*!< Offset: 0x014 Match Control Register (R/W) */
    __IO uint32_t MR0;                    /*!< Offset: 0x018 Match Register 0 (R/W) */
    __IO uint32_t MR1;                    /*!< Offset: 0x01C Match Register 1 (R/W) */
} HHD_BASETMR_TypeDef;
/*@}*/ /* end of group HHD_TMR */

/*------------- RTC (RTC) ------------------------------------------------------*/
/** @addtogroup GT_RTC XT103ZG Base Timer 
  @{
*/
typedef struct
{
    __I  uint32_t DR;                     /*!< Offset: 0x000 Data Register (R/W) */
    __IO uint32_t MR;                     /*!< Offset: 0x004 MatchRegister (R/W) */
    __IO uint32_t LR;                     /*!< Offset: 0x008 Load Register (R/W) */
    __IO uint32_t CR;                     /*!< Offset: 0x00C Control Register (R/W) */
    __IO uint32_t ISCS;                   /*!< Offset: 0x010 Interrupt Control Register (R/W) */
    __I  uint32_t RIS;                    /*!< Offset: 0x014 Raw Interrupt Register (R/W) */
    __I  uint32_t MIS;                    /*!< Offset: 0x018 Masked interrupt Register (R/W) */
    __O  uint32_t ICR;                    /*!< Offset: 0x01C Interrupt Clear Register (R/W) */
} HHD_RTC_TypeDef;
/*@}*/ /* end of group HHD_RTC */


/*------------- Universal Serial BUS (BUS) -----------*/
/** @addtogroup CMSDK_UART CMSDK Universal Serial BUS
  memory mapped structure for CMSDK_USB
  @{
*/
typedef struct
{ 
  __IO   uint32_t  FADDR;         /*!< Offset: 0x000 Function Address Register    (R/W) */
  __IO   uint32_t  POWER;         /*!< Offset: 0x004 Power Management Register  (R/W) */
  __I    uint32_t  INTRIN1;       /*!< Offset: 0x008 Interrupt In0 Register (R/) */
  __I    uint32_t  INTRIN2;       /*!< Offset: 0x00C Interrupt In1 Register (R/) */
  __I    uint32_t  INTROUT1;      /*!< Offset: 0x010 Interrupt Out1 Register (R/) */
  __I    uint32_t  INTROUT2;      /*!< Offset: 0x014 Interrupt Out2 Register (R/) */
  __I    uint32_t  INTRUSB;       /*!< Offset: 0x018 USB Interrupt Register (R/) */
  __IO   uint32_t  INTRIN1E;      /*!< Offset: 0x01C INTRIN1 Interrupt Enable Register (R/W) */
  __IO   uint32_t  INTRIN2E;      /*!< Offset: 0x020 INTRIN2 Interrupt Enable Register (R/W) */
  __IO   uint32_t  INTROUT1E;     /*!< Offset: 0x024 INTROUT1 Interrupt Enable Register (R/W) */
  __IO   uint32_t  INTROUT2E;     /*!< Offset: 0x028 INTROUT1 Interrupt Enable Register (R/W) */
  __IO   uint32_t  INTRUSBE;      /*!< Offset: 0x02C INTRUSB Interrupt Enable Register (R/W) */
  __IO   uint32_t  FRAME1;        /*!< Offset: 0x030 Frame Number bits 0~7 Register (R/W) */
  __IO   uint32_t  FRAME2;        /*!< Offset: 0x034 Frame Number bits 8~10 Register (R/W) */
  __IO   uint32_t  INDEX;         /*!< Offset: 0x038 Index Register (R/W) */
         uint32_t  RESEVRED0;
  __IO   uint32_t  INMAXP;        /*!< Offset: 0x040 Maximum Packet Size Register (R/W) */
  union {
    __IO   uint32_t  CSR0;        /*!< Offset: 0x044 Endpoint0 Control Status Register (R/ ) */
    __IO   uint32_t  INCSR1;      /*!< Offset: 0x044 In Control Status Register1 ( /W) */
    };
  __IO   uint32_t  INCSR2;        /*!< Offset: 0x048 In Control Status Register2 (R/W) */
  __IO   uint32_t  OUTMAXP;       /*!< Offset: 0x04C Maximum Out Packet Size Register (R/W) */
  __IO   uint32_t  OUTCSR1;       /*!< Offset: 0x050 Out Control Status  Register1 (R/W) */
  __IO   uint32_t  OUTCSR2;       /*!< Offset: 0x054 Out Control Status  Register2 (R/W) */
  union {
    __I   uint32_t  COUNT0;       /*!< Offset: 0x058 Endpoint0 Data Number Register (R/W) */
    __I   uint32_t  OUTCOUNT1;    /*!< Offset: 0x058 Data Number Low Register (R/W) */
    };
    __I   uint32_t  OUTCOUNT2;      /*!< Offset: 0x05C data Number High Register (R/W) */
    uint32_t  RESEVRED1[8];
    __IO  uint32_t  FIFO[8];        /*!< Offset: 0x080 FIFO Register (R/W) */
} HHD_USB_TypeDef;


/*------------- CAN BUS (CAN) -----------*/
/** @addtogroup CMSDK_CAN CMSDK Universal Asynchronous Receiver/Transmitter
  memory mapped structure for CMSDK_CAN
  @{
*/
typedef struct
{
    __IO   uint32_t  MOD;          /*!< Offset: 0x000 MOD Register    (R/W) */
    __O    uint32_t  CMR;          /*!< Offset: 0x004 Command Register    (W) */
    __I    uint32_t  SR;           /*!< Offset: 0x008 Status Register     (R) */
    __I    uint32_t  IR;           /*!< Offset: 0x00C Interrupt Register  (R) */
    __IO   uint32_t  IER;          /*!< Offset: 0x010 Interrupt Enable Register    (R/W) */
    uint32_t  RESERVED1;
    __I    uint32_t  BTR0;         /*!< Offset: 0x018 Bus Timing 0 Register    (R) */
    __I    uint32_t  BTR1;         /*!< Offset: 0x01C Bus Timing 1 Register    (R) */
    __I    uint32_t  OCR;          /*!< Offset: 0x020 Output Control Register  (R) */
    uint32_t  RESERVED2[2];
    __I    uint32_t  ALC;          /*!< Offset: 0x02C Arbitration Lost Capture Register    (R) */
    __I    uint32_t  ECC;          /*!< Offset: 0x030 Error Code Capture Register    (R) */
    __I    uint32_t  EWLR;         /*!< Offset: 0x034 Error Warning Register    (R) */
    __I    uint32_t  RXERR;        /*!< Offset: 0x038 Receive Error Counter Register    (R) */
    __I    uint32_t  TXERR;        /*!< Offset: 0x03C Transmit Error Register    (R) */
    __O    uint32_t
    TXBUF[4];     /*!< Offset: 0x040 Transmit Buffer (Frame Information) Register    (W) */
    __I    uint32_t  RXBUF[4];     /*!< Offset: 0x000 Receive Window Register    (R) */
    __I    uint32_t  ACR[4];       /*!< Offset: 0x000 Acceptance Code Register    (R) */
    __I    uint32_t  AMR[4];       /*!< Offset: 0x000 Acceptance Mask Register    (R) */
    __I    uint32_t  RMC;          /*!< Offset: 0x000 Receive Message Count Register    (R) */
    __I    uint32_t  RBSA;         /*!< Offset: 0x000 Receive Buffer Start Address Register    (R) */
    __IO   uint32_t  CDR;          /*!< Offset: 0x000 Clock Divider Register    (R/W) */
    __I    uint32_t  RXFIFO[64];   /*!< Offset: 0x000 Receive FFIO    (R) */
    __I    uint32_t  TB[13];       /*!< Offset: 0x000 Transmit Buffer    (R) */
} HHD_CAN_TypeDef;


/*------------- Universal Asynchronous Receiver Transmitter (UART) -----------*/
/** @addtogroup CMSDK_UART CMSDK Universal Asynchronous Receiver/Transmitter
  memory mapped structure for CMSDK_UART
  @{
*/
typedef struct
{
  __IO   uint32_t  DATA;          /*!< Offset: 0x000 Data Register    (R/W) */
  __IO   uint32_t  STATE;         /*!< Offset: 0x004 Status Register  (R/W) */
  __IO   uint32_t  CTRL;          /*!< Offset: 0x008 Control Register (R/W) */
  union {
    __I    uint32_t  INTSTATUS;   /*!< Offset: 0x00C Interrupt Status Register (R/ ) */
    __O    uint32_t  INTCLEAR;    /*!< Offset: 0x00C Interrupt Clear Register ( /W) */
    };
  __IO   uint32_t  BAUDDIV;       /*!< Offset: 0x010 Baudrate Divider Register (R/W) */

} HHD_UART_TypeDef;

/*--------------------PWM module------------------------------------------------*/
typedef struct
{
  __IO uint32_t CTRL;                   /*!< Offset: 0 control register (R/W) */
  __IO uint32_t FCTRL;                  /*!< Offset: 0x04 Fault control Register (R/W) */
  __IO uint32_t FLTACK;                 /*!< Offset: 0x08 Fault Status/Acknowldge Register (R/W)  */
  __IO uint32_t OUT;                    /*!< Offset: 0x0c Output Control Register (R/W) */
  __IO uint32_t CNTR;                   /*!< Offset: 0x10 Counter Register (R)  */
  __IO uint32_t CMOD;                   /*!< Offset: 0x14 Count Modulo Register (R/W)  */
  __IO uint32_t VAL[6];                 /*!< Offset: 0x18 Value Register 0 (R/W) */
       uint32_t RESERVED1[2];
  __IO uint32_t DTIM0;                  /*!< Offset: 0x38 Deadtime Register 0 (R/W)*/
  __IO uint32_t DTIM1;                  /*!< Offset: 0x3C Deadtime Register 1 (R/W)*/
  __IO uint32_t DMAP0;                  /*!< Offset: 0x40 Disable Mapping Register 0 (R/W) */
  __IO uint32_t DMAP1;                  /*!< Offset: 0x44 Disable Mapping Register 1 (R/W) */
  __IO uint32_t CNFG;                   /*!< Offset: 0x48 Config Register (R/W) */
  __IO uint32_t CCTRL;                  /*!< Offset: 0x4C Channel Control Register (R/W) */
  __IO uint32_t FPORTCTRL;              /*!< Offset:  0x50 Port Register (R/W) */
  __IO uint32_t ICCTRL;                 /*!< Offset: 0x54 Internal Correction Control Register (R/W) */
       uint32_t RESERVED2[2];
  __IO uint32_t INVCTRL;                /*!< Offset: 0x60 Invert output Control Register (R/W) */
  __IO uint32_t CNTRINI;                /*!< Offset: 0x64 Counter Init Register (R/W) */ 
} HHD_PWM_TypeDef;


/*------------- Watchdog Timer (WDT) -----------------------------------------*/
/** @addtogroup GT_WDT XT103ZG WatchDog Timer 
  @{
*/
typedef struct
{
  __IO uint32_t MOD;                    /*!< Offset: 0x000 Watchdog mode register (R/W) */
  __IO uint32_t TC;                     /*!< Offset: 0x004 Watchdog timer constant register (R/W) */
  __O  uint32_t FEED;                   /*!< Offset: 0x008 Watchdog feed sequence register ( /W) */
  __I  uint32_t TV;                     /*!< Offset: 0x00C Watchdog timer value register (R/ ) */
  __IO uint32_t WDCLKSEL;               /*!< Offset: 0x010 Watchdog clock source selectuin register (R/W ) */ 
  __IO uint32_t WARNINT;                /*!< Offset: 0x014 Watchdog Warning Interrupt compare value register (R/W ) */
  __IO uint32_t WINDOW;                 /*!< Offset: 0x018 Watchdog Window compare value register (R/W ) */  
} HHD_WDT_TypeDef;
/*@}*/ /* end of group GT_WDT */

/*------------- power Management Unit (PMU) -----------------------------------------*/
/** @addtogroup GT_WDT XT103ZG WatchDog Timer 
  @{
*/
typedef struct
{
  __IO uint32_t PCON;                    /*!< Offset: 0x000 Power Control Register (R/W) */
       uint32_t reserved[4];
  __IO uint32_t SYSCON;                  /*!< Offset: 0x014 System Config Register (R/W) */
} HHD_PMU_TypeDef;
/*@}*/ /* end of group GT_WDT */


/*------------- Inter-Integrated Circuit (I2C) -------------------------------*/
/** @addtogroup GT_I2C XT103ZG I2C-Bus Interface 
  @{
*/
typedef struct
{
  __IO uint32_t CONSET;                 /*!< Offset: 0x000 I2C Control Set Register (R/W) */
  __I  uint32_t STAT;                   /*!< Offset: 0x004 I2C Status Register (R/ ) */
  __IO uint32_t DAT;                    /*!< Offset: 0x008 I2C Data Register (R/W) */
  __IO uint32_t ADR0;                   /*!< Offset: 0x00C I2C Slave Address Register 0 (R/W) */
  __IO uint32_t SCLH;                   /*!< Offset: 0x010 SCH Duty Cycle Register High Half Word (R/W) */
  __IO uint32_t SCLL;                   /*!< Offset: 0x014 SCL Duty Cycle Register Low Half Word (R/W) */
  __O  uint32_t CONCLR;                 /*!< Offset: 0x018 I2C Control Clear Register ( /W) */
  __IO uint32_t MMCTRL;                 /*!< Offset: 0x01C Monitor mode control register (R/W) */
  __IO uint32_t ADR1;                   /*!< Offset: 0x020 I2C Slave Address Register 1 (R/W) */
  __IO uint32_t ADR2;                   /*!< Offset: 0x024 I2C Slave Address Register 2 (R/W) */
  __IO uint32_t ADR3;                   /*!< Offset: 0x028 I2C Slave Address Register 3 (R/W) */
  __I  uint32_t DATA_BUFFER;            /*!< Offset: 0x02C Data buffer register ( /W) */
  __IO uint32_t MASK0;                  /*!< Offset: 0x030 I2C Slave address mask register 0 (R/W) */
  __IO uint32_t MASK1;                  /*!< Offset: 0x034 I2C Slave address mask register 1 (R/W) */
  __IO uint32_t MASK2;                  /*!< Offset: 0x038 I2C Slave address mask register 2 (R/W) */
  __IO uint32_t MASK3;                  /*!< Offset: 0x03C I2C Slave address mask register 3 (R/W) */
} HHD_I2C_TypeDef;
/*@}*/ /* end of group GT_I2C */
  

/*------------- Serial Peripheral Interface (SPI) -----------------------*/
/** @addtogroup GT_SPI XT103ZG Serial Peripheral Interface 
  @{
*/
typedef struct
{
  __IO uint32_t CR0;                    /*!< Offset: 0x000 Control Register 0 (R/W) */
  __IO uint32_t CR1;                    /*!< Offset: 0x004 Control Register 1 (R/W) */
  __IO uint32_t DR;                     /*!< Offset: 0x008 Data Register (R/W) */
  __I  uint32_t SR;                     /*!< Offset: 0x00C Status Registe (R/ ) */
  __IO uint32_t CPSR;                   /*!< Offset: 0x010 Clock Prescale Register (R/W) */
  __IO uint32_t IMSC;                   /*!< Offset: 0x014 Interrupt Mask Set and Clear Register (R/W) */
  __IO uint32_t RIS;                    /*!< Offset: 0x018 Raw Interrupt Status Register (R/W) */
  __IO uint32_t MIS;                    /*!< Offset: 0x01C Masked Interrupt Status Register (R/W) */
  __IO uint32_t ICR;                    /*!< Offset: 0x020 Interrupt Clear Register (R/W) */
  __IO uint32_t DMACR;                  /*!< Offset: 0x024 DMA Control Register (R/W) */
} HHD_SPI_TypeDef;
/*@}*/ /* end of group GT_SPI */


/*------------- Analog-to-Digital Converter (ADC) ----------------------------*/
/** @addtogroup GT_ADC XT103ZG Analog-to-Digital Converter 
  @{
*/
typedef struct
{
  __IO uint32_t CR;                     /*!< Offset: 0x000       A/D Control Register (R/W) */
  __IO uint32_t GDR;                    /*!< Offset: 0x004       A/D Global Data Register (R/W) */
  __IO uint32_t CHSEL;                  /*!< Offset: 0x008       A/D Channel Select Register (R/W) */
  __IO uint32_t INTEN;                  /*!< Offset: 0x00C       A/D Interrupt Enable Register (R/W) */
  __IO uint32_t DR[4];                  /*!< Offset: 0x010-0x01C A/D Channel 0..7 Data Register (R/W) */
  __IO uint32_t HL0;                    /*!< Offset: 0x020       A/D High Limit data0 Register (R/W) */
  __IO uint32_t HL1;                    /*!< Offset: 0x024       A/D High Limit Data1 Register (R/W) */
  __IO uint32_t LL0;                    /*!< Offset: 0x028       A/D Low Limit Data0 Register (R/W) */
  __IO uint32_t LL1;                    /*!< Offset: 0x02C       A/D Low Limit Data1 Register (R/W) */
  __I  uint32_t INTSTAT;                /*!< Offset: 0x030       A/D Interrupt Status Register (R) */
  __IO uint32_t DIV;                    /*!< Offset: 0x034       A/D Clock Divider Register (R/W) */
  __IO uint32_t PWMFLT;
  __IO uint32_t MUXCR;                  /*!< Offset: 0x038       A/D Channel Mux Control Register (R/W) */
  __IO uint32_t SWTRIG;                 /*!< Offset: 0x034       A/D Software Control Register (R/W) */
} HHD_ADC_TypeDef;


/*@}*/ /* end of group GT_ADC */

/*@}*/ /* end of group GT_ADC */

/*-------------- Digital-to-Analog Converter (DAC) ----------------------------*/
/** @addtogroup GT_DAC XT103ZG Digital-to-Analog Converter
  @{
*/
typedef struct
{
  __IO uint32_t DAC1CTRL;
  __O  uint32_t DAC1BUF;
       uint32_t RESV[2];
  __IO uint32_t DAC2CTRL;
  __O  uint32_t DAC2BUF;
} HHD_DAC_TypeDef;

/*@}*/ /* end of group GT_DAC */

/*------------- CRC Interface ----------------------------*/
/** @addtogroup CRC Engine 
  @{
*/
typedef struct
{
  __IO uint32_t MODE;
  __IO uint32_t SEED;
  union {
  __I  uint32_t SUM;
  __O  uint32_t WR_DATA_DWORD;
  __O  uint16_t WR_DATA_WORD;
       uint16_t RESERVED_WORD;
  __O  uint8_t  WR_DATA_BYTE;
       uint8_t  RESERVED_BYTE[3];
  };
} HHD_CRC_TypeDef;

/**
  * @brief Configure information block (CIB)
  */

typedef struct {                                    /*!< CIB Structure                                                         */
  __I  uint32_t  RESERVED0;
  __I  uint32_t  FUNCDESC;                          /*!< Device function description                                           */
  __I  uint32_t  DID;                               /*!< Device ID                                                             */
  __I  uint32_t  VERID;                             /*!< Hardware version                                                      */
  __I  uint32_t  UNIQUEID0;                         /*!< Unique device serial no- low 32-bit                                   */
  __I  uint32_t  UNIQUEID1;                         /*!< Unique device serial no- high 32-bit                                  */
  __I  uint32_t  IRCTRIM;                           /*!< Internal IRC trim bits                                                */
} HHD_CIB_Type;

typedef struct
{
  __IO uint32_t MACCR;    //00
  __IO uint32_t MACFFR;  //04
  __IO uint32_t MACHTHR;//08
  __IO uint32_t MACHTLR;//0c
  __IO uint32_t MACMIIAR;//10
  __IO uint32_t MACMIIDR;//14
  __IO uint32_t MACFCR;//18
  __IO uint32_t MACVLANTR;//1c             /*    8 */
//       uint32_t RESERVED0[2];
  __IO uint32_t MACVERSION; //20            /*   11 */
  __IO uint32_t MACDEBUG; //24           /*   11 */
  __IO uint32_t MACRWUFFR; //28            /*   11 */
  __IO uint32_t MACPMTCSR;//2c
       uint32_t RESERVED1[2];//30,34
  __IO uint32_t MACSR; //38                /*   15 */
  __IO uint32_t MACIMR;//3C
  __IO uint32_t MACA0HR;
  __IO uint32_t MACA0LR;
  __IO uint32_t MACA1HR;
  __IO uint32_t MACA1LR;
  __IO uint32_t MACA2HR;
  __IO uint32_t MACA2LR;
  __IO uint32_t MACA3HR;
  __IO uint32_t MACA3LR;               /*   24 */
       uint32_t RESERVED2[40];
  __IO uint32_t MMCCR;                 /*   65 */

  __IO uint32_t MMCRIR;
  __IO uint32_t MMCTIR;
  __IO uint32_t MMCRIMR;
  __IO uint32_t MMCTIMR;               /*   69 */
       uint32_t RESERVED3[14];
  __IO uint32_t MMCTGFSCCR;            /*   84 */
  __IO uint32_t MMCTGFMSCCR;
       uint32_t RESERVED4[5];
  __IO uint32_t MMCTGFCR;
      uint32_t RESERVED5[10];
  __IO uint32_t MMCRFCECR;
  __IO uint32_t MMCRFAECR;
       uint32_t RESERVED6[10];
  __IO uint32_t MMCRGUFCR;
       uint32_t RESERVED7[334];
  __IO uint32_t PTPTSCR;
  __IO uint32_t PTPSSIR;
  __IO uint32_t PTPTSHR;
  __IO uint32_t PTPTSLR;
  __IO uint32_t PTPTSHUR;
  __IO uint32_t PTPTSLUR;
  __IO uint32_t PTPTSAR;
  __IO uint32_t PTPTTHR;
  __IO uint32_t PTPTTLR;
       uint32_t RESERVED8[567];
  __IO uint32_t DMABMR;
  __IO uint32_t DMATPDR;
  __IO uint32_t DMARPDR;
  __IO uint32_t DMARDLAR;
  __IO uint32_t DMATDLAR;
  __IO uint32_t DMASR;
  __IO uint32_t DMAOMR;
  __IO uint32_t DMAIER;
  __IO uint32_t DMAMFBOCR;
       uint32_t RESERVED9[9];
  __IO uint32_t DMACHTDR;
  __IO uint32_t DMACHRDR;
  __IO uint32_t DMACHTBAR;
  __IO uint32_t DMACHRBAR;
} HHD_ETH_TypeDef;

#define  GMACCONFIG            MACCR              /* Mac config Register                       */       
#define  GMACFRAMEFILTER       MACFFR             /* Mac frame filtering controls              */
#define  GMACHASHHIGH          MACHTHR            /* Multi-cast hash table high                */
#define  GMACHASHLOW           MACHTLR            /* Multi-cast hash table low                 */
#define  GMACGMIIADDR          MACMIIAR           /* GMII address Register(ext. Phy)           */
#define  GMACGMIIDATA          MACMIIDR           /* GMII data Register(ext. Phy)              */
#define  GMACFLOWCONTROL       MACFCR             /* Flow control Register                     */
#define  GMACVLAN              MACVLANTR          /* VLAN tag Register (IEEE 802.1Q)           */
#define  GMACVERSION           MACVERSION         /* Gmac core version                         */
#define  GMACDEBUG             MACDEBUG           /* debug                                     */
#define  GMACWAKEUPADDR        MACRWUFFR          /* GMAC wake-up frame filter adrress reg     */ 
#define  GMACPTMCTRLSTATUS     MACPMTCSR          /* PMT control and status register           */ 
#define  GMACLPICTRLSTS        MACLPICSR          /* LPI (low power idle) Control and Status Register          */
#define  GMACLPITIMECTRL       MACLPITCR          /* LPI timer control register               */
#define  GMACINTERRUPTSTATUS   MACSR              /* Mac Interrupt ststus register             */      /*   15 */
#define  GMACINTERRUPTMASK     MACIMR             /* Mac Interrupt Mask register               */
#define  GMACADDR0HIGH         MACA0HR            /* Mac address0 high Register                */
#define  GMACADDR0LOW          MACA0LR            /* Mac address0 low Register                */
#define  GMACADDR1HIGH         MACA1HR    
#define  GMACADDR1LOW          MACA1LR    
#define  GMACADDR2HIGH         MACA2HR          
#define  GMACADDR2LOW          MACA2LR    
#define  GMACADDR3HIGH         MACA3HR    
#define  GMACADDR3LOW          MACA3LR              /*   24 */

#define    MMCCTRL             MMCCR        /*MMC Control establishes the operating mode of MMC  */ /*   65 */
#define    MMCINTRRX           MMCRIR       /*MMC Receive Interrupt maintains the interrupt generated from all of the receive statistic counters*/
#define    MMCINTRTX           MMCTIR       /*MMC Transmit Interrupt maintains the interrupt generated from all of the transmit statistic counters*/
#define    MMCINTRMASKRX       MMCRIMR      /*MMC Receive Interrupt mask */
#define    MMCINTRMASKTX       MMCTIMR      /*MMC Transmit Interrupt Mask*/        /*   69 */

#define    MMCTXSINGLECOL_G      MMCTGFSCCR              /*   84 */
#define    MMCTXMULTCOL_G        MMCTGFMSCCR  
#define    MMCTXFRAMECOUNT_G     MMCTGFCR    
#define    MMCRXCRCERROR         MMCRFCECR 
#define    MMCRXALIGNMENTERROR   MMCRFAECR
#define    MMCRXUNICASTFRAMES_G  MMCRGUFCR 

#define    GMACTSCTRL        PTPTSCR       /* Controls the Timestamp update logic */
#define    GMACTSSUBSECINCR  PTPSSIR       /* Controls the Timestamp update logic */
#define    GMACTSHIGH        PTPTSHR       /* Controls the Timestamp update logic */
#define    GMACTSLOW         PTPTSLR       /* 32 bit nano seconds(MS)    */
#define    GMACTSHIGHUPDATE  PTPTSHUR      /* 32 bit seconds(MS) to be written/added/subtracted        */
#define    GMACTSLOWUPDATE   PTPTSLUR      /* 32 bit nano seconds(MS) to be writeen/added/subtracted   */
#define    GMACTSADDEND      PTPTSAR       /* Used by Software to readjust the clock frequency linearly  */
#define    GMACTSTARGETTIMEHIGH   PTPTTHR  /* 32 bit seconds(MS) to be compared with system time  */
#define    GMACTSTARGETTIMELOW    PTPTTLR  /* 32 bit nano seconds(MS) to be compared with system time */

#define    DMABUSMOD         DMABMR     /* CSR0 - Bus Mode Register                          */
#define    DMATXPOLLCOMMAND  DMATPDR    /* CSR1 - Transmit Poll Demand Register              */
#define    DMARXPOLLCOMMAND  DMARPDR    /* CSR2 - Receive Poll Demand Register               */
#define    DMARXBASEADDR     DMARDLAR   /* CSR3 - Receive Descriptor list base address       */
#define    DMATXBASEADDR     DMATDLAR   /* CSR4 - Transmit Descriptor list base address      */
#define    DMASTATUS         DMASR      /* CSR5 - Dma status Register                        */
#define    DMACONTROL        DMAOMR     /* CSR6 - Dma Operation Mode Register                */  
#define    DMAINTERRUPT      DMAIER     /* CSR7 - Interrupt enable                           */  
#define    DMAMISSEDFR      DMAMFBOCR   /* CSR8 - Missed Frame & Buffer overflow Counter     */  

#define    DMATXCURRDESC     DMACHTDR   /*      - Current host Tx Desc Register              */   
#define    DMARXCURRDESC     DMACHRDR   /*      - Current host Rx Desc Register              */ 
#define    DMATXCURRADDR     DMACHTBAR  /* CSR20 - Current host transmit buffer address      */
#define    DMARXCURRADDR     DMACHRBAR  /* CSR21 - Current host receive buffer address       */



/*@}*/ /* end of group GT_FMC */


#if defined ( __CC_ARM   )
#pragma no_anon_unions
#endif

/******************************************************************************/
/*                         Peripheral memory map                              */
/******************************************************************************/
/* Base addresses                                                             */
#define HHD_FLASH_BASE        (0x00000000UL)
#define HHD_RAM_BASE          (0x20000000UL)
#define HHD_APB1_BASE         (0x40000000UL)
#define HHD_APB2_BASE         (0x40010000UL)
#define HHD_AHB_BASE          (0x40020000UL)
#define HHD_CIB_BASE          (0x1FFF1400UL)

/* APB0 peripherals                                                           */
#define HHD_TIM2_BASE         (HHD_APB1_BASE + 0x0000)
#define HHD_TIM3_BASE         (HHD_APB1_BASE + 0x0400)
#define HHD_TIM4_BASE         (HHD_APB1_BASE + 0x0800)
#define HHD_TIM5_BASE         (HHD_APB1_BASE + 0x0c00)
#define HHD_TIM6_BASE         (HHD_APB1_BASE + 0x1000)
#define HHD_TIM7_BASE         (HHD_APB1_BASE + 0x1400)
#define HHD_RTC_BASE          (HHD_APB1_BASE + 0x2800)
#define HHD_WWDT_BASE         (HHD_APB1_BASE + 0x2c00)
#define HHD_IWDT_BASE         (HHD_APB1_BASE + 0x3000)
#define HHD_SPI2_BASE         (HHD_APB1_BASE + 0x3800)
#define HHD_SPI3_BASE         (HHD_APB1_BASE + 0x3c00)
#define HHD_UART2_BASE        (HHD_APB1_BASE + 0x4400)
#define HHD_UART3_BASE        (HHD_APB1_BASE + 0x4800)
#define HHD_UART4_BASE        (HHD_APB1_BASE + 0x4c00)
#define HHD_UART5_BASE        (HHD_APB1_BASE + 0x5000)
#define HHD_I2C1_BASE         (HHD_APB1_BASE + 0x5400)
#define HHD_I2C2_BASE         (HHD_APB1_BASE + 0x5800)
#define HHD_CAN1_BASE         (HHD_APB1_BASE + 0x6400)
#define HHD_CAN2_BASE         (HHD_APB1_BASE + 0x6800)
#define HHD_BKP_BASE          (HHD_APB1_BASE + 0x6c00)
#define HHD_PWR_BASE          (HHD_APB1_BASE + 0x7000)
#define HHD_DAC_BASE          (HHD_APB1_BASE + 0x7400)

#define HHD_AFIO_BASE         (HHD_APB2_BASE + 0x0000)
#define HHD_EXTI_BASE         (HHD_APB2_BASE + 0x0400)
#define HHD_GPIOA_BASE        (HHD_APB2_BASE + 0x0800)
#define HHD_GPIOB_BASE        (HHD_APB2_BASE + 0x0C00)
#define HHD_GPIOC_BASE        (HHD_APB2_BASE + 0x1000)
#define HHD_GPIOD_BASE        (HHD_APB2_BASE + 0x1400)
#define HHD_GPIOE_BASE        (HHD_APB2_BASE + 0x1800)
#define HHD_GPIOF_BASE        (HHD_APB2_BASE + 0x1C00)
#define HHD_GPIOG_BASE        (HHD_APB2_BASE + 0x2000)

#define HHD_ADC1_BASE         (HHD_APB2_BASE + 0x2400)
#define HHD_ADC2_BASE         (HHD_APB2_BASE + 0x2800)
#define HHD_TIM1_BASE         (HHD_APB2_BASE + 0x2c00)
#define HHD_SPI1_BASE         (HHD_APB2_BASE + 0x3000)
#define HHD_UART1_BASE        (HHD_APB2_BASE + 0x3800)
#define HHD_SPI4_BASE		 (HHD_APB2_BASE + 0x8800)
#define HHD_SPI5_BASE		 (HHD_APB2_BASE + 0x8C00)

#define HHD_DMA1_BASE         (HHD_AHB_BASE  + 0x0000)
#define HHD_SYSCON_BASE       (HHD_AHB_BASE  + 0x1000)
#define HHD_FMC_BASE          (HHD_AHB_BASE  + 0x2000)
#define HHD_CRC_BASE          (HHD_AHB_BASE  + 0x3000)

#define HHD_ETH_BASE          (HHD_AHB_BASE  + 0x8000)

/******************************************************************************/
/*                         Peripheral declaration                             */
/******************************************************************************/
#define HHD_CIB               ((HHD_CIB_Type       *) HHD_CIB_BASE)
#define HHD_WWDT              ((HHD_WDT_TypeDef    *) HHD_WWDT_BASE)
#define HHD_IWDT              ((HHD_WDT_TypeDef    *) HHD_IWDT_BASE)
#define HHD_UART1             ((HHD_UART_TypeDef   *) HHD_UART1_BASE)
#define HHD_UART2             ((HHD_UART_TypeDef   *) HHD_UART2_BASE)
#define HHD_UART3             ((HHD_UART_TypeDef   *) HHD_UART3_BASE)
#define HHD_UART4             ((HHD_UART_TypeDef   *) HHD_UART4_BASE)
#define HHD_UART5             ((HHD_UART_TypeDef   *) HHD_UART5_BASE)
#define HHD_TIM6              ((HHD_BASETMR_TypeDef *) HHD_TIM6_BASE)
#define HHD_TIM7              ((HHD_BASETMR_TypeDef *) HHD_TIM7_BASE)
#define HHD_TIM2              ((HHD_TMR_TypeDef    *) HHD_TIM2_BASE)
#define HHD_TIM3              ((HHD_TMR_TypeDef    *) HHD_TIM3_BASE)
#define HHD_TIM4              ((HHD_TMR_TypeDef    *) HHD_TIM4_BASE)
#define HHD_TIM5              ((HHD_TMR_TypeDef    *) HHD_TIM4_BASE)
#define HHD_RTC							 ((HHD_RTC_TypeDef    *) HHD_RTC_BASE)
#define HHD_ADC1              ((HHD_ADC_TypeDef    *) HHD_ADC1_BASE)
#define HHD_ADC2              ((HHD_ADC_TypeDef    *) HHD_ADC2_BASE)
#define HHD_ADC3              ((HHD_ADC_TypeDef    *) HHD_ADC3_BASE)
#define HHD_DAC               ((HHD_DAC_TypeDef    *) HHD_DAC_BASE)
#define HHD_I2C1              ((HHD_I2C_TypeDef    *) HHD_I2C1_BASE)
#define HHD_I2C2              ((HHD_I2C_TypeDef    *) HHD_I2C2_BASE)
#define HHD_CAN1              ((HHD_CAN_TypeDef    *) HHD_CAN1_BASE )
#define HHD_CAN2              ((HHD_CAN_TypeDef    *) HHD_CAN2_BASE )
#define HHD_AFIO              ((HHD_AFIO_TypeDef   *) HHD_AFIO_BASE )
#define HHD_SYSCON            ((HHD_SYSCON_TypeDef *) HHD_SYSCON_BASE)
#define HHD_TIM1              ((HHD_PWM_TypeDef    *) HHD_TIM1_BASE)
#define HHD_FMC               ((HHD_FMC_TypeDef    *) HHD_FMC_BASE)
#define HHD_CRC               ((HHD_CRC_TypeDef    *) HHD_CRC_BASE)
#define HHD_GPIOA             ((HHD_GPIO_TypeDef   *) HHD_GPIOA_BASE )
#define HHD_GPIOB             ((HHD_GPIO_TypeDef   *) HHD_GPIOB_BASE )
#define HHD_GPIOC             ((HHD_GPIO_TypeDef   *) HHD_GPIOC_BASE )
#define HHD_GPIOD             ((HHD_GPIO_TypeDef   *) HHD_GPIOD_BASE )
#define HHD_GPIOE             ((HHD_GPIO_TypeDef   *) HHD_GPIOE_BASE )
#define HHD_DMA1              ((HHD_DMA_TypeDef    *) HHD_DMA1_BASE )
#define HHD_PMU               ((HHD_PMU_TypeDef    *) HHD_PWR_BASE )
#define HHD_SPI1              ((HHD_SPI_TypeDef    *) HHD_SPI1_BASE )
#define HHD_SPI2              ((HHD_SPI_TypeDef    *) HHD_SPI2_BASE )
#define HHD_SPI3              ((HHD_SPI_TypeDef    *) HHD_SPI3_BASE )
#define HHD_ETH               ((HHD_ETH_TypeDef    *) HHD_ETH_BASE)

#ifdef __cplusplus
}
#endif

/******************************************************************************/
/*                Ethernet MAC Registers bits definitions                     */
/******************************************************************************/
/* Bit definition for Ethernet MAC Control Register register */
#define ETH_MACCR_WD      ((uint32_t)0x00800000)  /* Watchdog disable */
#define ETH_MACCR_JD      ((uint32_t)0x00400000)  /* Jabber disable */
#define ETH_MACCR_IFG     ((uint32_t)0x000E0000)  /* Inter-frame gap */
  #define ETH_MACCR_IFG_96Bit     ((uint32_t)0x00000000)  /* Minimum IFG between frames during transmission is 96Bit */
  #define ETH_MACCR_IFG_88Bit     ((uint32_t)0x00020000)  /* Minimum IFG between frames during transmission is 88Bit */
  #define ETH_MACCR_IFG_80Bit     ((uint32_t)0x00040000)  /* Minimum IFG between frames during transmission is 80Bit */
  #define ETH_MACCR_IFG_72Bit     ((uint32_t)0x00060000)  /* Minimum IFG between frames during transmission is 72Bit */
  #define ETH_MACCR_IFG_64Bit     ((uint32_t)0x00080000)  /* Minimum IFG between frames during transmission is 64Bit */        
  #define ETH_MACCR_IFG_56Bit     ((uint32_t)0x000A0000)  /* Minimum IFG between frames during transmission is 56Bit */
  #define ETH_MACCR_IFG_48Bit     ((uint32_t)0x000C0000)  /* Minimum IFG between frames during transmission is 48Bit */
  #define ETH_MACCR_IFG_40Bit     ((uint32_t)0x000E0000)  /* Minimum IFG between frames during transmission is 40Bit */              
#define ETH_MACCR_CSD     ((uint32_t)0x00010000)  /* Carrier sense disable (during transmission) */
#define ETH_MACCR_FES     ((uint32_t)0x00004000)  /* Fast ethernet speed */
#define ETH_MACCR_ROD     ((uint32_t)0x00002000)  /* Receive own disable */
#define ETH_MACCR_LM      ((uint32_t)0x00001000)  /* loopback mode */
#define ETH_MACCR_DM      ((uint32_t)0x00000800)  /* Duplex mode */
#define ETH_MACCR_IPCO    ((uint32_t)0x00000400)  /* IP Checksum offload */
#define ETH_MACCR_RD      ((uint32_t)0x00000200)  /* Retry disable */
#define ETH_MACCR_APCS    ((uint32_t)0x00000080)  /* Automatic Pad/CRC stripping */
#define ETH_MACCR_BL      ((uint32_t)0x00000060)  /* Back-off limit: random integer number (r) of slot time delays before rescheduling
                                                       a transmission attempt during retries after a collision: 0 =< r <2^k */
  #define ETH_MACCR_BL_10    ((uint32_t)0x00000000)  /* k = min (n, 10) */
  #define ETH_MACCR_BL_8     ((uint32_t)0x00000020)  /* k = min (n, 8) */
  #define ETH_MACCR_BL_4     ((uint32_t)0x00000040)  /* k = min (n, 4) */
  #define ETH_MACCR_BL_1     ((uint32_t)0x00000060)  /* k = min (n, 1) */ 
#define ETH_MACCR_DC      ((uint32_t)0x00000010)  /* Defferal check */
#define ETH_MACCR_TE      ((uint32_t)0x00000008)  /* Transmitter enable */
#define ETH_MACCR_RE      ((uint32_t)0x00000004)  /* Receiver enable */

/* Bit definition for Ethernet MAC Frame Filter Register */
#define ETH_MACFFR_RA     ((uint32_t)0x80000000)  /* Receive all */ 
#define ETH_MACFFR_HPF    ((uint32_t)0x00000400)  /* Hash or perfect filter */ 
#define ETH_MACFFR_SAF    ((uint32_t)0x00000200)  /* Source address filter enable */ 
#define ETH_MACFFR_SAIF   ((uint32_t)0x00000100)  /* SA inverse filtering */ 
#define ETH_MACFFR_PCF    ((uint32_t)0x000000C0)  /* Pass control frames: 3 cases */
  #define ETH_MACFFR_PCF_BlockAll                ((uint32_t)0x00000040)  /* MAC filters all control frames from reaching the application */
  #define ETH_MACFFR_PCF_ForwardAll              ((uint32_t)0x00000080)  /* MAC forwards all control frames to application even if they fail the Address Filter */
  #define ETH_MACFFR_PCF_ForwardPassedAddrFilter ((uint32_t)0x000000C0)  /* MAC forwards control frames that pass the Address Filter. */ 
#define ETH_MACFFR_BFD    ((uint32_t)0x00000020)  /* Broadcast frame disable */ 
#define ETH_MACFFR_PAM 	  ((uint32_t)0x00000010)  /* Pass all mutlicast */ 
#define ETH_MACFFR_DAIF   ((uint32_t)0x00000008)  /* DA Inverse filtering */ 
#define ETH_MACFFR_HM     ((uint32_t)0x00000004)  /* Hash multicast */ 
#define ETH_MACFFR_HU     ((uint32_t)0x00000002)  /* Hash unicast */
#define ETH_MACFFR_PM     ((uint32_t)0x00000001)  /* Promiscuous mode */

/* Bit definition for Ethernet MAC Hash Table High Register */
#define ETH_MACHTHR_HTH   ((uint32_t)0xFFFFFFFF)  /* Hash table high */

/* Bit definition for Ethernet MAC Hash Table Low Register */
#define ETH_MACHTLR_HTL   ((uint32_t)0xFFFFFFFF)  /* Hash table low */

/* Bit definition for Ethernet MAC MII Address Register */
#define ETH_MACMIIAR_PA   ((uint32_t)0x0000F800)  /* Physical layer address */ 
#define ETH_MACMIIAR_MR   ((uint32_t)0x000007C0)  /* MII register in the selected PHY */ 
#define ETH_MACMIIAR_CR   ((uint32_t)0x0000001C)  /* CR clock range: 6 cases */ 
  #define ETH_MACMIIAR_CR_Div42   ((uint32_t)0x00000000)  /* HCLK:60-72 MHz; MDC clock= HCLK/42 */
  #define ETH_MACMIIAR_CR_Div16   ((uint32_t)0x00000008)  /* HCLK:20-35 MHz; MDC clock= HCLK/16 */
  #define ETH_MACMIIAR_CR_Div26   ((uint32_t)0x0000000C)  /* HCLK:35-60 MHz; MDC clock= HCLK/26 */
#define ETH_MACMIIAR_MW   ((uint32_t)0x00000002)  /* MII write */ 
#define ETH_MACMIIAR_MB   ((uint32_t)0x00000001)  /* MII busy */ 
  
/* Bit definition for Ethernet MAC MII Data Register */
#define ETH_MACMIIDR_MD   ((uint32_t)0x0000FFFF)  /* MII data: read/write data from/to PHY */

/* Bit definition for Ethernet MAC Flow Control Register */
#define ETH_MACFCR_PT     ((uint32_t)0xFFFF0000)  /* Pause time */
#define ETH_MACFCR_ZQPD   ((uint32_t)0x00000080)  /* Zero-quanta pause disable */
#define ETH_MACFCR_PLT    ((uint32_t)0x00000030)  /* Pause low threshold: 4 cases */
  #define ETH_MACFCR_PLT_Minus4   ((uint32_t)0x00000000)  /* Pause time minus 4 slot times */
  #define ETH_MACFCR_PLT_Minus28  ((uint32_t)0x00000010)  /* Pause time minus 28 slot times */
  #define ETH_MACFCR_PLT_Minus144 ((uint32_t)0x00000020)  /* Pause time minus 144 slot times */
  #define ETH_MACFCR_PLT_Minus256 ((uint32_t)0x00000030)  /* Pause time minus 256 slot times */      
#define ETH_MACFCR_UPFD   ((uint32_t)0x00000008)  /* Unicast pause frame detect */
#define ETH_MACFCR_RFCE   ((uint32_t)0x00000004)  /* Receive flow control enable */
#define ETH_MACFCR_TFCE   ((uint32_t)0x00000002)  /* Transmit flow control enable */
#define ETH_MACFCR_FCBBPA ((uint32_t)0x00000001)  /* Flow control busy/backpressure activate */

/* Bit definition for Ethernet MAC VLAN Tag Register */
#define ETH_MACVLANTR_VLANTC ((uint32_t)0x00010000)  /* 12-bit VLAN tag comparison */
#define ETH_MACVLANTR_VLANTI ((uint32_t)0x0000FFFF)  /* VLAN tag identifier (for receive frames) */

/* Bit definition for Ethernet MAC Remote Wake-UpFrame Filter Register */ 
#define ETH_MACRWUFFR_D   ((uint32_t)0xFFFFFFFF)  /* Wake-up frame filter register data */
/* Eight sequential Writes to this address (offset 0x28) will write all Wake-UpFrame Filter Registers.
   Eight sequential Reads from this address (offset 0x28) will read all Wake-UpFrame Filter Registers. */
/* Wake-UpFrame Filter Reg0 : Filter 0 Byte Mask
   Wake-UpFrame Filter Reg1 : Filter 1 Byte Mask
   Wake-UpFrame Filter Reg2 : Filter 2 Byte Mask
   Wake-UpFrame Filter Reg3 : Filter 3 Byte Mask
   Wake-UpFrame Filter Reg4 : RSVD - Filter3 Command - RSVD - Filter2 Command - 
                              RSVD - Filter1 Command - RSVD - Filter0 Command
   Wake-UpFrame Filter Re5 : Filter3 Offset - Filter2 Offset - Filter1 Offset - Filter0 Offset
   Wake-UpFrame Filter Re6 : Filter1 CRC16 - Filter0 CRC16
   Wake-UpFrame Filter Re7 : Filter3 CRC16 - Filter2 CRC16 */

/* Bit definition for Ethernet MAC PMT Control and Status Register */ 
#define ETH_MACPMTCSR_WFFRPR ((uint32_t)0x80000000)  /* Wake-Up Frame Filter Register Pointer Reset */
#define ETH_MACPMTCSR_GU     ((uint32_t)0x00000200)  /* Global Unicast */
#define ETH_MACPMTCSR_WFR    ((uint32_t)0x00000040)  /* Wake-Up Frame Received */
#define ETH_MACPMTCSR_MPR    ((uint32_t)0x00000020)  /* Magic Packet Received */
#define ETH_MACPMTCSR_WFE    ((uint32_t)0x00000004)  /* Wake-Up Frame Enable */
#define ETH_MACPMTCSR_MPE    ((uint32_t)0x00000002)  /* Magic Packet Enable */
#define ETH_MACPMTCSR_PD     ((uint32_t)0x00000001)  /* Power Down */

/* Bit definition for Ethernet MAC Status Register */
#define ETH_MACSR_TSTS      ((uint32_t)0x00000200)  /* Time stamp trigger status */
#define ETH_MACSR_MMCTS     ((uint32_t)0x00000040)  /* MMC transmit status */
#define ETH_MACSR_MMMCRS    ((uint32_t)0x00000020)  /* MMC receive status */
#define ETH_MACSR_MMCS      ((uint32_t)0x00000010)  /* MMC status */
#define ETH_MACSR_PMTS      ((uint32_t)0x00000008)  /* PMT status */

/* Bit definition for Ethernet MAC Interrupt Mask Register */
#define ETH_MACIMR_TSTIM     ((uint32_t)0x00000200)  /* Time stamp trigger interrupt mask */
#define ETH_MACIMR_PMTIM     ((uint32_t)0x00000008)  /* PMT interrupt mask */

/* Bit definition for Ethernet MAC Address0 High Register */
#define ETH_MACA0HR_MACA0H   ((uint32_t)0x0000FFFF)  /* MAC address0 high */

/* Bit definition for Ethernet MAC Address0 Low Register */
#define ETH_MACA0LR_MACA0L   ((uint32_t)0xFFFFFFFF)  /* MAC address0 low */

/* Bit definition for Ethernet MAC Address1 High Register */
#define ETH_MACA1HR_AE       ((uint32_t)0x80000000)  /* Address enable */
#define ETH_MACA1HR_SA       ((uint32_t)0x40000000)  /* Source address */
#define ETH_MACA1HR_MBC      ((uint32_t)0x3F000000)  /* Mask byte control: bits to mask for comparison of the MAC Address bytes */
  #define ETH_MACA1HR_MBC_HBits15_8    ((uint32_t)0x20000000)  /* Mask MAC Address high reg bits [15:8] */
  #define ETH_MACA1HR_MBC_HBits7_0     ((uint32_t)0x10000000)  /* Mask MAC Address high reg bits [7:0] */
  #define ETH_MACA1HR_MBC_LBits31_24   ((uint32_t)0x08000000)  /* Mask MAC Address low reg bits [31:24] */
  #define ETH_MACA1HR_MBC_LBits23_16   ((uint32_t)0x04000000)  /* Mask MAC Address low reg bits [23:16] */
  #define ETH_MACA1HR_MBC_LBits15_8    ((uint32_t)0x02000000)  /* Mask MAC Address low reg bits [15:8] */
  #define ETH_MACA1HR_MBC_LBits7_0     ((uint32_t)0x01000000)  /* Mask MAC Address low reg bits [7:0] */ 
#define ETH_MACA1HR_MACA1H   ((uint32_t)0x0000FFFF)  /* MAC address1 high */

/* Bit definition for Ethernet MAC Address1 Low Register */
#define ETH_MACA1LR_MACA1L   ((uint32_t)0xFFFFFFFF)  /* MAC address1 low */

/* Bit definition for Ethernet MAC Address2 High Register */
#define ETH_MACA2HR_AE       ((uint32_t)0x80000000)  /* Address enable */
#define ETH_MACA2HR_SA       ((uint32_t)0x40000000)  /* Source address */
#define ETH_MACA2HR_MBC      ((uint32_t)0x3F000000)  /* Mask byte control */
  #define ETH_MACA2HR_MBC_HBits15_8    ((uint32_t)0x20000000)  /* Mask MAC Address high reg bits [15:8] */
  #define ETH_MACA2HR_MBC_HBits7_0     ((uint32_t)0x10000000)  /* Mask MAC Address high reg bits [7:0] */
  #define ETH_MACA2HR_MBC_LBits31_24   ((uint32_t)0x08000000)  /* Mask MAC Address low reg bits [31:24] */
  #define ETH_MACA2HR_MBC_LBits23_16   ((uint32_t)0x04000000)  /* Mask MAC Address low reg bits [23:16] */
  #define ETH_MACA2HR_MBC_LBits15_8    ((uint32_t)0x02000000)  /* Mask MAC Address low reg bits [15:8] */
  #define ETH_MACA2HR_MBC_LBits7_0     ((uint32_t)0x01000000)  /* Mask MAC Address low reg bits [70] */
#define ETH_MACA2HR_MACA2H   ((uint32_t)0x0000FFFF)  /* MAC address1 high */

/* Bit definition for Ethernet MAC Address2 Low Register */
#define ETH_MACA2LR_MACA2L   ((uint32_t)0xFFFFFFFF)  /* MAC address2 low */

/* Bit definition for Ethernet MAC Address3 High Register */
#define ETH_MACA3HR_AE       ((uint32_t)0x80000000)  /* Address enable */
#define ETH_MACA3HR_SA       ((uint32_t)0x40000000)  /* Source address */
#define ETH_MACA3HR_MBC      ((uint32_t)0x3F000000)  /* Mask byte control */
  #define ETH_MACA3HR_MBC_HBits15_8    ((uint32_t)0x20000000)  /* Mask MAC Address high reg bits [15:8] */
  #define ETH_MACA3HR_MBC_HBits7_0     ((uint32_t)0x10000000)  /* Mask MAC Address high reg bits [7:0] */
  #define ETH_MACA3HR_MBC_LBits31_24   ((uint32_t)0x08000000)  /* Mask MAC Address low reg bits [31:24] */
  #define ETH_MACA3HR_MBC_LBits23_16   ((uint32_t)0x04000000)  /* Mask MAC Address low reg bits [23:16] */
  #define ETH_MACA3HR_MBC_LBits15_8    ((uint32_t)0x02000000)  /* Mask MAC Address low reg bits [15:8] */
  #define ETH_MACA3HR_MBC_LBits7_0     ((uint32_t)0x01000000)  /* Mask MAC Address low reg bits [70] */
#define ETH_MACA3HR_MACA3H   ((uint32_t)0x0000FFFF)  /* MAC address3 high */

/* Bit definition for Ethernet MAC Address3 Low Register */
#define ETH_MACA3LR_MACA3L   ((uint32_t)0xFFFFFFFF)  /* MAC address3 low */

/******************************************************************************/
/*                Ethernet MMC Registers bits definition                      */
/******************************************************************************/

/* Bit definition for Ethernet MMC Contol Register */
#define ETH_MMCCR_MCF        ((uint32_t)0x00000008)  /* MMC Counter Freeze */
#define ETH_MMCCR_ROR        ((uint32_t)0x00000004)  /* Reset on Read */
#define ETH_MMCCR_CSR        ((uint32_t)0x00000002)  /* Counter Stop Rollover */
#define ETH_MMCCR_CR         ((uint32_t)0x00000001)  /* Counters Reset */

/* Bit definition for Ethernet MMC Receive Interrupt Register */
#define ETH_MMCRIR_RGUFS     ((uint32_t)0x00020000)  /* Set when Rx good unicast frames counter reaches half the maximum value */
#define ETH_MMCRIR_RFAES     ((uint32_t)0x00000040)  /* Set when Rx alignment error counter reaches half the maximum value */
#define ETH_MMCRIR_RFCES     ((uint32_t)0x00000020)  /* Set when Rx crc error counter reaches half the maximum value */

/* Bit definition for Ethernet MMC Transmit Interrupt Register */
#define ETH_MMCTIR_TGFS      ((uint32_t)0x00200000)  /* Set when Tx good frame count counter reaches half the maximum value */
#define ETH_MMCTIR_TGFMSCS   ((uint32_t)0x00008000)  /* Set when Tx good multi col counter reaches half the maximum value */
#define ETH_MMCTIR_TGFSCS    ((uint32_t)0x00004000)  /* Set when Tx good single col counter reaches half the maximum value */

/* Bit definition for Ethernet MMC Receive Interrupt Mask Register */
#define ETH_MMCRIMR_RGUFM    ((uint32_t)0x00020000)  /* Mask the interrupt when Rx good unicast frames counter reaches half the maximum value */
#define ETH_MMCRIMR_RFAEM    ((uint32_t)0x00000040)  /* Mask the interrupt when when Rx alignment error counter reaches half the maximum value */
#define ETH_MMCRIMR_RFCEM    ((uint32_t)0x00000020)  /* Mask the interrupt when Rx crc error counter reaches half the maximum value */

/* Bit definition for Ethernet MMC Transmit Interrupt Mask Register */
#define ETH_MMCTIMR_TGFM     ((uint32_t)0x00200000)  /* Mask the interrupt when Tx good frame count counter reaches half the maximum value */
#define ETH_MMCTIMR_TGFMSCM  ((uint32_t)0x00008000)  /* Mask the interrupt when Tx good multi col counter reaches half the maximum value */
#define ETH_MMCTIMR_TGFSCM   ((uint32_t)0x00004000)  /* Mask the interrupt when Tx good single col counter reaches half the maximum value */

/* Bit definition for Ethernet MMC Transmitted Good Frames after Single Collision Counter Register */
#define ETH_MMCTGFSCCR_TGFSCC     ((uint32_t)0xFFFFFFFF)  /* Number of successfully transmitted frames after a single collision in Half-duplex mode. */

/* Bit definition for Ethernet MMC Transmitted Good Frames after More than a Single Collision Counter Register */
#define ETH_MMCTGFMSCCR_TGFMSCC   ((uint32_t)0xFFFFFFFF)  /* Number of successfully transmitted frames after more than a single collision in Half-duplex mode. */

/* Bit definition for Ethernet MMC Transmitted Good Frames Counter Register */
#define ETH_MMCTGFCR_TGFC    ((uint32_t)0xFFFFFFFF)  /* Number of good frames transmitted. */

/* Bit definition for Ethernet MMC Received Frames with CRC Error Counter Register */
#define ETH_MMCRFCECR_RFCEC  ((uint32_t)0xFFFFFFFF)  /* Number of frames received with CRC error. */

/* Bit definition for Ethernet MMC Received Frames with Alignement Error Counter Register */
#define ETH_MMCRFAECR_RFAEC  ((uint32_t)0xFFFFFFFF)  /* Number of frames received with alignment (dribble) error */

/* Bit definition for Ethernet MMC Received Good Unicast Frames Counter Register */
#define ETH_MMCRGUFCR_RGUFC  ((uint32_t)0xFFFFFFFF)  /* Number of good unicast frames received. */

/******************************************************************************/
/*               Ethernet PTP Registers bits definition                       */
/******************************************************************************/

/* Bit definition for Ethernet PTP Time Stamp Contol Register */
#define ETH_PTPTSCR_TSARU    ((uint32_t)0x00000020)  /* Addend register update */
#define ETH_PTPTSCR_TSITE    ((uint32_t)0x00000010)  /* Time stamp interrupt trigger enable */
#define ETH_PTPTSCR_TSSTU    ((uint32_t)0x00000008)  /* Time stamp update */
#define ETH_PTPTSCR_TSSTI    ((uint32_t)0x00000004)  /* Time stamp initialize */
#define ETH_PTPTSCR_TSFCU    ((uint32_t)0x00000002)  /* Time stamp fine or coarse update */
#define ETH_PTPTSCR_TSE      ((uint32_t)0x00000001)  /* Time stamp enable */

/* Bit definition for Ethernet PTP Sub-Second Increment Register */
#define ETH_PTPSSIR_STSSI    ((uint32_t)0x000000FF)  /* System time Sub-second increment value */

/* Bit definition for Ethernet PTP Time Stamp High Register */
#define ETH_PTPTSHR_STS      ((uint32_t)0xFFFFFFFF)  /* System Time second */

/* Bit definition for Ethernet PTP Time Stamp Low Register */
#define ETH_PTPTSLR_STPNS    ((uint32_t)0x80000000)  /* System Time Positive or negative time */
#define ETH_PTPTSLR_STSS     ((uint32_t)0x7FFFFFFF)  /* System Time sub-seconds */

/* Bit definition for Ethernet PTP Time Stamp High Update Register */
#define ETH_PTPTSHUR_TSUS    ((uint32_t)0xFFFFFFFF)  /* Time stamp update seconds */

/* Bit definition for Ethernet PTP Time Stamp Low Update Register */
#define ETH_PTPTSLUR_TSUPNS  ((uint32_t)0x80000000)  /* Time stamp update Positive or negative time */
#define ETH_PTPTSLUR_TSUSS   ((uint32_t)0x7FFFFFFF)  /* Time stamp update sub-seconds */

/* Bit definition for Ethernet PTP Time Stamp Addend Register */
#define ETH_PTPTSAR_TSA      ((uint32_t)0xFFFFFFFF)  /* Time stamp addend */

/* Bit definition for Ethernet PTP Target Time High Register */
#define ETH_PTPTTHR_TTSH     ((uint32_t)0xFFFFFFFF)  /* Target time stamp high */

/* Bit definition for Ethernet PTP Target Time Low Register */
#define ETH_PTPTTLR_TTSL     ((uint32_t)0xFFFFFFFF)  /* Target time stamp low */

/******************************************************************************/
/*                 Ethernet DMA Registers bits definition                     */
/******************************************************************************/

/* Bit definition for Ethernet DMA Bus Mode Register */
#define ETH_DMABMR_AAB       ((uint32_t)0x02000000)  /* Address-Aligned beats */
#define ETH_DMABMR_FPM        ((uint32_t)0x01000000)  /* 4xPBL mode */
#define ETH_DMABMR_USP       ((uint32_t)0x00800000)  /* Use separate PBL */
#define ETH_DMABMR_RDP       ((uint32_t)0x007E0000)  /* RxDMA PBL */
  #define ETH_DMABMR_RDP_1Beat    ((uint32_t)0x00020000)  /* maximum number of beats to be transferred in one RxDMA transaction is 1 */
  #define ETH_DMABMR_RDP_2Beat    ((uint32_t)0x00040000)  /* maximum number of beats to be transferred in one RxDMA transaction is 2 */
  #define ETH_DMABMR_RDP_4Beat    ((uint32_t)0x00080000)  /* maximum number of beats to be transferred in one RxDMA transaction is 4 */
  #define ETH_DMABMR_RDP_8Beat    ((uint32_t)0x00100000)  /* maximum number of beats to be transferred in one RxDMA transaction is 8 */
  #define ETH_DMABMR_RDP_16Beat   ((uint32_t)0x00200000)  /* maximum number of beats to be transferred in one RxDMA transaction is 16 */
  #define ETH_DMABMR_RDP_32Beat   ((uint32_t)0x00400000)  /* maximum number of beats to be transferred in one RxDMA transaction is 32 */                
  #define ETH_DMABMR_RDP_4xPBL_4Beat   ((uint32_t)0x01020000)  /* maximum number of beats to be transferred in one RxDMA transaction is 4 */
  #define ETH_DMABMR_RDP_4xPBL_8Beat   ((uint32_t)0x01040000)  /* maximum number of beats to be transferred in one RxDMA transaction is 8 */
  #define ETH_DMABMR_RDP_4xPBL_16Beat  ((uint32_t)0x01080000)  /* maximum number of beats to be transferred in one RxDMA transaction is 16 */
  #define ETH_DMABMR_RDP_4xPBL_32Beat  ((uint32_t)0x01100000)  /* maximum number of beats to be transferred in one RxDMA transaction is 32 */
  #define ETH_DMABMR_RDP_4xPBL_64Beat  ((uint32_t)0x01200000)  /* maximum number of beats to be transferred in one RxDMA transaction is 64 */
  #define ETH_DMABMR_RDP_4xPBL_128Beat ((uint32_t)0x01400000)  /* maximum number of beats to be transferred in one RxDMA transaction is 128 */  
#define ETH_DMABMR_FB        ((uint32_t)0x00010000)  /* Fixed Burst */
#define ETH_DMABMR_RTPR      ((uint32_t)0x0000C000)  /* Rx Tx priority ratio */
  #define ETH_DMABMR_RTPR_1_1     ((uint32_t)0x00000000)  /* Rx Tx priority ratio */
  #define ETH_DMABMR_RTPR_2_1     ((uint32_t)0x00004000)  /* Rx Tx priority ratio */
  #define ETH_DMABMR_RTPR_3_1     ((uint32_t)0x00008000)  /* Rx Tx priority ratio */
  #define ETH_DMABMR_RTPR_4_1     ((uint32_t)0x0000C000)  /* Rx Tx priority ratio */  
#define ETH_DMABMR_PBL    ((uint32_t)0x00003F00)  /* Programmable burst length */
  #define ETH_DMABMR_PBL_1Beat    ((uint32_t)0x00000100)  /* maximum number of beats to be transferred in one TxDMA (or both) transaction is 1 */
  #define ETH_DMABMR_PBL_2Beat    ((uint32_t)0x00000200)  /* maximum number of beats to be transferred in one TxDMA (or both) transaction is 2 */
  #define ETH_DMABMR_PBL_4Beat    ((uint32_t)0x00000400)  /* maximum number of beats to be transferred in one TxDMA (or both) transaction is 4 */
  #define ETH_DMABMR_PBL_8Beat    ((uint32_t)0x00000800)  /* maximum number of beats to be transferred in one TxDMA (or both) transaction is 8 */
  #define ETH_DMABMR_PBL_16Beat   ((uint32_t)0x00001000)  /* maximum number of beats to be transferred in one TxDMA (or both) transaction is 16 */
  #define ETH_DMABMR_PBL_32Beat   ((uint32_t)0x00002000)  /* maximum number of beats to be transferred in one TxDMA (or both) transaction is 32 */                
  #define ETH_DMABMR_PBL_4xPBL_4Beat   ((uint32_t)0x01000100)  /* maximum number of beats to be transferred in one TxDMA (or both) transaction is 4 */
  #define ETH_DMABMR_PBL_4xPBL_8Beat   ((uint32_t)0x01000200)  /* maximum number of beats to be transferred in one TxDMA (or both) transaction is 8 */
  #define ETH_DMABMR_PBL_4xPBL_16Beat  ((uint32_t)0x01000400)  /* maximum number of beats to be transferred in one TxDMA (or both) transaction is 16 */
  #define ETH_DMABMR_PBL_4xPBL_32Beat  ((uint32_t)0x01000800)  /* maximum number of beats to be transferred in one TxDMA (or both) transaction is 32 */
  #define ETH_DMABMR_PBL_4xPBL_64Beat  ((uint32_t)0x01001000)  /* maximum number of beats to be transferred in one TxDMA (or both) transaction is 64 */
  #define ETH_DMABMR_PBL_4xPBL_128Beat ((uint32_t)0x01002000)  /* maximum number of beats to be transferred in one TxDMA (or both) transaction is 128 */
#define ETH_DMABMR_DSL       ((uint32_t)0x0000007C)  /* Descriptor Skip Length */
#define ETH_DMABMR_DA        ((uint32_t)0x00000002)  /* DMA arbitration scheme */
#define ETH_DMABMR_SR        ((uint32_t)0x00000001)  /* Software reset */

/* Bit definition for Ethernet DMA Transmit Poll Demand Register */
#define ETH_DMATPDR_TPD      ((uint32_t)0xFFFFFFFF)  /* Transmit poll demand */

/* Bit definition for Ethernet DMA Receive Poll Demand Register */
#define ETH_DMARPDR_RPD      ((uint32_t)0xFFFFFFFF)  /* Receive poll demand  */

/* Bit definition for Ethernet DMA Receive Descriptor List Address Register */
#define ETH_DMARDLAR_SRL     ((uint32_t)0xFFFFFFFF)  /* Start of receive list */

/* Bit definition for Ethernet DMA Transmit Descriptor List Address Register */
#define ETH_DMATDLAR_STL     ((uint32_t)0xFFFFFFFF)  /* Start of transmit list */

/* Bit definition for Ethernet DMA Status Register */
#define ETH_DMASR_TSTS       ((uint32_t)0x20000000)  /* Time-stamp trigger status */
#define ETH_DMASR_PMTS       ((uint32_t)0x10000000)  /* PMT status */
#define ETH_DMASR_MMCS       ((uint32_t)0x08000000)  /* MMC status */
#define ETH_DMASR_EBS        ((uint32_t)0x03800000)  /* Error bits status */
  /* combination with EBS[2:0] for GetFlagStatus function */
  #define ETH_DMASR_EBS_DescAccess      ((uint32_t)0x02000000)  /* Error bits 0-data buffer, 1-desc. access */
  #define ETH_DMASR_EBS_ReadTransf      ((uint32_t)0x01000000)  /* Error bits 0-write trnsf, 1-read transfr */
  #define ETH_DMASR_EBS_DataTransfTx    ((uint32_t)0x00800000)  /* Error bits 0-Rx DMA, 1-Tx DMA */
#define ETH_DMASR_TPS         ((uint32_t)0x00700000)  /* Transmit process state */
  #define ETH_DMASR_TPS_Stopped         ((uint32_t)0x00000000)  /* Stopped - Reset or Stop Tx Command issued  */
  #define ETH_DMASR_TPS_Fetching        ((uint32_t)0x00100000)  /* Running - fetching the Tx descriptor */
  #define ETH_DMASR_TPS_Waiting         ((uint32_t)0x00200000)  /* Running - waiting for status */
  #define ETH_DMASR_TPS_Reading         ((uint32_t)0x00300000)  /* Running - reading the data from host memory */
  #define ETH_DMASR_TPS_Suspended       ((uint32_t)0x00600000)  /* Suspended - Tx Descriptor unavailabe */
  #define ETH_DMASR_TPS_Closing         ((uint32_t)0x00700000)  /* Running - closing Rx descriptor */
#define ETH_DMASR_RPS         ((uint32_t)0x000E0000)  /* Receive process state */
  #define ETH_DMASR_RPS_Stopped         ((uint32_t)0x00000000)  /* Stopped - Reset or Stop Rx Command issued */
  #define ETH_DMASR_RPS_Fetching        ((uint32_t)0x00020000)  /* Running - fetching the Rx descriptor */
  #define ETH_DMASR_RPS_Waiting         ((uint32_t)0x00060000)  /* Running - waiting for packet */
  #define ETH_DMASR_RPS_Suspended       ((uint32_t)0x00080000)  /* Suspended - Rx Descriptor unavailable */
  #define ETH_DMASR_RPS_Closing         ((uint32_t)0x000A0000)  /* Running - closing descriptor */
  #define ETH_DMASR_RPS_Queuing         ((uint32_t)0x000E0000)  /* Running - queuing the recieve frame into host memory */
#define ETH_DMASR_NIS        ((uint32_t)0x00010000)  /* Normal interrupt summary */
#define ETH_DMASR_AIS        ((uint32_t)0x00008000)  /* Abnormal interrupt summary */
#define ETH_DMASR_ERS        ((uint32_t)0x00004000)  /* Early receive status */
#define ETH_DMASR_FBES       ((uint32_t)0x00002000)  /* Fatal bus error status */
#define ETH_DMASR_ETS        ((uint32_t)0x00000400)  /* Early transmit status */
#define ETH_DMASR_RWTS       ((uint32_t)0x00000200)  /* Receive watchdog timeout status */
#define ETH_DMASR_RPSS       ((uint32_t)0x00000100)  /* Receive process stopped status */
#define ETH_DMASR_RBUS       ((uint32_t)0x00000080)  /* Receive buffer unavailable status */
#define ETH_DMASR_RS         ((uint32_t)0x00000040)  /* Receive status */
#define ETH_DMASR_TUS        ((uint32_t)0x00000020)  /* Transmit underflow status */
#define ETH_DMASR_ROS        ((uint32_t)0x00000010)  /* Receive overflow status */
#define ETH_DMASR_TJTS       ((uint32_t)0x00000008)  /* Transmit jabber timeout status */
#define ETH_DMASR_TBUS       ((uint32_t)0x00000004)  /* Transmit buffer unavailable status */
#define ETH_DMASR_TPSS       ((uint32_t)0x00000002)  /* Transmit process stopped status */
#define ETH_DMASR_TS         ((uint32_t)0x00000001)  /* Transmit status */

/* Bit definition for Ethernet DMA Operation Mode Register */
#define ETH_DMAOMR_DTCEFD    ((uint32_t)0x04000000)  /* Disable Dropping of TCP/IP checksum error frames */
#define ETH_DMAOMR_RSF       ((uint32_t)0x02000000)  /* Receive store and forward */
#define ETH_DMAOMR_DFRF      ((uint32_t)0x01000000)  /* Disable flushing of received frames */
#define ETH_DMAOMR_TSF       ((uint32_t)0x00200000)  /* Transmit store and forward */
#define ETH_DMAOMR_FTF       ((uint32_t)0x00100000)  /* Flush transmit FIFO */
#define ETH_DMAOMR_TTC       ((uint32_t)0x0001C000)  /* Transmit threshold control */
  #define ETH_DMAOMR_TTC_64Bytes       ((uint32_t)0x00000000)  /* threshold level of the MTL Transmit FIFO is 64 Bytes */
  #define ETH_DMAOMR_TTC_128Bytes      ((uint32_t)0x00004000)  /* threshold level of the MTL Transmit FIFO is 128 Bytes */
  #define ETH_DMAOMR_TTC_192Bytes      ((uint32_t)0x00008000)  /* threshold level of the MTL Transmit FIFO is 192 Bytes */
  #define ETH_DMAOMR_TTC_256Bytes      ((uint32_t)0x0000C000)  /* threshold level of the MTL Transmit FIFO is 256 Bytes */
  #define ETH_DMAOMR_TTC_40Bytes       ((uint32_t)0x00010000)  /* threshold level of the MTL Transmit FIFO is 40 Bytes */
  #define ETH_DMAOMR_TTC_32Bytes       ((uint32_t)0x00014000)  /* threshold level of the MTL Transmit FIFO is 32 Bytes */
  #define ETH_DMAOMR_TTC_24Bytes       ((uint32_t)0x00018000)  /* threshold level of the MTL Transmit FIFO is 24 Bytes */
  #define ETH_DMAOMR_TTC_16Bytes       ((uint32_t)0x0001C000)  /* threshold level of the MTL Transmit FIFO is 16 Bytes */
#define ETH_DMAOMR_ST        ((uint32_t)0x00002000)  /* Start/stop transmission command */
#define ETH_DMAOMR_FEF       ((uint32_t)0x00000080)  /* Forward error frames */
#define ETH_DMAOMR_FUGF      ((uint32_t)0x00000040)  /* Forward undersized good frames */
#define ETH_DMAOMR_RTC       ((uint32_t)0x00000018)  /* receive threshold control */
  #define ETH_DMAOMR_RTC_64Bytes       ((uint32_t)0x00000000)  /* threshold level of the MTL Receive FIFO is 64 Bytes */
  #define ETH_DMAOMR_RTC_32Bytes       ((uint32_t)0x00000008)  /* threshold level of the MTL Receive FIFO is 32 Bytes */
  #define ETH_DMAOMR_RTC_96Bytes       ((uint32_t)0x00000010)  /* threshold level of the MTL Receive FIFO is 96 Bytes */
  #define ETH_DMAOMR_RTC_128Bytes      ((uint32_t)0x00000018)  /* threshold level of the MTL Receive FIFO is 128 Bytes */
#define ETH_DMAOMR_OSF       ((uint32_t)0x00000004)  /* operate on second frame */
#define ETH_DMAOMR_SR        ((uint32_t)0x00000002)  /* Start/stop receive */

/* Bit definition for Ethernet DMA Interrupt Enable Register */
#define ETH_DMAIER_NISE      ((uint32_t)0x00010000)  /* Normal interrupt summary enable */
#define ETH_DMAIER_AISE      ((uint32_t)0x00008000)  /* Abnormal interrupt summary enable */
#define ETH_DMAIER_ERIE      ((uint32_t)0x00004000)  /* Early receive interrupt enable */
#define ETH_DMAIER_FBEIE     ((uint32_t)0x00002000)  /* Fatal bus error interrupt enable */
#define ETH_DMAIER_ETIE      ((uint32_t)0x00000400)  /* Early transmit interrupt enable */
#define ETH_DMAIER_RWTIE     ((uint32_t)0x00000200)  /* Receive watchdog timeout interrupt enable */
#define ETH_DMAIER_RPSIE     ((uint32_t)0x00000100)  /* Receive process stopped interrupt enable */
#define ETH_DMAIER_RBUIE     ((uint32_t)0x00000080)  /* Receive buffer unavailable interrupt enable */
#define ETH_DMAIER_RIE       ((uint32_t)0x00000040)  /* Receive interrupt enable */
#define ETH_DMAIER_TUIE      ((uint32_t)0x00000020)  /* Transmit Underflow interrupt enable */
#define ETH_DMAIER_ROIE      ((uint32_t)0x00000010)  /* Receive Overflow interrupt enable */
#define ETH_DMAIER_TJTIE     ((uint32_t)0x00000008)  /* Transmit jabber timeout interrupt enable */
#define ETH_DMAIER_TBUIE     ((uint32_t)0x00000004)  /* Transmit buffer unavailable interrupt enable */
#define ETH_DMAIER_TPSIE     ((uint32_t)0x00000002)  /* Transmit process stopped interrupt enable */
#define ETH_DMAIER_TIE       ((uint32_t)0x00000001)  /* Transmit interrupt enable */

/* Bit definition for Ethernet DMA Missed Frame and Buffer Overflow Counter Register */
#define ETH_DMAMFBOCR_OFOC   ((uint32_t)0x10000000)  /* Overflow bit for FIFO overflow counter */
#define ETH_DMAMFBOCR_MFA    ((uint32_t)0x0FFE0000)  /* Number of frames missed by the application */
#define ETH_DMAMFBOCR_OMFC   ((uint32_t)0x00010000)  /* Overflow bit for missed frame counter */
#define ETH_DMAMFBOCR_MFC    ((uint32_t)0x0000FFFF)  /* Number of frames missed by the controller */

/* Bit definition for Ethernet DMA Current Host Transmit Descriptor Register */
#define ETH_DMACHTDR_HTDAP   ((uint32_t)0xFFFFFFFF)  /* Host transmit descriptor address pointer */

/* Bit definition for Ethernet DMA Current Host Receive Descriptor Register */
#define ETH_DMACHRDR_HRDAP   ((uint32_t)0xFFFFFFFF)  /* Host receive descriptor address pointer */

/* Bit definition for Ethernet DMA Current Host Transmit Buffer Address Register */
#define ETH_DMACHTBAR_HTBAP  ((uint32_t)0xFFFFFFFF)  /* Host transmit buffer address pointer */

/* Bit definition for Ethernet DMA Current Host Receive Buffer Address Register */
#define ETH_DMACHRBAR_HRBAP  ((uint32_t)0xFFFFFFFF)  /* Host receive buffer address pointer */

#define ETH_100M 1


#endif  /* __CMSDK_H__ */

