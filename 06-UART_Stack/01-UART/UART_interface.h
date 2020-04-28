/*
 * UART_interface.h
 *
 *  Created on: Mar 9, 2020
 *      Author: pc
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

void UART_voidInit(void);



void UART_voidTransmirDataSynch (u8 Copy_u8Data);
void UART_voidTransmitDataAsynch (u8 Copy_u8Data , void (* Copy_ptr)(void) );


u8 UART_u8RecieveSynch (u8 * Copy_pu8Data);
void UART_u8RecieveAsynch (void (* Copy_ptr)(u8));   // u8 -> value that i read





#endif /* UART_INTERFACE_H_ */
