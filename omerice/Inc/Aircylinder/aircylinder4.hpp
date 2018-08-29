/*
 * aircylinder4.hpp
 *
 *  Created on: 2018/08/29
 *      Author: —T‘¿
 */

#ifndef AIRCYLINDER4_HPP_
#define AIRCYLINDER4_HPP_
#include "stm32f4xx_hal.h"
class air4
{
public:
	void Open()
	{
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_2,GPIO_PIN_SET);
	}
	void Close()
	{
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_2,GPIO_PIN_RESET);
	}
};





#endif /* AIRCYLINDER4_HPP_ */
