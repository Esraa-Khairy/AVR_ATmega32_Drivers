/*
 * i2c_interface.h
 *
 *  Created on: Apr 8, 2020
 *      Author: pc
 */

#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_



typedef enum
{
	I2C_Ok,
	I2C_SC_Error,
	I2C_RSC_Error,
	I2C_SLA_W_Error,
	I2C_SLA_R_Error,
	I2C_DATA_Error,
	I2C_MR_DATA_Error,

}I2C_Error_States;



void I2C_voidMasterInit(void);

void I2C_voidSlaveInit(u8 Copy_u8SlaveAdd);

I2C_Error_States I2C_voidSendStartCondition (void);

I2C_Error_States I2C_voidSendRestartCondition (void);

I2C_Error_States I2C_voidSendSlaveAddressWithRead(u8 Copy_u8SlaveAdd);

I2C_Error_States I2C_voidSendSlaveAddressWithRead(u8 Copy_u8SlaveAdd);

I2C_Error_States I2C_voidMasterSendDataByte (u8 Copy_u8Data);

I2C_Error_States I2C_enuMasterReadDataByte (u8 * Copy_u8Data);

void I2C_voidSendStopCondition (void);





#endif /* I2C_INTERFACE_H_ */
