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


extern  Robot *Robo;
extern  PS3controller *ps3;
void Application::Debug1()
{
	 game.PIDtheta.set_gain(0.7,0.002,0);
		 game.PIDx.set_gain(0.5,0.005,0);
		 game.PIDy.set_gain(0.5,0.005,0);
		 game.GOPosition(0,76,0);

}
void Application::Debug2(){
	 game.PIDtheta.set_gain(0.7,0,0);
			 game.PIDx.set_gain(0.4,0.0005,0);
			 game.PIDy.set_gain(0.4,0.0005,0);
			 game.GOPosition(60,76,0);
}
void Application::Debug3(){
	 game.PIDtheta.set_gain(0.7,0,0);
				 game.PIDx.set_gain(0.3,0.01,0);
				 game.PIDy.set_gain(0.3,0.01,0);
				 game.GOPosition(60,190,0);
}
void Application::gogachiasariokiba(int i)
{
	float t=i/200;
	 game.PIDtheta.set_gain(0.7,0,0);
	 game.PIDx.set_gain(0.7,0,0);
	 game.PIDy.set_gain(0.7,0,0);
	 game.GOPosition(bezierPX.bezier3(22.5,23,99.4,99.4,t),bezierPY.bezier3(22.5,89,60,200,t),0);

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
	 game.PIDtheta.set_gain(0.7,0,0);
	 game.PIDx.set_gain(0.7,0,0);
	 game.PIDy.set_gain(0.7,0,0);
	ps3->cannode->Receeive();
	game.GOPosition(map(ps3->ANALOG_LEFT_X()-0x80,-100,100,-0x80,0xff),map(ps3->ANALOG_LEFT_Y()-0x80,-100,100,-0x80,0xff),
			map(ps3->ANALOG_RIGHT_X()-0x80,-100,100,-0x80,0xff));
	ps3->cannode->Sendreqest();
}

Application::Application()
{
	Robo->loca.Setshitf_X(13);
	Robo->loca.Setshift_y(2);
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
