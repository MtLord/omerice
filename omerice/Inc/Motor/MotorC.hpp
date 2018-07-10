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
	TIM_HandleTypeDef *htim1;
public:
	void setDuty(float d);
	void setvelocity(float v);
	void begin();
	void mbreak();
	//void stop();
	MotorC(TIM_HandleTypeDef *_htim1):htim1(_htim1){};
	~MotorC(){
		mbreak();
	}
};



#endif /* MOTOR_MOTORC_HPP_ */
