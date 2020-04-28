/*
 * I2c_register.h
 *
 *  Created on: Apr 8, 2020
 *      Author: pc
 */

#ifndef I2C_REGISTER_H_
#define I2C_REGISTER_H_



#define TWDR  	*((volatile u8*)0x23)
#define TWAR 	*((volatile u8*)0x22)
#define TWSR 	*((volatile u8*)0x21)
#define TWBR 	*((volatile u8*)0x20)
#define TWCR	*((volatile u8*)0x56)

#endif /* I2C_REGISTER_H_ */
