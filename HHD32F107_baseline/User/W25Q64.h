#ifndef __W25Q64_H__
#define __W25Q64_H__
#include "g32f1xx.h"
#define W25X_WriteEnable      0x06 //Write Enable
#define W25X_WriteEnableVSR   0x50 //Write Enable for Volatile Status Register
#define W25X_WriteDisable     0x04 //Write Disable
#define W25X_ReadStatusReg1   0x05 //¶Á×´Ì¬¼Ä´æÆ÷1£ºS7~S0
#define W25X_ReadStatusReg2   0x35 //¶Á×´Ì¬¼Ä´æÆ÷2£ºS15~S8
#define W25X_WriteStatusReg   0x01 //Ð´¶Á×´Ì¬¼Ä´æÆ÷£ºBYTE1:S7~S0  BYTE2£ºS15~S8
#define W25X_PageProgram      0x02 //µ¥Ò³±à³Ì£ºBYTE1:A23~A16|2:A15~A8|3:A7~A0|4:D7~D0 #define W25X_SectorErase      0x20 //ÉÈÇø²Á³ý£º4K BYTE1:A23~A16|2:A15~A8|3:A7~A0 #define W25X_BlockErase32K    0x52 //¿é²Á³ý:32K BYTE1:A23~A16|2:A15~A8|3:A7~A0
#define W25X_BlockErase64K    0xD8 //¿é²Á³ý:64K BYTE1:A23~A16|2:A15~A8|3:A7~A0
#define W25X_ChipErase           0xC7    //Ð¾Æ¬²Á³ý
#define W25X_EraseSuspend        0x75    //ÔÝÍ£²Á³ý
#define W25X_EraseResume         0x7A    //»Ö¸´²Á³ý
#define W25X_PowerDown           0xB9    //µôµç
#define W25X_ContinuousReadMode  0xFF    //Á¬Ðø¶ÁÄ£Ê½
#define W25X_ReadData         0x03 //¶ÁÊý¾Ý£ºBYTE1:A23~A16|2:A15~A8|3:A7~A0|4:D7~D0 #define W25X_FastReadData    0x0B //¿ìËÙ¶ÁÈ¡BYTE1:A23~A16|2:A15~A8|3:A7~A0|4:dummy|5:D7~D0 #define W25X_FastReadDual   0x3B //¿ìËÙË«¶ÁÈ¡BYTE1:A23~A16|2:A15~A8|3:A7~A0|4:dummy|5:D7~D0  
#define W25X_SectorErase      0x20

u16 SPI_Flash_ReadID(void);
void SPI_Flash_Read(u8 *pBuffer, u32 ReadAddr, u16 NumByteToRead)  ;
void SPI_Flash_Write_Page(u8 *pBuffer, u32 WriteAddr, u16 NumByteToWrite);
void SPI_Flash_Erase_Sector(u32 Dst_Addr) ;
void SPI_Flash_Write_NoCheck(u8 *pBuffer, u32 WriteAddr, u16 NumByteToWrite);
void SPI_Flash_Write(u8 *pBuffer, u32 WriteAddr, u16 NumByteToWrite);
void SPI_Flash_Erase_Chip(void)   ;
#endif