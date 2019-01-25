#ifndef __W25Q64_H__
#define __W25Q64_H__
#include "g32f1xx.h"
#define W25X_WriteEnable      0x06 //Write Enable
#define W25X_WriteEnableVSR   0x50 //Write Enable for Volatile Status Register
#define W25X_WriteDisable     0x04 //Write Disable
#define W25X_ReadStatusReg1   0x05 //��״̬�Ĵ���1��S7~S0
#define W25X_ReadStatusReg2   0x35 //��״̬�Ĵ���2��S15~S8
#define W25X_WriteStatusReg   0x01 //д��״̬�Ĵ�����BYTE1:S7~S0  BYTE2��S15~S8
#define W25X_PageProgram      0x02 //��ҳ��̣�BYTE1:A23~A16|2:A15~A8|3:A7~A0|4:D7~D0 #define W25X_SectorErase      0x20 //����������4K BYTE1:A23~A16|2:A15~A8|3:A7~A0 #define W25X_BlockErase32K    0x52 //�����:32K BYTE1:A23~A16|2:A15~A8|3:A7~A0
#define W25X_BlockErase64K    0xD8 //�����:64K BYTE1:A23~A16|2:A15~A8|3:A7~A0
#define W25X_ChipErase           0xC7    //оƬ����
#define W25X_EraseSuspend        0x75    //��ͣ����
#define W25X_EraseResume         0x7A    //�ָ�����
#define W25X_PowerDown           0xB9    //����
#define W25X_ContinuousReadMode  0xFF    //������ģʽ
#define W25X_ReadData         0x03 //�����ݣ�BYTE1:A23~A16|2:A15~A8|3:A7~A0|4:D7~D0 #define W25X_FastReadData    0x0B //���ٶ�ȡBYTE1:A23~A16|2:A15~A8|3:A7~A0|4:dummy|5:D7~D0 #define W25X_FastReadDual   0x3B //����˫��ȡBYTE1:A23~A16|2:A15~A8|3:A7~A0|4:dummy|5:D7~D0  
#define W25X_SectorErase      0x20

u16 SPI_Flash_ReadID(void);
void SPI_Flash_Read(u8 *pBuffer, u32 ReadAddr, u16 NumByteToRead)  ;
void SPI_Flash_Write_Page(u8 *pBuffer, u32 WriteAddr, u16 NumByteToWrite);
void SPI_Flash_Erase_Sector(u32 Dst_Addr) ;
void SPI_Flash_Write_NoCheck(u8 *pBuffer, u32 WriteAddr, u16 NumByteToWrite);
void SPI_Flash_Write(u8 *pBuffer, u32 WriteAddr, u16 NumByteToWrite);
void SPI_Flash_Erase_Chip(void)   ;
#endif