/*
 * aircylinder3.hpp
 *
 *  Created on: 2018/08/29
 *      Author: —T‘¿
 */

#ifndef AIRCYLINDER3_HPP_
#define AIRCYLINDER3_HPP_
#include "stm32f4xx_hal.h"
class air3
{
public:
	void Open()
	{
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_12,GPIO_PIN_SET);
	}
	void Close()
	{
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_12,GPIO_PIN_RESET);
	}
};




#endif /* AIRCYLINDER3_HPP_ */
