/*
 * excuteApplication.hpp
 *
 *  Created on: 2018/08/29
 *      Author: 裕汰
 */

#ifndef APPLICATION_EXCUTEAPPLICATION_HPP_
#define APPLICATION_EXCUTEAPPLICATION_HPP_

#include <application/move.hpp>
#include "app_y/bezier.hpp"
#include "PS3/PS3class.hpp"
class Application
{
	float manualX=0;
	float manualY=0;
	double manualtheta=0;
	float time;
	float s;
	float c;
	PS3controller *ps3;
protected:
	const float PI=3.14159265;

	 float t=0;
	 bezier bezierPX;
	 bezier bezierPY;
	 long map(float x, long in_min, long in_max, long out_min, long out_max)
	 	{
	 		return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
	 	}

public:
	 move game;
	 Application(PS3controller *_ps3);
	 Application();
	 void Debug1();
	 void Debug2();
	 void Debug3();
	 void Debug4();
	 virtual ~Application(){}
	 int BuleButton();
	 virtual void manualcontrol();
	 virtual void gogachiasariokiba(int i);
	 virtual void gogachiasari(int i);
	 virtual void gogoalarea(int i);
};

class ApplicationBlue:public Application //bluezon
{
public:
	using Application::Application;
	virtual ~ApplicationBlue(){}
	 virtual void gogachiasariokiba(int i);
	 virtual void gogachiasari(int i);
	 virtual void gogoalarea(int i);
};


enum class state:unsigned int
{
	CASE_WAIT,//スタートボタンが押されるまで待機
	gogachiasariokiba,
	gogachiasari,
	gogoalarea
};



#endif /* APPLICATION_EXCUTEAPPLICATION_HPP_ */
