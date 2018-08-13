/*
 * MotorE.hpp
 *
 *  Created on: 2018/08/10
 *      Author: —T‘¿
 */

#ifndef MOTOR_MOTORE_HPP_
#define MOTOR_MOTORE_HPP_
#include "Motors.hpp"

class MotorE:public Motors
{
private:
	TIM_HandleTypeDef *Motorhandler;
public:
	void setDuty(float d);
	void setvelocity(float v);
	void begin();
	void mbreak();
	//void stop();disable
	MotorE(TIM_HandleTypeDef *_htim1):Motorhandler(_htim1)
	{
		this->begin();
	};
	~MotorE(){
		mbreak();
	}
};



#endif /* MOTOR_MOTORE_HPP_ */
