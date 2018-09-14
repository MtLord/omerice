/*
 * Robot.hpp
 *
 *  Created on: 2018/06/25
 *      Author: —T‘¿
 */

#ifndef ROBOT_HPP_
#define ROBOT_HPP_
/*******include heders*******************/
#include <gyro/L3GD20.hpp>
#include "encoder/encoderA.hpp"
#include "encoder/encoderB.hpp"
#include "encoder/encoderC.hpp"
#include "encoder/encoderD.hpp"
#include "Motor/MotorA.hpp"
#include "Motor/MotorB.hpp"
#include "Motor/MotorC.hpp"
#include "Motor/MotorD.hpp"
#include "Motor/MotorE.hpp"
#include "Motor/MotorF.hpp"

#include "servo/ServoA.hpp"
#include "servo/ServoB.hpp"
#include "localization.hpp"
#include "Aircylinder/aircylinder1.hpp"
#include "Aircylinder/aircylinder2.hpp"
#include "Aircylinder/aircylinder3.hpp"
#include "Aircylinder/aircylinder4.hpp"
#include "Aircylinder/aircylinder5.hpp"
#include "adconvert/adc_class.hpp"
/****************************************/
class Robot
{
	private:


public:
	MotorA m_a;
		MotorB m_b;
		MotorC m_c;
		MotorD m_d;
		MotorE m_e;
		MotorF m_f;
	encoderA en_a;
	encoderD en_d;
	encoderB en_b;
	encoderC en_c;
	encoders enc;
	localization loca;
	Sensor sensor;
	air1 Air1;
	air2 Air2;
	air3 Air3;
	air4 Air4;
	air5 Air5;

	ServoB servob;
	ServoA servoa;
	Gyro gyro;

	Robot(SPI_HandleTypeDef *_hspi3,TIM_HandleTypeDef *_htim1,
			TIM_HandleTypeDef *_htim2,TIM_HandleTypeDef *_htim3,TIM_HandleTypeDef *_htim4,TIM_HandleTypeDef *_htim5,TIM_HandleTypeDef *htim8,TIM_HandleTypeDef *_htim12,
			ADC_HandleTypeDef *_adchadndle)
			:en_a(_htim2),en_b(_htim3),en_c(_htim4),en_d(_htim5),m_a(_htim1),m_b(_htim1),m_c(_htim1),m_d(_htim1),m_e(_htim12),m_f(_htim12),
			 gyro(_hspi3),servoa(htim8),servob(htim8),sensor(_adchadndle)
	{
		loca.begin(&enc,&gyro);

		en_b.begin(&m_c,&m_d,&m_e,&m_f);
		en_c.begin(&m_d,&m_e,&m_f);

	}

};



#endif /* ROBOT_HPP_ */
