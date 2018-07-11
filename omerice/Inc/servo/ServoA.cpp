/*
 * ServoA.cpp
 *
 *  Created on: 2018/05/28
 *      Author: —T‘¿
 */
#include "ServoA.hpp"

void ServoA::set_pulse(float pulse)
{
	__HAL_TIM_SetCompare(htim2,TIM_CHANNEL_1,map(pulse,0,100,0,9999));
}

void ServoA::begin()
{
	HAL_TIM_PWM_Start(htim2, TIM_CHANNEL_1);
}
/*
void ServoA::set_angle(float ag){
	__HAL_TIM_SetCompare(htim2,TIM_CHANNEL_3,map(ag,0,180,servo_low,servo_hight));
}
*/


