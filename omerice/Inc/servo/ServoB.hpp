/*
 * ServoB.hpp
 *
 *  Created on: 2018/07/12
 *      Author: —T‘¿
 */

#ifndef SERVO_SERVOB_HPP_
#define SERVO_SERVOB_HPP_
#include "Servos.hpp"

class ServoB:public serovo
{
	TIM_HandleTypeDef *htim2;

public:
	ServoB(TIM_HandleTypeDef *_htim8):htim2(_htim8){}
	void begin();
	void set_pulse(float pulse);
	//void set_angle(float ag);–¢ŽÀ‘•

};



#endif /* SERVO_SERVOB_HPP_ */
