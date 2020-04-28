/*
 * I2C_private.h

 *
 *  Created on: Apr 8, 2020
 *      Author: pc
 */

#ifndef I2C_PRIVATE_H_
#define I2C_PRIVATE_H_


/* TWCR Pits numbers */

#define TWCR_INT		7
#define TWCR_EA			6
#define TWCR_STA		5
#define TWCR_STO 		4
#define TWCR_WC    		3
#define TWCR_EN			2
#define TWCR_IE			0



/*TWSR Pins*/

#define  TWSR_TWPS1		1
#define  TWSR_TWPS0		0


#define I2C_STATUS_CODE_MASK    0xF8



/******************************************* Status Code **********************************/

/*Master transmit case*/

#define I2C_MT_SC_ACK			0X08
#define I2C_MT_RSC_ACK			0X10
#define I2C_MT_SLA_W_ACK		0X18
#define I2C_MT_DATA_ACK			0X28


/*Master Receive case*/

#define I2C_MR_SC_ACK			0X08
#define I2C_MR_RSC_ACK			0X10
#define I2C_MR_SLA_R_ACK		0X48
#define I2C_MR_DATA_ACK			0X50










#endif /* I2C_PRIVATE_H_ */
