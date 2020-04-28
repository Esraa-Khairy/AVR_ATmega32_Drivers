/*
 * UART_program.c

 *
 *  Created on: Mar 9, 2020
 *      Author: Esraa Awad
 */
#include "STD_TYPES.h"
#include "BIT_MATHS.h"
#include "UART_register.h"
#include "UART_private.h"
#include "UART_confg.h"
#include "UART_interface.h"
/*lock up table*/
const u8 BaudRateValue  [3][3] =
{
		/*4800 , 9600 , 115200 ,  */
		{0x67    ,0x33      , 0x03        },  /* CLK SYSTEM 0 = 8mhz*/
		{ 154     , 77     ,   6      },  /*clK SYTEM 1 =12 mhz*/
		{    0xcf  , 0x67     ,0x08          }  /*CLK SYETM 2 =16 MHZ*/

};



void (*EndOfTransmitCB) (void);

void UART_voidInit(void)
{

	/* U2X = 0*/
	CLR_BIT(UCSRA,1);


	/*Disable all interrupt
	 * Enable RX and TX
	 * char size 8 bits
	 * */
	UCSRB = 0x18;

	/* Asynch Mode
	 * charcter size = 8 bit
	 *
	 */
	UCSRC = (   (1<<7) | (UART_u8_PARITY <<4) | (UART_u8_STOP_BITS << 3) | ( 3 << 1)  );


	/*assign baud rate */
	UBRRL = BaudRateValue[UART_u8_SYS_FREQ][UART_u8_BAUD_RATE];    // need revision


}



void UART_voidTransmirDataSynch (u8 Copy_u8Data)
{

	u32 Local_u32Timeout = 0;
	/* Send Data on UDR*/
	UDR_T = Copy_u8Data;

	u8 Local_u8Error  =STD_TYPES_ERROR_OK;

	/*wait till flag is raisde */
	while(GET_BIT(UCSRA,6) == 0 && Local_u32Timeout < UART_u32_TIME_OUT_TH )
	{
		Local_u32Timeout ++;
	}


	if (Local_u32Timeout >= UART_u32_TIME_OUT_TH)
	{
		Local_u8Error = STD_TYPES_ERROR_NOK;

	}

	else
	{
		/*clear flag*/
		SET_BIT(UCSRA,6);
	}



}
void UART_voidTransmitDataAsynch (u8 Copy_u8Data , void (* Copy_ptr)(void) )
{




	/*enable int */
	SET_BIT(UCSRB,6);


	/* Send Data on UDR*/
	UDR_T = Copy_u8Data;

	/*save the call back address */
	EndOfTransmitCB = Copy_ptr;




}


u8 UART_u8RecieveSynch (u8 * Copy_pu8Data)

{

	u32 Local_u32Timeout = 0;


	u8 Local_u8Error  =STD_TYPES_ERROR_OK;

	/*wait till flag is raisde */
	while(GET_BIT(UCSRA,6) == 0 && Local_u32Timeout < UART_u32_TIME_OUT_TH )
	{
		Local_u32Timeout ++;
	}


	if (Local_u32Timeout >= UART_u32_TIME_OUT_TH)
	{
		Local_u8Error = STD_TYPES_ERROR_NOK;

	}

	else
	{
		/*set data to recieved pointer*/
		*Copy_pu8Data = UDR_R;
	}

	return (Local_u8Error);


}


void UART_u8RecieveAsynch (void (* Copy_ptr)(u8))
{


	if (GET_BIT(UCSRA,7) == 1)
	{
		Copy_ptr(UDR_R);
	}

	/*notjing to recieve now , enable recieve interrupt */
	else
	{
		/*enable int*/
		SET_BIT(UCSRB , 7);

		/*save call back in global variable */
		EndOfTransmitCB = Copy_ptr;
	}






}




