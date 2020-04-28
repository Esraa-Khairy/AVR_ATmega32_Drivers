/*
 * UART_private.h
 *
 *  Created on: Mar 9, 2020
 *      Author: pc
 */

#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

#define 		   UART_PARITY_DISABLED		0U
#define 		   UART_PARTY_EVEN			2U
#define 		   UART_PARITY_ODD			3U

#define 			UART_BAUD_9600		1U
#define  			UART_BAUD_115200	2U
#define 			UART_BAUD_8400		0U



#define UART_STOP_1_BIT			0U
#define UART_STOP_2_BIT			1U



#define 			UART_SYS_FREQ_12M    1
#define  			UART_SYS_FREQ_8M     0
#define  			UART_SYS_FREQ_16M    2
#endif /* UART_PRIVATE_H_ */
