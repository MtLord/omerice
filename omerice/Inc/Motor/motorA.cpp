/*
 * motorA.cpp
 *
 *  Created on: 2018/05/27
 *      Author: —T‘¿
 */
#include "MotorA.hpp"

void MotorA::setDuty(float d)
{
	if(d>=0)
	{
					HAL_GPIO_WritePin(direA_GPIO_Port,direA_Pin,GPIO_PIN_RESET);
					__HAL_TIM_SetCompare(Motorhandler,TIM_CHANNEL_1,map(d,0,100,0,999));

	}

	else if(d<0)
	{
		__HAL_TIM_SetCompare(Motorhandler,TIM_CHANNEL_1,map(-d,0,100,0,999));
		HAL_GPIO_WritePin(direA_GPIO_Port,direA_Pin,GPIO_PIN_SET);
	}

}

void MotorA::begin()
{
	HAL_TIM_PWM_Start(Motorhandler,TIM_CHANNEL_1) ;       //HAL‚ÌŽd—l
			HAL_GPIO_WritePin(direA_GPIO_Port,direA_Pin,GPIO_PIN_RESET);

}

void MotorA::mbreak()
{
	__HAL_TIM_SetCompare(Motorhandler,TIM_CHANNEL_1,map(0,0,100,0,999));
	HAL_GPIO_WritePin(direA_GPIO_Port,direA_Pin,GPIO_PIN_RESET);
}
/*
void MotorA::stop()
{
	__HAL_TIM_SetCompare(htim1,TIM_CHANNEL_1,0);
		HAL_GPIO_WritePin(direA_GPIO_Port,direA_Pin,GPIO_PIN_RESET);
}
*/
void MotorA::setvelocity(float v)
{
	this->setDuty(map(v,-max_rad,max_rad,-100,100));
}
