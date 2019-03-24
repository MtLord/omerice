/*
 * CAN.hpp
 *
 *  Created on: 2018/12/28
 *      Author: —T‘¿
 */

#ifndef CAN_CAN_HPP_
#define CAN_CAN_HPP_
#include "can.h"
#include "stm32f4xx_hal.h"

class ExtCnaBus
{
	CAN_TxHeaderTypeDef Txmsg;
	uint8_t TX_BUF[8]={0,};
	bool Txok=false;
public:

	 short Send(unsigned long ID,unsigned char DLC,unsigned char *data);
};

class StdCanBus
{
	CAN_TxHeaderTypeDef Txmsg;
	uint8_t TX_BUF[8]={0,};
public:
	CAN_RxHeaderTypeDef RXmsg;
		unsigned char RxFIFO_Data[];
	 short Send(unsigned short ID,unsigned char DLC,unsigned char *data);

};




#endif /* CAN_CAN_HPP_ */
