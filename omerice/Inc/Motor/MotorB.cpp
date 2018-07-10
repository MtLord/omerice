/*
f * MotorB.cpp
 *
 *  Created on: 2018/05/27
 *      Author: —T‘¿
 */
#include "MotorB.hpp"

void MotorB::setDuty(float d)
{
	//__HAL_TIM_SetCompare(htim1,TIM_CHANNEL_1,map(d,0,100,0,999));
	if(d>=0)
	{
		__HAL_TIM_SetCompare(htim1,TIM_CHANNEL_2,map(d,0,100,0,999));
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15,GPIO_PIN_RESET);
	}

	else if(d<0)
	{
		__HAL_TIM_SetCompare(htim1,TIM_CHANNEL_2,map(-d,0,100,0,999));
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15,GPIO_PIN_SET);
	}

}

void MotorB::begin()
{
	if (HAL_TIM_PWM_Start(htim1,TIM_CHANNEL_2) != HAL_OK)       //HAL‚ÌŽd—l
			{
			  Error_Handler();
			}
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15,GPIO_PIN_RESET);

}

void MotorB::mbreak()
{
	__HAL_TIM_SetCompare(htim1,TIM_CHANNEL_2,map(0,0,100,0,999));
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15,GPIO_PIN_RESET);
}
/*
void MotorB::stop()
{
	__HAL_TIM_SetCompare(htim1,TIM_CHANNEL_2,map(0,0,100,0,999));
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15,GPIO_PIN_RESET);
}
*/
void MotorB::setvelocity(float v)
{
	this->setDuty(map(v,-max_rad,max_rad,-100,100));
}




