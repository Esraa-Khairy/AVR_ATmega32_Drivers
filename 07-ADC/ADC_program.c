/************************************************/
/* Author: Alzahraa Elsallakh                   */
/* Version: V01                                 */
/* Date: 26 Feb 2020                            */
/* Layer: MCAL                                  */
/* Component: ADC                               */
/* File Name: ADC_program.c                     */
/************************************************/

#include "STD_TYPES.h"
#include "BIT_MATHS.h"
#include "Delay_interface.h"

#include "ADC_interface.h"
#include "ADC_config.h"
#include "ADC_register.h"
#include "ADC_private.h"


/*
    Description: This function shall initiate ADC driver
    Input: void
    output: void
*/
extern void ADC_voidInit(void)
{
  /* 
      8 bits mode, AVCC ref voltage
      polling (not interrupt)
  */
  
  /* AVCC reference voltage */
  CLR_BIT(ADMUX,7);
  SET_BIT(ADMUX,6);
  
  /* Activate left adjustment mode */
  SET_BIT(ADMUX,5);
  
  /* ADC enable */
  SET_BIT(ADCSRA,7);
  
  /* Setting prescaler */
  SET_BIT(ADCSRA,2);
  SET_BIT(ADCSRA,1);
  SET_BIT(ADCSRA,0);
  
  
}
extern u8 ADC_u8GetChannelReading(u8 Copy_u8Channel)
{
  
  /* Selecting channel */
  ADMUX &= ADMUX_CHANNEL_CLEAR;
  ADMUX |= Copy_u8Channel;
  
  /* Starting conversion */
  SET_BIT(ADCSRA,6);
  
  /* Polling on the conversion complete flag */
  while (GET_BIT(ADCSRA,4) == 0);
  
  /* Clearing flag after polling */
  SET_BIT(ADCSRA,4);
  
  /* Getting result */
  return ADCH;
  
}
