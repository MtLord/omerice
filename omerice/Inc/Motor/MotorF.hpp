/*
 * MotorF.hpp
 *
 *  Created on: 2018/08/10
 *      Author: —T‘¿
 */

#ifndef MOTOR_MOTORF_HPP_
#define MOTOR_MOTORF_HPP_
#include "Motors.hpp"

class MotorF:public Motors
{
private:
	TIM_HandleTypeDef *Motorhandler;
public:
	void setDuty(float d);
	void setvelocity(float v);
	void begin();
	void mbreak();
	//void stop();disable
	MotorF(TIM_HandleTypeDef *_htim1):Motorhandler(_htim1)
	{
		this->begin();
	};
	~MotorF(){
		mbreak();
	}
};




#endif /* MOTOR_MOTORF_HPP_ */
