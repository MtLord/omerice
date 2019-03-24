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
	ExtCnaBus *canbus;
	LowlayerHandle *plow;
	float dutytemp=0;
	unsigned char countbuf[4]={0,};
	void countset(LowlayerHandle *low);
	virtual void SetDuty();//state if
	virtual void SendEncoder();
public:
	void TaskShift();
	CanTask(ExtCnaBus *_canbus,LowlayerHandle *_plow):canbus(_canbus),plow(_plow)
	{

	}
};

class CanTask2:public CanTask //2Ç¬ñ⁄ÇÃÉ{Å[Éh
{
	virtual void SetDuty();//state if
	virtual void SendEncoder();
public:
	using CanTask::CanTask;

};

class CanTask3:public CanTask
{
	virtual void SetDuty();//state if
	virtual void SendEncoder();
public:

};


#endif /* CANTASK_HPP_ */
