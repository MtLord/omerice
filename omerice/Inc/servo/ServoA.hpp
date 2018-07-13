/*
 * ServoA.hpp
 *
 *  Created on: 2018/05/28
 *      Author: —T‘¿
 */

#ifndef SERVO_SERVOA_HPP_
#define SERVO_SERVOA_HPP_
#include "Servos.hpp"

class ServoA:public serovo
{
	TIM_HandleTypeDef *htim2;

public:
	ServoA(TIM_HandleTypeDef *_htim8):htim2(_htim8){}
	void begin();
	void set_pulse(float pulse);
	//void set_angle(float ag);–¢ŽÀ‘•

};




#endif /* SERVO_SERVOA_HPP_ */
