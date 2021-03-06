/*
 * CAN.hpp
 *
 *  Created on: 2018/08/18
 *      Author: �T��
 */

#ifndef CAN_CAN_HPP_
#define CAN_CAN_HPP_
#include "stm32f4xx_hal.h"

class can_bus
{
private:
	CAN_TxHeaderTypeDef   TxMessage1;
	CAN_RxHeaderTypeDef  RxMessage1;

	CAN_HandleTypeDef *canhandle;
	CAN_FilterTypeDef  sFilterConfig;
public:
void filterconfig();
	uint8_t Data[8]={0x00,0x00,0x80,0x80,0x80,0x80,0x00,0x00};
	can_bus(CAN_HandleTypeDef *_hcan):canhandle(_hcan)
	{

	}
	 volatile void Sendreqest()
	{
		 	  TxMessage1.DLC=1;
			  TxMessage1.StdId=0x73;
			  TxMessage1.IDE=CAN_ID_STD;
			  TxMessage1.RTR=CAN_RTR_DATA;

			uint8_t TR_BUF[1]={0x42,};

			   if(HAL_CAN_AddTxMessage(canhandle,&TxMessage1,TR_BUF,(uint32_t*)CAN_TX_MAILBOX0)!=HAL_OK)
			  {
				   printf("Txerror\n\r");
			  }
	}
	//virtual void Transmit();
	 void Receeive()
	{

		HAL_CAN_GetRxMessage(canhandle,CAN_RX_FIFO0,&RxMessage1,this->Data);
		 // printf("data[0]:%d data[1]:%d data[2]:%d data[3]:%d data[4]:%d data[5]:%d data[6]:%d data[7]:%d\n\r",Data[0],Data[1],Data[2],
		       		 //Data[3],Data[4],Data[5],Data[6],Data[7]);
	}

};



#endif /* CAN_CAN_HPP_ */
