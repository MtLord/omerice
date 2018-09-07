/*
 * encoders.cpp
 *
 *  Created on: 2018/09/07
 *      Author: —T‘¿
 */
#include "encoders.hpp"
#include "Robot.hpp"
extern Robot *Robo;
#define Xencoder 0
#define Yencoder 1

void encoders::countintegral()
{
		count[0]=Robo->en_a.getcount();
		count[1]=Robo->en_d.getcount();
		hensa[0]=count[0]-b_count[0];
		hensa[1]=count[1]-b_count[1];
		point[Xencoder]+=(hensa[Xencoder]*cos(Robo->gyro.Zrad())-hensa[Yencoder]*sin(Robo->gyro.Zrad()));
		point[Yencoder]+=(hensa[Yencoder]*cos(Robo->gyro.Zrad())+hensa[Xencoder]*sin(Robo->gyro.Zrad()));
		b_count[0]=count[0];
		b_count[1]=count[1];
}
