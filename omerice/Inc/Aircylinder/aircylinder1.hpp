/*
 * aircylinder1.hpp
 *
 *  Created on: 2018/08/29
 *      Author: —T‘¿
 */

#ifndef AIRCYLINDER1_HPP_
#define AIRCYLINDER1_HPP_
#include "stm32f4xx_hal.h"
class air1
{
public:
	void Open()
	{
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4,GPIO_PIN_SET);
	}
	void Close()
	{
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4,GPIO_PIN_RESET);
	}
};



#endif /* AIRCYLINDER1_HPP_ */
