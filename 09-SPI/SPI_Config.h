/*
 * SPI_Config.h

 *
 *  Created on: Apr 22, 2020
 *      Author: Esraa Awad
 */

#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_



/* Configuration for master or slave mode
 * options:-
 * 				SPI_u8_MASTER
				SPI_u8_SLAVE	*/

#define SPI_u8_SELECT_MODE 	SPI_u8_MASTER


/*config for date order
 * options:- SPI_u8_MSB
			 SPI_u8_LSB	 */
#define SPI_u8_DATE_ORDER	SPI_u8_MSB


/* Config for clock polarity
 * options:- SPI_u8_RAISING_EDGE
			 SPI_u8_FALLING_EDGE */
#define SPI_u8_CLK_POLARITY		SPI_u8_RAISING_EDGE

/* Config for clock phase
 * options:- SPI_u8_SMAPLE
			 SPI_u8_SETUP	*/
#define SPI_u8_CLK_PHASE		SPI_u8_SETUP


/* Config for clk rate
 * options:-SPI_u8_CLK_OVER_4
			SPI_u8_CLK_OVER_16
			SPI_u8_CLK_OVER_64
			SPI_u8_CLK_OVER_128
			SPI_u8_HCLK_OVER_2
			SPI_u8_HCLK_OVER_8
			SPI_u8_HCLK_OVER_32
			SPI_u8_HCLK_OVER_64*/


#define SPI_u8_CLK_RATE  	SPI_u8_CLK_OVER_16

/* config macro for time out */

#define SPI_u16_TIME_OUT	50000


#endif /* SPI_CONFIG_H_ */
