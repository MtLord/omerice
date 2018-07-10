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

	TIM_HandleTypeDef *htim1;
public:
	void setDuty(float d);
	void setvelocity(float v);//角速度を入力するとdutyに変換してセットする
	void begin();
	void mbreak();//機体が止まって動かなくなる
	//void stop();//disable
	MotorA(TIM_HandleTypeDef *_htim1):htim1(_htim1){};
	~MotorA(){
		this->mbreak();
	}
};





#endif /* LIBRARY_MOTOR_INCLUDE_MOTORA_HPP_ */
