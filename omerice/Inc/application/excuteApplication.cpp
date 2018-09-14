/*
 * excuteApplication.cpp
 *
 *  Created on: 2018/08/20
 *      Author: —T‘¿
 */

#include "excuteApplication.hpp"
#include "pid.hpp"
#include "Robot.hpp"
#include "PS3/PS3class.hpp"
#include "CAN/CAN.hpp"
#include "math.h"
//extern can_bus *canhadle;
extern  Robot *Robo;
void Application::Debug1()
{
	 game.PIDtheta.set_gain(0.5,0,0);
			 game.PIDx.set_gain(1,0,0);
			 game.PIDy.set_gain(1,0,0);
			 time+=0.01;
		 game.GOPosition(30*cos(PI*time),30*sin(PI*time),0);
}

void Application::Debug2()
{
	 game.PIDtheta.set_gain(0.5,0,0);
	game.PIDx.set_gain(1,0,0);
	game.PIDy.set_gain(1,0,0);
	game.GOPosition(0,0,PI);

}
void Application::Debug3()
{
	 game.PIDtheta.set_gain(0.5,0,0);
	game.PIDx.set_gain(1,0,0);
	game.PIDy.set_gain(1,0,0);
	game.GOPosition(0,0,0);

}

void Application::Debug4()
{
	 game.PIDtheta.set_gain(1,0,0);
		game.PIDx.set_gain(1,0,0);
		game.PIDy.set_gain(1,0,0);
		game.GOPosition(0,0,0);

}
void Application::gogachiasariokiba(int i)
{
	float t=i/200;
	 game.PIDtheta.set_gain(1.5,0,0);
	 game.PIDx.set_gain(5,0.01,0);
	 game.PIDy.set_gain(5,0.01,0);
	 game.GOPosition(bezierPX.bezier3(0,23,99.4,99.4,t),bezierPY.bezier3(0,89,60,200,t),0);

}
void Application::gogachiasari(int i)
{
	float t=i/200;
		 game.PIDtheta.set_gain(0.7,0,0);
		 game.PIDx.set_gain(0.7,0,0);
		 game.PIDy.set_gain(0.7,0,0);
		game.GOPosition(bezierPX.bezier3(99.4,30,30,110,t),bezierPY.bezier3(200,200,300,275,t),-PI/2);
}
void Application::gogoalarea(int i)
{

	float t=i/200;
		 game.PIDtheta.set_gain(0.7,0,0);
		 game.PIDx.set_gain(0.7,0,0);
		 game.PIDy.set_gain(0.7,0,0);
			game.GOPosition(bezierPX.bezier3(87.5,0,7.5,101.3,t),bezierPY.bezier3(275,275,200,174.5,t),0);
}
void Application::manualcontrol()
{
	 game.PIDtheta.set_gain(1 ,0,0);
	 game.PIDx.set_gain(35,0,0);
	 game.PIDy.set_gain(35,0,0);

	 //ps3->cannode->Sendreqest();
	 float con_x = (ps3->ANALOG_LEFT_X() - 127) /127;
	 float con_y = (ps3->ANALOG_LEFT_Y() - 127) /127;
	 float con_yaw = (ps3->ANALOG_RIGHT_X() - 127) /127;
	 float terget_x = Robo->loca.GetX() + con_x;
	 float terget_y = Robo->loca.GetY() + con_y;
	 float terget_yaw  = Robo->loca.GetYaw() - con_yaw;
	 //printf("x:%f y:%f yaw:%f\n\r",Robo->loca.GetX(),Robo->loca.GetY(),Robo->loca.GetYaw());

	game.GOPosition((ps3->ANALOG_LEFT_X() - 127)/3,(ps3->ANALOG_LEFT_Y() - 127)/3,-con_yaw);
	//printf("%f %f %f\n\r",manualX,manualY,manualtheta);

}

Application::Application(PS3controller *_ps3)
{
	ps3=_ps3;
	Robo->loca.Setshitf_X(13);// 13 -2
	Robo->loca.Setshift_y(-2);
	Robo->loca.Setdiameter(4.8);
	Robo->loca.Setpulse(1024);

}
Application::Application(){

		Robo->loca.Setshitf_X(13);// 13 -2
		Robo->loca.Setshift_y(-2);
		Robo->loca.Setdiameter(4.8);
		Robo->loca.Setpulse(1024);
}
int Application::BuleButton()
{
	return HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_13);
}

void ApplicationBlue::gogachiasariokiba(int i)
{
	float t=i/200;
		 game.PIDtheta.set_gain(0,0,0);
		 game.PIDx.set_gain(0,0,0);
		 game.PIDy.set_gain(0,0,0);
			game.GOPosition(bezierPX.bezier3(22.5,23,99.4,99.4,t),bezierPY.bezier3(22.5,89,60,200,t),0);
}
void ApplicationBlue::gogachiasari(int i)
{
	float t=i/200;
			 game.PIDtheta.set_gain(0,0,0);
			 game.PIDx.set_gain(0,0,0);
			 game.PIDy.set_gain(0,0,0);
			game.GOPosition(bezierPX.bezier3(99.4,30,30,110,t),bezierPY.bezier3(200,200,300,275,t),-PI/2);
}

void ApplicationBlue::gogoalarea(int i)
{
	float t=i/200;
			 game.PIDtheta.set_gain(0,0,0);
			 game.PIDx.set_gain(0,0,0);
			 game.PIDy.set_gain(0,0,0);
				game.GOPosition(bezierPX.bezier3(87.5,0,7.5,101.3,t),bezierPY.bezier3(275,275,200,174.5,t),0);
}
