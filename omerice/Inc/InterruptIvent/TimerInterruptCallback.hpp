
#ifndef __TIMERINTERRUPTCALLBACK__
#define __TIMERINTERRUPTCALLBACK__
#include "stm32f4xx_hal.h"
//#include "application/excuteApplication.hpp"
//if you use different interrupt cycle,you set interrupt cycle  each other
class TimerInterrupt1
{
private:
	float period=0.001;//äÑÇËçûÇ›é¸ä˙
	unsigned short counterperiod;
	unsigned short Prescaler=0;
	float ajustperiod;

public:
	TimerInterrupt1(TIM_HandleTypeDef *timhandle)
	{
		/**************initialization******************/
		while(ajustperiod!=period)
		{
			Prescaler++;
		for(counterperiod=0;counterperiod<65535;counterperiod++)
		{
			ajustperiod=((float)Prescaler*(float)(counterperiod+1))/40000000;
			if(ajustperiod==period)
			{
				break;
			}
		}
		}
		timhandle->Init.Prescaler=Prescaler-1;
		timhandle->Init.Period=counterperiod;

		/***********************************************/
	}
	void TIMinterrupt()
	{
		/*****interrupt ivent here*************/




		/*****************************************/
	}
	void Setperiod(float p)
	{
		period=p;
	}
};

class TimerInterrupt2
{
private:

public:
	TimerInterrupt2(TIM_HandleTypeDef *timhandle)
	{

	}
	void TIMinterrupt(){
		/*****interrupt ivent here*************/




		/*****************************************/
	}

};



class TimerInterrupt3
{
private:

public:
	TimerInterrupt3(TIM_HandleTypeDef *timhandle)
	{

	}
	void TIMinterrupt(){
		/*****interrupt ivent here*************/




		/*****************************************/
	}

};

class TimerInterrupt4
{
private:

public:
	TimerInterrupt4(TIM_HandleTypeDef *timhandle)
	{

	}
	void TIMinterrupt(){
		/*****interrupt ivent here*************/




		/*****************************************/
	}

};

class TimerInterrupt5
{
private:

public:
	TimerInterrupt5(TIM_HandleTypeDef *timhandle)
	{

	}
	void TIMinterrupt(){
		/*****interrupt ivent here*************/




		/*****************************************/
	}

};





//7 10 11 13 14



#endif
