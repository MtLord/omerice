/*
 * MotorA.hpp
 *
 *  Created on: 2018/05/27
 *      Author: 裕汰
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
	void setvelocity(float v);//角速度を入力するとdutyに変換してセットする
	void begin();
	void mbreak();//機体が止まって動かなくなる
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
