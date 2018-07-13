/*
 * ServoB.cpp
 *
 *  Created on: 2018/07/12
 *      Author: —T‘¿
 */
#include "ServoB.hpp"

void ServoB::begin(){
	HAL_TIM_PWM_Start(htim2, TIM_CHANNEL_2);
}

void ServoB::set_pulse(float pulse){
	__HAL_TIM_SetCompare(htim2,TIM_CHANNEL_2,map(pulse,0,100,0,9999));
}

