/*
 * L3G4200D.cpp
 *
 *  Created on: 2018/06/17
 *
 */

#include "L3G4200D.hpp"
uint8_t Gyro::readByte(uint8_t reg )
{
	uint8_t address,val;

		HAL_GPIO_WritePin( gyro_cs_GPIO_Port, gyro_cs_Pin, GPIO_PIN_RESET );

		 address =( reg|0x80);
		HAL_SPI_Transmit( hspi3, &address,1,100 );

		HAL_SPI_Receive( hspi3,&val,1,100 );

		HAL_GPIO_WritePin( gyro_cs_GPIO_Port,gyro_cs_Pin, GPIO_PIN_SET );
return (uint8_t)val;
}

void Gyro::writeByte(uint8_t reg, uint8_t val)
{
	HAL_GPIO_WritePin( gyro_cs_GPIO_Port, gyro_cs_Pin, GPIO_PIN_RESET );

	HAL_SPI_Transmit( hspi3, &reg,1,10 );

	HAL_SPI_Transmit( hspi3, &val,1,10 );

	HAL_GPIO_WritePin( gyro_cs_GPIO_Port,gyro_cs_Pin, GPIO_PIN_SET );
}

  float Gyro::getZvel(  ){
	  signed short ret= (readByte(OUT_Z_H)<<8 | readByte(OUT_Z_L)) ;
	return (float)ret*0.070;

}

float Gyro::Zdeg()
{
	return deg;
}
