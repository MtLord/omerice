/*
 * MotorF.cpp
 *
 *  Created on: 2018/08/10
 *      Author: —T‘¿
 */
#include "MotorF.hpp"
#include "main.h"
void MotorF::setDuty(float d)
{
	//__HAL_TIM_SetCompare(htim1,TIM_CHANNEL_1,map(d,0,100,0,999));
	if(d>=0)
	{
		__HAL_TIM_SetCompare(Motorhandler,TIM_CHANNEL_2,map(d,0,100,0,999));
					HAL_GPIO_WritePin(direF_GPIO_Port,direF_Pin,GPIO_PIN_RESET);
	}

	else if(d<0)
	{
		__HAL_TIM_SetCompare(Motorhandler,TIM_CHANNEL_2,map(-d,0,100,0,999));
			HAL_GPIO_WritePin(direF_GPIO_Port,direF_Pin,GPIO_PIN_SET);
	}

}

void MotorF::begin()
{
	if (HAL_TIM_PWM_Start(Motorhandler,TIM_CHANNEL_2) != HAL_OK)       //HAL‚ÌŽd—l
			{
			  Error_Handler();
			}
			HAL_GPIO_WritePin(direF_GPIO_Port,direF_Pin,GPIO_PIN_RESET);

}

void MotorF::mbreak()
{
	__HAL_TIM_SetCompare(Motorhandler,TIM_CHANNEL_2,map(0,0,100,0,999));
	HAL_GPIO_WritePin(direF_GPIO_Port,direF_Pin,GPIO_PIN_RESET);
}
/*
void MotorC::stop()
{
	__HAL_TIM_SetCompare(htim1,TIM_CHANNEL_3,map(0,0,100,0,999));
		HAL_GPIO_WritePin(direC_GPIO_Port,direC_Pin,GPIO_PIN_RESET);
}
*/
void MotorF::setvelocity(float v)
{
	this->setDuty(map(v,-max_rad,max_rad,-100,100));
}




