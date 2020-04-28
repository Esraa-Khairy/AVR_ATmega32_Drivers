/*
 * SPI_program.c

 *
 *  Created on: Apr 22, 2020
 *      Author: Esraa Awad
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_Config.h"
#include "SPI_register.h"


/* Global Pointer for size , Index , recieved and tranmitted buffers to be used by ISR*/
static u8 * SPI_pu8TransmittedBuffer = NULL;

static u8 * SPI_pu8RecievedBuffer = NULL;

static u8 SPI_BufferSize ;

static void (*SPI_pFNotivicationFunc)(void) = NULL;

static u8 SPI_u8BufferIndex;

static u8 SPI_BusyFlag;




void SPI_voidInit (void)
{
	/* Choose MAster or Slave Mode  */

#if SPI_u8_SELECT_MODE == SPI_u8_MASTER
	SET_BIT(SPCR,SPCR_MSTR);

	#if SPI_u8_CLK_RATE == SPI_u8_CLK_OVER_4
		CLR_BIT (SPCR,SPCR_SPR1);
		CLR_BIT(SPCR,SPCR_SPR0);
	#elif SPI_u8_CLK_RATE == SPI_u8_CLK_OVER_16
		CLR_BIT (SPCR,SPCR_SPR1);
		SET_BIT(SPCR,SPCR_SPR0);
	#elif SPI_u8_CLK_RATE == SPI_u8_CLK_OVER_64
		CLR_BIT (SPCR,SPCR_SPR1);
		SET_BIT(SPCR,SPCR_SPR0);

	#elif SPI_u8_CLK_RATE == SPI_u8_CLK_OVER_128
		SET_BIT (SPCR,SPCR_SPR1);
		SET_BIT(SPCR,SPCR_SPR0);
	#elif SPI_u8_CLK_RATE == SPI_u8_HCLK_OVER_2
		SET_BIT (SPCR,SPCR_SPR1);
		SET_BIT(SPCR,SPCR_SPR0);
		SET_BIT(SPCR,SPCR_SPI2X);
	#endif


#elif SPI_u8_SELECT_MODE == SPI_u8_SLAVE
	CLR_BIT(SPCR,SPCR_MSTR);

#endif

	/* Choose the data order */
#if SPI_u8_DATE_ORDER == SPI_u8_MSB
	CLR_BIT(SPCR,SPCR_DORD);
#elif SPI_u8_DATE_ORDER == SPI_u8_LSB
	SET_BIT(SPCR,SPCR_DORD);
#endif

	/* choose clock polarity */
#if SPI_u8_CLK_POLARITY ==  SPI_u8_FALLING_EDGE
	SET_BIT(SPCR,SPCR_CPOL);
#elif SPI_u8_CLK_POLARITY == SPI_u8_RAISING_EDGE
	CLR_BIT(SPCR,SPCR_CPOL);
#endif
	/* Choose Clock Phase */
#if SPI_u8_CLK_PHASE == SPI_u8_SMAPLE
	CLR_BIT(SPCR,SPCR_CPHA);
#elif SPI_u8_CLK_PHASE == SPI_u8_SETUP
	SET_BIT(SPCR,SPCR_CPHA);

#endif
	/* SPI Enable */
	SET_BIT(SPCR,SPCR_SPE);



}

u8 SPI_u8SendDateByteSynch (u8 Copy_u8TransmittedByte)
{
	u8 Local_u8ReturnState = STD_TYPES_u8_ERROR_OK;
	u16 Local_u16TimeOutCounter = 0;

	SPDR = Copy_u8TransmittedByte;

	/* check collifion flag */
	if (GET_BIT(SPSR , SPSR_WCOL)==1)
	{
		Local_u8ReturnState = STD_TYPES_u8_ERROR_NOK;
	}

	/* wait until transmission is completed */
	while ( (GET_BIT(SPSR,SPSR_SPIF) == 0) && Local_u16TimeOutCounter < SPI_u16_TIME_OUT )
	{
		Local_u16TimeOutCounter++;
	}

	if (Local_u16TimeOutCounter >= SPI_u16_TIME_OUT)
	{
		Local_u8ReturnState = STD_TYPES_u8_ERROR_NOK;
	}



	return (Local_u8ReturnState);

}

u8 SPI_u8RecievedDataByteSynch (u8 * Copy_pu8RecievedByte)
{
	u8 Local_u8ReturnState = STD_TYPES_u8_ERROR_OK;
	u16 Local_u16TimeOutCounter = 0;
	/* Check the Null Pointer */
	if (Copy_pu8RecievedByte == NULL)
	{
		Local_u8ReturnState = STD_TYPES_u8_ERROR_NOK;

	}
	else
	{
		/* wait until transmission is completed */
			while ( (GET_BIT(SPSR,SPSR_SPIF) == 0) && Local_u16TimeOutCounter < SPI_u16_TIME_OUT )
			{
				Local_u16TimeOutCounter++;
			}

			if (Local_u16TimeOutCounter >= SPI_u16_TIME_OUT)
			{
				Local_u8ReturnState = STD_TYPES_u8_ERROR_NOK;
			}
			else
			{
				Copy_pu8RecievedByte = SPDR;

			}
	}

	return (Local_u8ReturnState);

}


u8 SPI_u8SendRecieveByteSynch (u8 Copy_u8TransmiyyedByte ,u8 * Copy_pu8RecievedByte)
{
	u8 Local_u8ReturnState = STD_TYPES_u8_ERROR_OK;
		u16 Local_u16TimeOutCounter = 0;
		/* Check the Null Pointer */
		if (Copy_pu8RecievedByte == NULL)
		{
			Local_u8ReturnState = STD_TYPES_u8_ERROR_NOK;

		}
		else
		{
			SPDR =Copy_u8TransmiyyedByte ;
			/* check collifion flag */
				if (GET_BIT(SPSR , SPSR_WCOL)==1)
				{
					Local_u8ReturnState = STD_TYPES_u8_ERROR_NOK;
				}
			/* wait until transmission is completed */
				while ( (GET_BIT(SPSR,SPSR_SPIF) == 0) && Local_u16TimeOutCounter < SPI_u16_TIME_OUT )
				{
					Local_u16TimeOutCounter++;
				}

				if (Local_u16TimeOutCounter >= SPI_u16_TIME_OUT)
				{
					Local_u8ReturnState = STD_TYPES_u8_ERROR_NOK;
				}
				else
				{
					Copy_pu8RecievedByte = SPDR;

				}
		}

		return (Local_u8ReturnState);


}


u8 SPI_u8SendRecievedBufferAsynch (u8 * Copy_pu8TransmittedBuffer , u8 * Copy_pu8RecievedBuffer , u8 Copy_u8BufferSize,void(*Copy_pfNotifyFunc(void)) )
{
	u8 Local_u8ReturnState = STD_TYPES_u8_ERROR_OK;

	/*check the null pointer*/
	if ( (Copy_pu8TransmittedBuffer == NULL) || (Copy_pu8RecievedBuffer == NULL ) || (Copy_pfNotifyFunc == NULL) || (SPI_BusyFlag ==1))
	{
		Local_u8ReturnState = STD_TYPES_u8_ERROR_NULL_POINTER;
	}

	else
	{
		/* Set busy flag */
		SPI_BusyFlag = 1;
		/* Init Global Pointers */

		SPI_pu8TransmittedBuffer = Copy_pu8TransmittedBuffer;
		SPI_pu8RecievedBuffer = Copy_pu8RecievedBuffer;

		SPI_BufferSize = Copy_u8BufferSize;
		SPI_pFNotivicationFunc = Copy_pfNotifyFunc;


		/* Send first Byte */
		SPDR = SPI_pu8TransmittedBuffer[SPI_u8BufferIndex];


		/*Enable SPI Interrupt */
		SET_BIT(SPCR , SPCR_SPIE);

	}

	return (Local_u8ReturnState);

}

void __vector_12(void)
{
	/* Read Date byte*/
	SPI_pu8RecievedBuffer[SPI_u8BufferIndex] = SPDR;

	/* Increment Buffer Index */
	SPI_u8BufferIndex ++;

	/* Check that buffer index  = buffer size or not */
	if (SPI_u8BufferIndex == SPI_BufferSize)
	{
		/* Disable interrupt */
		CLR_BIT(SPCR,SPCR_SPIE);

		/* Clear buffer index */
		SPI_u8BufferIndex = 0;

		/* Call notification function*/
		SPI_pFNotivicationFunc();

		/* Clear busy flag */
		SPI_BusyFlag = 0;

	}
	else
	{
		/* Send the Next byte */
		SPDR = SPI_pu8TransmittedBuffer[SPI_u8BufferIndex];
	}


}

/*ISR(12)
{
	}*/




