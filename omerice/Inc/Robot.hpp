/*
 * Robot.hpp
 *
 *  Created on: 2018/06/25
 *      Author: óTëø
 */

#ifndef ROBOT_HPP_
#define ROBOT_HPP_
/*******include heders*******************/
#include "encoder/encoderA.hpp"
#include "encoder/encoderB.hpp"
#include "Motor/MotorA.hpp"
#include "Motor/MotorB.hpp"
#include "Motor/MotorC.hpp"
#include "PSpad_data.hpp"
#include "gyro/L3G4200D.hpp"
/****************************************/
class Robot
{
	private:

	 //const float R= 0.10;//É^ÉCÉÑÇÃîºåa
	 //const float T= 0.342; //é‘ïù                            íPà m

public:
	encoderA en_a;
	encoderB en_b;
	MotorA m_a;
	MotorB m_b;
	MotorC m_c;
	PadDataDepot pspad;
	Gyro gyro;
	Robot(SPI_HandleTypeDef *_hspi2,SPI_HandleTypeDef *_hspi3,TIM_HandleTypeDef *_htim1,
			TIM_HandleTypeDef *_htim2,TIM_HandleTypeDef *_htim3,TIM_HandleTypeDef *_htim8)
			:en_a(_htim2,500,5),en_b(_htim3,500,5),m_a(_htim1),m_b(_htim1),m_c(_htim1),pspad(_hspi2),gyro(_hspi3){}

};



#endif /* ROBOT_HPP_ */
