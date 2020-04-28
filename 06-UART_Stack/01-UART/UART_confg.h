/*
 * UART_confg.h
 *
 *  Created on: Mar 9, 2020
 *      Author: pc
 */

#ifndef UART_CONFG_H_
#define UART_CONFG_H_


/*options: UART_PARITY_DISABLED
 * 		   UART_PARTY_EVEN
 * 		   UART_PARITY_ODD*/
#define UART_u8_PARITY		UART_PARITY_DISABLED

/* options: UART_BAUD_9600
 * 			UART_BAUD_115200
 * 			UART_BAUD_8400
 */
#define UART_u8_BAUD_RATE	UART_BAUD_9600

/*optioins UART_STOP_1_BIT
 * 			UART_STOP_2_BIT*/

#define UART_u8_STOP_BITS  UART_STOP_1_BIT


/* options: UART_SYS_FREQ_12M
 * 			UART_SYS_FREQ_8M
 * 			UART_SYS_FREQ_16M
 */
#define UART_u8_SYS_FREQ	UART_SYS_FREQ_12M


#define UART_u32_TIME_OUT_TH 	10000UL

#endif /* UART_CONFG_H_ */
