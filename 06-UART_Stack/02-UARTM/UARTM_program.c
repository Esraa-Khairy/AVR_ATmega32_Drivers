#include "BIT_MATHS.h"
#include "STD_TYPES.h"


#include "UART_interface.h"

#include "UARTM_config.h"
#include "UARTM_interface.h"
#include "UARTM_private.h"


URTM_JobRequest URTM_QUEUE [URTM_u8_MAX_QUEUE_SIZE];

u8 	  URTM_QCurrent 	= 0;
u8    URTM_QNext    	= 0;
u8    URTM_QAvailable 	= URTM_u8_MAX_QUEUE_SIZE;
u8    URTM_BustFlag   	= 0;

void (*Pfunc ) (void);

extern u8 URTM_u8PerformJobRequest (URTM_JobRequest Copy_jobInfo)
{


	u8 Local_u8State = STD_TYPES_ERROR_OK;


	/*Add the job to the queue "enqueue" */


	/*Add job to the next location*/
	if (URTM_QAvailable >0)
	{
		URTM_QAvailable --;
		URTM_QUEUE[URTM_QNext] = Copy_jobInfo;



		/*Increment the next*/
		if (URTM_QNext == (URTM_u8_MAX_QUEUE_SIZE -1))  // to not overswite
		{
			URTM_QNext = 0;
		}
		else
		{
			URTM_QNext ++;
		}

		voidExecute();   // called to continue word

	}
	else
	{
		Local_u8State = STD_TYPES_ERROR_NOK;
	}

	return (Local_u8State);

}



static void voidExecute (void)
{

	if (URTM_BustFlag == 0)  //free
	{
		voidStart();
	}
	else
	{
		/* do nothing */
	}



}


static void voidStart (void)
{

	u8 Local_u8Counter;

	if (URTM_BustFlag == 0)  //free
	{
		voidStart();
	}
	else
	{
		/* do nothing */
	}


	/*queue is empty */
	if ( URTM_QAvailable == URTM_u8_MAX_QUEUE_SIZE)
	{
		URTM_BustFlag =0;
		/*Do nothing */
	}

	/*Queue includes jobs */
	else

	{

		URTM_BustFlag =1;
		if (URTM_QAvailable == (URTM_u8_MAX_QUEUE_SIZE-1))  // there is only one job in queue so execute it
		{
			/* start the job */
			switch (URTM_QUEUE[URTM_QCurrent].jobType)
			{
			case URTM_SEND_SYNC :
				u8 Local_u8Counter;
				for (Local_u8Counter =0 ; Local_u8Counter< URTM_QUEUE[URTM_QCurrent].Length ; Local_u8Counter++)
				{
					UART_voidTransmirDataSynch(URTM_QUEUE[URTM_QCurrent].DataBuffer[Local_u8Counter]);

				}

				URTM_QAvailable ++;
				/*Increment the next*/
				if (URTM_QNext == (URTM_u8_MAX_QUEUE_SIZE -1))  // to not overwrite
				{
					URTM_QNext = 0;
				}
				else
				{
					URTM_QNext ++;
				}

				break;
			case URTM_SEND_ASYNCH : voidSendAsynch();break;
			case URTM_u8RecieveSYNCk   : voidSendynch(); break;
			case URTM_Send_Asynch()    : voidSendAsynch();break;

			}

		}
		else
		{

		}

	}

}

static void voidstart (void)
{


}



static void voidSendSynch (void)
{
	u8 Local_u8Counter;

	for (Local_u8Counter , )





}


void App_CB (void(*ptfunc)(void))
{



}

