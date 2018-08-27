
#ifndef __TIMERINTERRUPTCALLBACK__
#define __TIMERINTERRUPTCALLBACK__
#include "stm32f4xx_hal.h"

//if you use different interrupt cycle,you set interrupt cycle  each other
class TimerInterrupt1
{
private:

public:
	TimerInterrupt1(TIM_HandleTypeDef *timhandle)
	{
		/**************initialization******************/
		timhandle->Init.Period=3000;
		timhandle->Init.Prescaler=89;

		/***********************************************/
	}
	void TIMinterrupt(){
		/*****interrupt ivent here*************/




		/*****************************************/
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
