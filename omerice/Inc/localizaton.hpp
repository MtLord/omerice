/*
 * Get_position.hpp
 *
 *  Created on: 2018/08/28
 *      Author: —T‘¿
 */

#ifndef APPLICATION_LOCALIZATON_HPP_
#define APPLICATION_LOCALIZATON_HPP_
#include "Robot.hpp"
#include "math.h"
#include "encoder/encoderA.hpp"
#include "encoder/encoderD.hpp"
#include "gyro/L3GD20.hpp"


class localization
{
	float ShiftY;
	float ShiftX;
	encoderA *enA;
	encoderD *enD;
	Gyro *GYRO;



public:
	localization(encoderA *enA,encoderD *enD,Gyro *gyro):enA(enA),enD(enD),GYRO(gyro)
	{

	}
	virtual double GetX()
	{
		return -1*enA->getdistance()-ShiftY*sin(GYRO->Zrad())-ShiftX*cos(GYRO->Zrad())+ShiftX;
	}
	virtual double GetY()
	{
		return enD->getdistance()+ShiftX*sin(GYRO->Zrad())+ShiftY*cos(GYRO->Zrad());
	}
	virtual float GetZvel(){
		return GYRO->Zradvel();
	}
	virtual float GetYaw(){
		return GYRO->Zrad();
	}
	//virtual ~localization();
	void Setshitf_X(float x){
		ShiftX=x;
	}
	void Setshift_y(float y){
		ShiftY=y;
	}
};


//y38.65 x60

#endif /* APPLICATION_LOCALIZATON_HPP_ */
