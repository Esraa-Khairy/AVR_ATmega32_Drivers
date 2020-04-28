


/*SPCR Bits*/
#define SPCR_SPIE 			7
#define SPCR_SPE 			6
#define SPCR_DORD 			5
#define SPCR_MSTR 			4
#define SPCR_CPOL 			3
#define SPCR_CPHA 			2
#define SPCR_SPR1 			1
#define SPCR_SPR0 			0


/*SPSR Bits*/
#define SPSR_SPIF			7
#define SPSR_WCOL			6
#define SPSR_SPI2X			0


/* Macros for configuration */

/* Macros for Selecting the mode Master or Slave  */
#define SPI_u8_MASTER	0
#define SPI_u8_SLAVE	1


/* macros for date order */
#define SPI_u8_MSB		0
#define SPI_u8_LSB		1



/* Macros for Clock polarity  */
#define SPI_u8_RAISING_EDGE		0
#define SPI_u8_FALLING_EDGE		1




/* Macros for clock phase */
#define SPI_u8_SMAPLE		0
#define SPI_u8_SETUP		1



/* Macros for clock Rate in master mode */
#define SPI_u8_CLK_OVER_4		0
#define SPI_u8_CLK_OVER_16		1
#define SPI_u8_CLK_OVER_64		2
#define SPI_u8_CLK_OVER_128		3
#define SPI_u8_HCLK_OVER_2		4
#define SPI_u8_HCLK_OVER_8		5
#define SPI_u8_HCLK_OVER_32		6
#define SPI_u8_HCLK_OVER_64		7

void __vector_12(void)   __attribute__((signal));

#define ISR(NO)      void __vector_##NO(void)__attribute__((signal));\
						void __vector_##NO(void)

