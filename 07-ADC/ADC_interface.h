/************************************************/
/* Author: Alzahraa Elsallakh                   */
/* Version: V01                                 */
/* Date: 26 Feb 2020                            */
/* Layer: MCAL                                  */
/* Component: ADC                               */
/* File Name: ADC_interface.h                   */
/************************************************/

#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H


/*
    Description: This function shall initiate ADC driver
    Input: void
    output: void
*/
extern void ADC_voidInit(void);


extern u8 ADC_u8GetChannelReading (u8 Copy_u8Channel);

#endif
