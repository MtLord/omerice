/*
 * PApad_data.c
 *
 *  Created on: 2018/03/18
 *      Author: —T‘¿
 */
#include <PSpad_data.hpp>


#define delay_us_15 HAL_Delay(16/1000);




void Pspad::PSpad_get_dat()
{
	 CS_LOW;
	 //delay_us_15;
	 HAL_SPI_TransmitReceive(hspi2,(uint8_t*) CDMdata ,(uint8_t *)GetBytedata, 9, 1);
	 //delay_us_15
	 CS_HIGH;
	HAL_Delay(16);
}









