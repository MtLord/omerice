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
	float ShiftY;
	float ShiftX;
	float initX=30;
	float initY=0;
	Gyro *GYRO;
	encoders *enc;
	 double point[2]={0,0};
	 double b_dist[2];
	 double hensa[2];
	 const double pi=3.14159265358979323846264338;
public:

	void begin(encoders *_enc,Gyro *gyro)
	{
		this->enc=_enc;
		this->GYRO=gyro;
	}

	 double GetX()
	{
		return -((double)enc->GetXcount()*pi*diameter)/((double)pulse*4)+ShiftX*cos(this->GetYaw()) - ShiftY*sin(this->GetYaw())-ShiftX+initX;//フィールド座標系に変換
	}
	 double GetY()
	{
		 return ((double)enc->GetYcount()*pi*diameter)/((double)pulse*4)+ShiftY*cos(this->GetYaw()) + ShiftX*sin(this->GetYaw())-ShiftY;
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
	void Setinitposition(float x,float y)
	{
		initX=x;
		initY=y;
	}

	void printcount()
	{
		printf("encodera:%f encoderd:%f flag:%f\n\r",this->GetX(),this->GetY(),this->GetYaw());
	}

};


//y38.65 x60

#endif /* APPLICATION_LOCALIZATON_HPP_ */
