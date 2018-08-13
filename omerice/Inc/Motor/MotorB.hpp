/*
 * MotorB.hpp
 *
 *  Created on: 2018/05/27
 *      Author: �T��
 */

#ifndef LIBRARY_MOTOR_INCLUDE_MOTORB_HPP_
#define LIBRARY_MOTOR_INCLUDE_MOTORB_HPP_

#include "Motors.hpp"

class MotorB:public Motors
{
private:
	TIM_HandleTypeDef *Motorhandler;
public:
	void setDuty(float d);
	void setvelocity(float v);
	void begin();
	void mbreak();
	//void stop();disable
	MotorB(TIM_HandleTypeDef *_htim1):Motorhandler(_htim1)
	{
		this->begin();
	};
	~MotorB(){
		mbreak();
	}
};




#endif /* LIBRARY_MOTOR_INCLUDE_MOTORB_HPP_ */
