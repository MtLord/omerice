/*
 * MotorD.hpp
 *
 *  Created on: 2018/08/08
 *      Author: —T‘¿
 */

#ifndef MOTOR_MOTORD_HPP_
#define MOTOR_MOTORD_HPP_

#include "Motors.hpp"

class MotorD:public Motors
{
private:
	TIM_HandleTypeDef *Motorhandler;
public:
	void setDuty(float d);
	void setvelocity(float v);
	void begin();
	void mbreak();
	//void stop();disable
	MotorD(TIM_HandleTypeDef *_htim1):Motorhandler(_htim1)
	{
		this->begin();
	};
	~MotorD(){
		mbreak();
	}
};



#endif /* MOTOR_MOTORD_HPP_ */
