/*
 * aircylinder5.hpp
 *
 *  Created on: 2018/08/29
 *      Author: —T‘¿
 */

#ifndef AIRCYLINDER5_HPP_
#define AIRCYLINDER5_HPP_
#include "stm32f4xx_hal.h"
class air5
{
public:
	void Open()
	{
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_14,GPIO_PIN_SET);
	}
	void Close()
	{
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_14,GPIO_PIN_RESET);
	}
};




#endif /* AIRCYLINDER5_HPP_ */
