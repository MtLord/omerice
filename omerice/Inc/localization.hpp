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
#include "encoder/encoderA.hpp"
#include "encoder/encoderD.hpp"
#include "gyro/L3GD20.hpp"
#include "math.h"

#define Xencoder 0
#define Yencoder 1
class localization
{
	float radias;
	float ShiftY;
	float ShiftX;
	float initX;
	float initY;
	float delta=0;
	Gyro *GYRO;
	encoderA *enA;
	encoderD *enD;
	 double point[2]={0,0};
	 double b_dist[2];
	 double hensa[2];
public:

	void begin(encoderA *A,encoderD *D,Gyro *gyro)
	{
		radias=4.8;
		this->enA=A;
		this->enD=D;
		this->GYRO=gyro;
	}
	void integralcount()
	{
		double dist[2]={enA->getdistance(),enD->getdistance()};

		hensa[Xencoder]=dist[Xencoder]-b_dist[Xencoder];
		hensa[1]=dist[Yencoder]-b_dist[Yencoder];
		point[Xencoder]+=(hensa[Xencoder]*cos(GYRO->Zrad())-hensa[Yencoder]*sin(GYRO->Zrad()))*radias;
		point[Yencoder]+=(hensa[Yencoder]*cos(GYRO->Zrad())+hensa[Xencoder]*sin(GYRO->Zrad()))*radias;
		b_dist[Xencoder]=dist[Xencoder];
		b_dist[Yencoder]=dist[Yencoder];
	}
	 double GetX()
	{
		return initX+cos(GYRO->Zrad())*(cos(delta)*(point[Xencoder]-ShiftX)-sin(delta)*(point[Yencoder]-ShiftY))
				-sin(GYRO->Zrad())*(sin(delta)*(point[Xencoder]-ShiftX)+cos(delta)*(point[Yencoder]-ShiftY));
	}
	 double GetY()
	{
		return initY+sin(GYRO->Zrad())*(cos(delta)*(point[Xencoder]-ShiftX)-sin(delta)*(point[Yencoder]-ShiftY))
				+cos(GYRO->Zrad())*(sin(delta)*(point[Xencoder]-ShiftX)+cos(delta)*(point[Yencoder]-ShiftY));
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
		enA->Setdiameter(d);
		enD->Setdiameter(d);
	}
	void Setpulse(float P)
	{
		enA->Setpulse(P);
		enD->Setpulse(P);
	}
	void Setinitposition(float x,float y)
	{
		initX=x;
		initY=y;
	}
	void Setdelta(float delta)
	{
		this->delta=delta;
	}
	void printcount()
	{
		printf("encodera:%f encoderd:%f\n\r",this->GetX(),this->GetY());
	}
	void printdistance(){
		printf("GetX:%lf GetY:%lf",enA->getdistance(),enD->getdistance());
	}
};


//y38.65 x60

#endif /* APPLICATION_LOCALIZATON_HPP_ */
