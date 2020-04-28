/*
 * SPI_interface.h

 *
 *  Created on: Apr 22, 2020
 *      Author: Esraa Awad
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_


void SPI_voidInit (void);

u8 SPI_u8SendDateByteSynch (u8 Copy_u8TransmittedByte);

u8 SPI_u8RecievedDataByteSynch (u8 * Copy_pu8RecievedByte);


u8 SPI_u8SendRecieveByteSynch (u8 Copy_u8TransmiyyedByte ,u8 * Copy_pu8RecievedByte);


u8 SPI_u8SendRecievedBufferAsynch (u8 * Copy_pu8TransmittedBuffer , u8 * Copy_pu8RecievedBuffer , u8 Copy_u8BufferSize,void(*Copy_pfNotifyFunc(void)) );




#endif /* SPI_INTERFACE_H_ */
