/*
 * MotorE.cpp
 *
 *  Created on: 2018/08/10
 *      Author: —T‘¿
 */
#include "MotorE.hpp"
#include "main.h"
void MotorE::setDuty(float d)
{
	//__HAL_TIM_SetCompare(htim1,TIM_CHANNEL_1,map(d,0,100,0,999));
	if(d>=0)
	{
		__HAL_TIM_SetCompare(Motorhandler,TIM_CHANNEL_1,map(d,0,100,0,999));
					HAL_GPIO_WritePin(direE_GPIO_Port,direE_Pin,GPIO_PIN_RESET);
	}

	else if(d<0)
	{
		__HAL_TIM_SetCompare(Motorhandler,TIM_CHANNEL_1,map(-d,0,100,0,999));
			HAL_GPIO_WritePin(direE_GPIO_Port,direE_Pin,GPIO_PIN_SET);
	}

}

void MotorE::begin()
{
	if (HAL_TIM_PWM_Start(Motorhandler,TIM_CHANNEL_1) != HAL_OK)       //HAL‚ÌŽd—l
			{
			  Error_Handler();
			}
			HAL_GPIO_WritePin(direE_GPIO_Port,direE_Pin,GPIO_PIN_RESET);

}

void MotorE::mbreak()
{
	__HAL_TIM_SetCompare(Motorhandler,TIM_CHANNEL_1,map(0,0,100,0,999));
	HAL_GPIO_WritePin(direE_GPIO_Port,direE_Pin,GPIO_PIN_RESET);
}
/*
void MotorC::stop()
{
	__HAL_TIM_SetCompare(htim1,TIM_CHANNEL_3,map(0,0,100,0,999));
		HAL_GPIO_WritePin(direC_GPIO_Port,direC_Pin,GPIO_PIN_RESET);
}
*/
void MotorE::setvelocity(float v)
{
	this->setDuty(map(v,-max_rad,max_rad,-100,100));
}


