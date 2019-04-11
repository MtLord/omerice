/*
 * CAN.cpp
 *
 *  Created on: 2018/12/28
 *      Author: —T‘¿
 */
#include "CAN.hpp"
#include "LowlayerHandel.hpp"
#include "can.h"
extern LowlayerHandleTypdef *plow;
unsigned char RxFIFO_Data[7];
CAN_RxHeaderTypeDef RXmsg;

bool CanRxFlag=false;
void FilterConfig()
{
	CAN_FilterTypeDef  sFilterConfig;
	sFilterConfig.FilterIdHigh=0x0000;
	sFilterConfig.FilterIdLow=0x0000;
	sFilterConfig.FilterMaskIdHigh=0x0000;
	sFilterConfig.FilterMaskIdLow=0x0000;
	sFilterConfig.FilterFIFOAssignment=CAN_FILTER_FIFO0;
	sFilterConfig.FilterBank=0;
	sFilterConfig.FilterScale=CAN_FILTERSCALE_32BIT;
	sFilterConfig.FilterMode=CAN_FILTERMODE_IDMASK;
	sFilterConfig.FilterActivation=ENABLE;
	sFilterConfig.SlaveStartFilterBank=14;
	if(HAL_CAN_ConfigFilter(&hcan1, &sFilterConfig)!=HAL_OK)
		{
			//printf("filter config error!");
		}
	HAL_CAN_Start(&hcan1);
	HAL_CAN_ActivateNotification(&hcan1, CAN_IT_RX_FIFO0_MSG_PENDING);
}

void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)
 {
   if(hcan->Instance==CAN1)
   {

	   HAL_CAN_GetRxMessage(&hcan1,CAN_RX_FIFO0,&RXmsg,RxFIFO_Data);
	   CanRxFlag=true;
   }


 }
 void HAL_CAN_RxFifo1MsgPendingCallback(CAN_HandleTypeDef *hcan)
 {
   if(hcan->Instance==CAN1)
   {

	  HAL_CAN_GetRxMessage(&hcan1,CAN_RX_FIFO1,&RXmsg,RxFIFO_Data);
	   CanRxFlag=true;

   }
 }


short ExtCnaBus::Send(unsigned long ID,unsigned char DLC,unsigned char *data)
{
	Txmsg.DLC=DLC;
	Txmsg.ExtId=ID;
	Txmsg.IDE=CAN_ID_EXT;
	Txmsg.RTR=CAN_RTR_DATA;
	while(Txok==false)
			{
				if(HAL_CAN_AddTxMessage(&hcan1,&Txmsg,data,(uint32_t*)CAN_TX_MAILBOX0)!=HAL_OK)
				{

					HAL_Delay(200/1000);

					if(HAL_CAN_AddTxMessage(&hcan1,&Txmsg,data,(uint32_t*)CAN_TX_MAILBOX1)!=HAL_OK)
					{
						if(HAL_CAN_AddTxMessage(&hcan1,&Txmsg,data,(uint32_t*)CAN_TX_MAILBOX2)==HAL_OK)
						{
							Txok=true;
						}
						else
						{
							return -1;
						}
					}
					else
					{
						return 0;
						Txok=true;
					}
				}
				else
				{
					return 0;
					Txok=true;
				}

			}
		return 0;
		Txok=false;
}

short StdCanBus::Send(unsigned short ID,unsigned char DLC,unsigned char *data)
{
	Txmsg.DLC=DLC;
	Txmsg.StdId=ID;
	Txmsg.IDE=CAN_ID_STD;
	Txmsg.RTR=CAN_RTR_DATA;
	while(Txok==false)
			{
				if(HAL_CAN_AddTxMessage(&hcan1,&Txmsg,data,(uint32_t*)CAN_TX_MAILBOX0)!=HAL_OK)
				{
					if((hcan1.Instance->TSR&(0x1<<26))==0)
					{//TEM0 is full
						HAL_Delay(50/1000);
						if(HAL_CAN_AddTxMessage(&hcan1,&Txmsg,data,(uint32_t*)CAN_TX_MAILBOX1)!=HAL_OK)
						{
							if((hcan1.Instance->TSR&(0x1<<27))==0)//TME1 is full
							{
								if(HAL_CAN_AddTxMessage(&hcan1,&Txmsg,data,(uint32_t*)CAN_TX_MAILBOX2)!=HAL_OK)
								{
									if((hcan1.Instance->TSR&(0x1<<28))==0){
										HAL_CAN_AddTxMessage(&hcan1,&Txmsg,data,(uint32_t*)CAN_TX_MAILBOX0);
									}
									else{
										HAL_CAN_AddTxMessage(&hcan1,&Txmsg,data,(uint32_t*)CAN_TX_MAILBOX2);
										return -1;
									}

								}
								else
								{
									Txok=true;
								}
							}
							else if((hcan1.Instance->TSR&(0x1<<17))==0)
							{
								HAL_CAN_AddTxMessage(&hcan1,&Txmsg,data,(uint32_t*)CAN_TX_MAILBOX2);
							}
						 }
						else
						{
							Txok=true;
						}
					 }
					else if((hcan1.Instance->TSR&(0x1<<17))==0)
					{
						HAL_CAN_AddTxMessage(&hcan1,&Txmsg,data,(uint32_t*)CAN_TX_MAILBOX1);
					}
				 }
				else
				{
					Txok=true;
				}
			}
return 0;
}


