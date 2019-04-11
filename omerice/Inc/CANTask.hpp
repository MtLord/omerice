/*
 * CANTask.hpp
 *
 *  Created on: 2019/03/11
 *      Author: óTëø
 */

#ifndef CANTASK_HPP_
#define CANTASK_HPP_

#include "CAN/CAN.hpp"
#include <LowlayerHandel.hpp>

class CanTask
{
protected:
	unsigned short comustd=0;
	unsigned short comuext=0;
	StdCanBus *canbus;
	LowlayerHandleTypdef *plow;
	float dutytemp=0;
	unsigned char countbuf[4]={0,};
	void countset(LowlayerHandleTypdef *low);
	virtual void SetDuty();//state if

	long count1=0;
	long count2=0;
	long count3=0;
	long count4=0;
	long count5=0;
	long count6=0;
	long count7=0;
	long count8=0;
public:
	virtual void TaskShift();
	virtual void SendEncoder();
	CanTask(StdCanBus *_canbus,LowlayerHandleTypdef *_plow):canbus(_canbus),plow(_plow)
	{

	}
};

class CanTask2:public CanTask //2Ç¬ñ⁄ÇÃÉ{Å[Éh
{
	virtual void SetDuty();//state if

public:
	virtual void SendEncoder();

	using CanTask::CanTask;

};

class CanTask3:public CanTask
{
	virtual void SetDuty();//state if
	void SendEncoder();
public:

};


#endif /* CANTASK_HPP_ */
