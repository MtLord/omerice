/*
 * MotorC.cpp
 *
 *  Created on: 2018/07/01
 *      Author: —T‘¿
 */
#include "MotorC.hpp"

void MotorC::setDuty(float d)
{
	//__HAL_TIM_SetCompare(htim1,TIM_CHANNEL_1,map(d,0,100,0,999));
	if(d>=0)
	{
		__HAL_TIM_SetCompare(Motorhandler,TIM_CHANNEL_3,map(d,0,100,0,999));
					HAL_GPIO_WritePin(direC_GPIO_Port,direC_Pin,GPIO_PIN_RESET);
	}

	else if(d<0)
	{
		__HAL_TIM_SetCompare(Motorhandler,TIM_CHANNEL_3,map(-d,0,100,0,999));
			HAL_GPIO_WritePin(direC_GPIO_Port,direC_Pin,GPIO_PIN_SET);
	}

}

void MotorC::begin()
{
	if (HAL_TIM_PWM_Start(Motorhandler,TIM_CHANNEL_3) != HAL_OK)       //HAL‚ÌŽd—l
			{
			  Error_Handler();
			}
			HAL_GPIO_WritePin(direC_GPIO_Port,direC_Pin,GPIO_PIN_RESET);

}

void MotorC::mbreak()
{
	__HAL_TIM_SetCompare(Motorhandler,TIM_CHANNEL_3,map(0,0,100,0,999));
	HAL_GPIO_WritePin(direC_GPIO_Port,direC_Pin,GPIO_PIN_RESET);
}
/*
void MotorC::stop()
{
	__HAL_TIM_SetCompare(htim1,TIM_CHANNEL_3,map(0,0,100,0,999));
		HAL_GPIO_WritePin(direC_GPIO_Port,direC_Pin,GPIO_PIN_RESET);
}
*/
void MotorC::setvelocity(float v)
{
	this->setDuty(map(v,-max_rad,max_rad,-100,100));
}




