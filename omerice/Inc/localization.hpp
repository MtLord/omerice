/*
 * Get_position.hpp
 *
 *  Created on: 2018/08/28
 *      Author: 裕汰
 */

#ifndef APPLICATION_LOCALIZATON_HPP_
#define APPLICATION_LOCALIZATON_HPP_
#include "Robot.hpp"
#include "math.h"
#include "encoder/encoders.hpp"

#include "gyro/L3GD20.hpp"
#include "math.h"


class localization
{
	float diameter=4.8;
	uint16_t pulse=2048;
	int flag;
	float ShiftY=0;
	float ShiftX=0;

	Gyro *GYRO;
	encoders *enc;
	encoderA *ena;
	encoderD *end;
	 const double pi=3.14159265358979323846264338;
public:

	void begin(encoders *_enc,Gyro *gyro,encoderA *_ena,encoderD *_end)
	{
		this->enc=_enc;
		this->GYRO=gyro;
		ena=_ena;
		end=_end;
	}

	 double GetX()
	{
		return ((double)ena->getcount()*pi*diameter)/((double)pulse*4)-ShiftX;
	}
	 double GetY()
	{
		 return ((double)end->getcount()*pi*diameter)/((double)pulse*4)-ShiftY;
	}
	 float GetZvel(){
		return GYRO->Zradvel();
	}
	 float GetYaw(){
		return GYRO->Zrad();
	}

	void Setshitf_X(float x)//機体中心からのズレを記述
	{
		ShiftX=x;
	}
	void Setshift_y(float y){
		ShiftY=y;
	}

	void Setdiameter(float d)
	{
		 diameter=d;

	}
	void Setpulse(int P)
	{
		 pulse=P;
	}




};


//y38.65 x60

#endif /* APPLICATION_LOCALIZATON_HPP_ */
