/*
 * CANTask.cpp
 *
 *  Created on: 2019/03/11
 *      Author: —T‘¿
 */
#include "CANTask.hpp"

extern unsigned char RxFIFO_Data[6];
extern CAN_RxHeaderTypeDef RXmsg;
void CanTask::TaskShift()
{
	unsigned long m_orderid=RXmsg.StdId>>4;
	unsigned long orderid=RXmsg.ExtId>10;
	comustd=RXmsg.StdId&0xF;//‚±‚±•sˆÀ
	comuext=RXmsg.ExtId&0xF;
	if(m_orderid==0x02)
	{
		SetDuty();
	}
	if(orderid==0x40)//get count
	{
		SendEncoder();
	}
}

void CanTask::SetDuty()
{
	((unsigned char*)&dutytemp)[0]=RxFIFO_Data[0];
	((unsigned char*)&dutytemp)[1]=RxFIFO_Data[1];
	((unsigned char*)&dutytemp)[2]=RxFIFO_Data[2];
	((unsigned char*)&dutytemp)[3]=RxFIFO_Data[3];
	switch(comustd)
	{
	case 1:
		plow->m_a.setDuty(dutytemp);
		break;
	case 2:
		plow->m_b.setDuty(dutytemp);
		break;
	case 3:
		plow->m_c.setDuty(dutytemp);
		break;
	case 4:
		plow->m_d.setDuty(dutytemp);
		break;
	case 5:
		plow->m_e.setDuty(dutytemp);
		break;
	case 6:
		plow->m_f.setDuty(dutytemp);
		break;
	}

}

void CanTask::SendEncoder()
{
	switch(comuext)
	{
	case 1:
		countbuf[0]=((unsigned char*)plow->en_a.getcount())[0];
			countbuf[1]=((unsigned char*)plow->en_a.getcount())[1];
			countbuf[2]=((unsigned char*)plow->en_a.getcount())[2];
			countbuf[3]=((unsigned char*)plow->en_a.getcount())[3];
			canbus->Send(0x40<<10|comuext,4,countbuf);
			break;
	case 2:
		countbuf[0]=((unsigned char*)plow->en_b.getcount())[0];
		countbuf[1]=((unsigned char*)plow->en_b.getcount())[1];
		countbuf[2]=((unsigned char*)plow->en_b.getcount())[2];
		countbuf[3]=((unsigned char*)plow->en_b.getcount())[3];
		canbus->Send(0x40<<10|comuext,4,countbuf);
			break;
	case 3:
		countbuf[0]=((unsigned char*)plow->en_c.getcount())[0];
		countbuf[1]=((unsigned char*)plow->en_c.getcount())[1];
		countbuf[2]=((unsigned char*)plow->en_c.getcount())[2];
		countbuf[3]=((unsigned char*)plow->en_c.getcount())[3];
				canbus->Send(0x40<<10|comuext,4,countbuf);
					break;
	case 4:
		countbuf[0]=((unsigned char*)plow->en_d.getcount())[0];
		countbuf[1]=((unsigned char*)plow->en_d.getcount())[1];
		countbuf[2]=((unsigned char*)plow->en_d.getcount())[2];
		countbuf[3]=((unsigned char*)plow->en_d.getcount())[3];
				canbus->Send(0x40<<10|comuext,4,countbuf);
					break;

	}
}

void CanTask2::SetDuty()
{
	((unsigned char*)&dutytemp)[0]=RxFIFO_Data[0];
		((unsigned char*)&dutytemp)[1]=RxFIFO_Data[1];
		((unsigned char*)&dutytemp)[2]=RxFIFO_Data[2];
		((unsigned char*)&dutytemp)[3]=RxFIFO_Data[3];
		switch(comustd)
		{
		case 7:
			plow->m_a.setDuty(dutytemp);
			break;
		case 8:
			plow->m_b.setDuty(dutytemp);
			break;
		case 9:
			plow->m_c.setDuty(dutytemp);
			break;
		case 10:
			plow->m_d.setDuty(dutytemp);
			break;
		case 11:
			plow->m_e.setDuty(dutytemp);
			break;
		case 12:
			plow->m_f.setDuty(dutytemp);
			break;
		}
}

void CanTask2::SendEncoder()
{
	switch(comuext)
		{
		case 5:
			countbuf[0]=((unsigned char*)plow->en_a.getcount())[0];
				countbuf[1]=((unsigned char*)plow->en_a.getcount())[1];
				countbuf[2]=((unsigned char*)plow->en_a.getcount())[2];
				countbuf[3]=((unsigned char*)plow->en_a.getcount())[3];
				canbus->Send(0x40<<10|comuext,4,countbuf);
				break;
		case 6:
			countbuf[0]=((unsigned char*)plow->en_b.getcount())[0];
			countbuf[1]=((unsigned char*)plow->en_b.getcount())[1];
			countbuf[2]=((unsigned char*)plow->en_b.getcount())[2];
			countbuf[3]=((unsigned char*)plow->en_b.getcount())[3];
			canbus->Send(0x40<<10|comuext,4,countbuf);
				break;
		case 7:
			countbuf[0]=((unsigned char*)plow->en_c.getcount())[0];
			countbuf[1]=((unsigned char*)plow->en_c.getcount())[1];
			countbuf[2]=((unsigned char*)plow->en_c.getcount())[2];
			countbuf[3]=((unsigned char*)plow->en_c.getcount())[3];
					canbus->Send(0x40<<10|comuext,4,countbuf);
						break;
		case 8:
			countbuf[0]=((unsigned char*)plow->en_d.getcount())[0];
			countbuf[1]=((unsigned char*)plow->en_d.getcount())[1];
			countbuf[2]=((unsigned char*)plow->en_d.getcount())[2];
			countbuf[3]=((unsigned char*)plow->en_d.getcount())[3];
					canbus->Send(0x40<<10|comuext,4,countbuf);
						break;

		}
}

