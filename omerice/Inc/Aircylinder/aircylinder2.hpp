/*
 * aircylinder2.hpp
 *
 *  Created on: 2018/08/29
 *      Author: —T‘¿
 */

#ifndef AIRCYLINDER2_HPP_
#define AIRCYLINDER2_HPP_
#include "stm32f4xx_hal.h"
class air2
{
public:
	void Open()
	{
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_SET);
	}
	void Close()
	{
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_RESET);
	}
};



#endif /* AIRCYLINDER2_HPP_ */
