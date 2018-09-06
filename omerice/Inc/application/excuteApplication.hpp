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
class Application
{
protected:
	const float PI=3.14159265;
	move game;
	 float t=0;
	 bezier bezierPX;
	 bezier bezierPY;
	 long map(float x, long in_min, long in_max, long out_min, long out_max)
	 	{
	 		return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
	 	}

public:
	 Application();
	 void Debug();
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
