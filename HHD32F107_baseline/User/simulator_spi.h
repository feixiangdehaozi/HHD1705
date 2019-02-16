#ifndef __SIMULATOR_SPI_H__
#define __SIMULATOR_SPI_H__

#include "hhd32f1xx.h"

#define SPI4_CS_PIN			PIN7
#define SPI4_CS_PORT		GPIOC

#define SPI4_SCK_PIN		PIN10
#define SPI4_SCK_PORT		GPIOC

#define SPI4_MISO_PIN		PIN11
#define SPI4_MISO_PORT		GPIOC

#define SPI4_MOSI_PIN		PIN12
#define SPI4_MOSI_PORT		GPIOC

#define SPI4_CS				SPI4_CS_PORT->OUT.bit.IO7 
#define SPI4_CLK		    SPI4_SCK_PORT->OUT.bit.IO10	
#define SPI4_MOSI			SPI4_MOSI_PORT->OUT.bit.IO12
#define SPI4_MISO			(GPIOC->PIN.bit.IO11)




void simulator_Init(void);
unsigned char readWriteByte(unsigned char data);
unsigned char readByte(void);
void WriteByte(unsigned char data);
uint16_t writeArray(uint8_t *data, uint16_t byteLen);
uint16_t readArray(uint8_t *data, uint16_t byteLen);















#endif



