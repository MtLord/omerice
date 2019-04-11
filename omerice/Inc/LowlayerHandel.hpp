/*
 * Robot.hpp
 *
 *  Created on: 2018/06/25
 *      Author: —T‘¿
 */

#ifndef LOWLAYERHANDEL_HPP_
#define LOWLAYERHANDEL_HPP_
/*******include heders*******************/

#include "tim.h"
#include "adc.h"
#include "encoder/RotaryEncoder.hpp"
#include "Motor/MotorA.hpp"
#include "Motor/MotorB.hpp"
#include "Motor/MotorC.hpp"
#include "Motor/MotorD.hpp"
#include "Motor/MotorE.hpp"
#include "Motor/MotorF.hpp"



#include "Aircylinder/aircylinder1.hpp"
#include "Aircylinder/aircylinder2.hpp"
#include "Aircylinder/aircylinder3.hpp"
#include "Aircylinder/aircylinder4.hpp"
#include "Aircylinder/aircylinder5.hpp"
#include "adconvert/adc_class.hpp"
/****************************************/
struct LowlayerHandleTypdef
{
	private:


public:
	MotorA m_a;
	MotorB m_b;
	MotorC m_c;
	MotorD m_d;
	MotorE m_e;
	MotorF m_f;
	Encoder en_a,en_d;
	IntEncoder en_b,en_c;
	Sensor sensor;
	air1 Air1;
	air2 Air2;
	air3 Air3;
	air4 Air4;
	air5 Air5;
	//Gyro gyro;

	LowlayerHandleTypdef():en_a(&htim2),en_b(&htim3),en_c(&htim4),en_d(&htim5),m_a(&htim1)
		,m_b(&htim1),m_c(&htim1),m_d(&htim1),m_e(&htim12),m_f(&htim12),sensor(&hadc1)


	{

	}

};



#endif /* LOWLAYERHANDEL_HPP_ */
