/*
 * CANTask.cpp
 *
 *  Created on: 2019/03/11
 *      Author: —T‘¿
 */
#include "CANTask.hpp"
#include "stm32f4xx_hal.h"

extern unsigned char RxFIFO_Data[7];
extern CAN_RxHeaderTypeDef RXmsg;
const unsigned int siftbit=4;
void CanTask::TaskShift()
{
	unsigned long m_orderid=RXmsg.StdId>>4;
	//unsigned long orderid=RXmsg.ExtId>>10;
	comustd=RXmsg.StdId&0xF;//‚±‚±•sˆÀ
	//comuext=RXmsg.ExtId&0xF;
	if(m_orderid==0x02)
	{
		SetDuty();
		//SendEncoder();

	}
	if(m_orderid==0x40)//get count
	{

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
	switch(comustd)
		{
		case 1:
			count1=plow->en_a.getcount();
					 			countbuf[0]=((unsigned char*)&count1)[0];
					 			countbuf[1]=((unsigned char*)&count1)[1];
					 			countbuf[2]=((unsigned char*)&count1)[2];
					 			countbuf[3]=((unsigned char*)&count1)[3];


				break;
		case 2:
			count2=plow->en_b.getcount();
					 		countbuf[0]=((unsigned char*)&count2)[0];
					 		countbuf[1]=((unsigned char*)&count2)[1];
					 		countbuf[2]=((unsigned char*)&count2)[2];
					 		countbuf[3]=((unsigned char*)&count2)[3];


				break;
		case 3:
			count3=plow->en_c.getcount();
					 		countbuf[0]=((unsigned char*)&count3)[0];
					 		countbuf[1]=((unsigned char*)&count3)[1];
					 		countbuf[2]=((unsigned char*)&count3)[2];
					 		countbuf[3]=((unsigned char*)&count3)[3];

						break;
		case 10:
			count4=plow->en_d.getcount();
					 		countbuf[0]=((unsigned char*)&count4)[0];
					 		countbuf[1]=((unsigned char*)&count4)[1];
					 		countbuf[2]=((unsigned char*)&count4)[2];
					 		countbuf[3]=((unsigned char*)&count4)[3];

						break;

		}
	canbus->Send(0x40<<siftbit|comustd,4,countbuf);
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
	switch(comustd)
			{
			case 5:
				count5=plow->en_a.getcount();
									countbuf[0]=((unsigned char*)&count5)[0];
										countbuf[1]=((unsigned char*)&count5)[1];
										countbuf[2]=((unsigned char*)&count5)[2];
										countbuf[3]=((unsigned char*)&count5)[3];


					break;
			case 6:
				count6=plow->en_b.getcount();
									countbuf[0]=((unsigned char*)&count6)[0];
									countbuf[1]=((unsigned char*)&count6)[1];
									countbuf[2]=((unsigned char*)&count6)[2];
									countbuf[3]=((unsigned char*)&count6)[3];

					break;
			case 7:
				count7=plow->en_c.getcount();
									countbuf[0]=((unsigned char*)&count7)[0];
									countbuf[1]=((unsigned char*)&count7)[1];
									countbuf[2]=((unsigned char*)&count7)[2];
									countbuf[3]=((unsigned char*)&count7)[3];

							break;
			case 8:
				count8=plow->en_d.getcount();
									countbuf[0]=((unsigned char*)&count8)[0];
									countbuf[1]=((unsigned char*)&count8)[1];
									countbuf[2]=((unsigned char*)&count8)[2];
									countbuf[3]=((unsigned char*)&count8)[3];

							break;

			}

	canbus->Send(0x40<<siftbit|comustd,4,countbuf);



}

