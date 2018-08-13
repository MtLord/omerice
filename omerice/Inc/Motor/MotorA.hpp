/*
 * MotorA.hpp
 *
 *  Created on: 2018/05/27
 *      Author: —T‘¿
 */

#ifndef LIBRARY_MOTOR_INCLUDE_MOTORA_HPP_
#define LIBRARY_MOTOR_INCLUDE_MOTORA_HPP_

#include "Motors.hpp"
#include "main.h"
class MotorA:public Motors
{
private:

	TIM_HandleTypeDef *Motorhandler;
public:
	void setDuty(float d);
	void setvelocity(float v);//Šp‘¬“x‚ð“ü—Í‚·‚é‚Æduty‚É•ÏŠ·‚µ‚ÄƒZƒbƒg‚·‚é
	void begin();
	void mbreak();//‹@‘Ì‚ªŽ~‚Ü‚Á‚Ä“®‚©‚È‚­‚È‚é
	//void stop();//disable
	MotorA(TIM_HandleTypeDef *_htim1):Motorhandler(_htim1)
	{
		this->begin();
	}
	~MotorA(){
		this->mbreak();
	}
};





#endif /* LIBRARY_MOTOR_INCLUDE_MOTORA_HPP_ */
