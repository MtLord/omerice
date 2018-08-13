/*
 * MotorC.hpp
 *
 *  Created on: 2018/07/01
 *      Author: —T‘¿
 */

#ifndef MOTOR_MOTORC_HPP_
#define MOTOR_MOTORC_HPP_


#include "Motors.hpp"

class MotorC:public Motors
{
private:
	TIM_HandleTypeDef *Motorhandler;
public:
	void setDuty(float d);
	void setvelocity(float v);
	void begin();
	void mbreak();
	//void stop();
	MotorC(TIM_HandleTypeDef *_htim1):Motorhandler(_htim1)
	{
		this->begin();
	};
	~MotorC(){
		mbreak();
	}
};



#endif /* MOTOR_MOTORC_HPP_ */
