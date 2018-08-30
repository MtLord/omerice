/*
 * PS3class.hpp
 *
 *  Created on: 2018/08/20
 *      Author: 裕汰
 */

#ifndef PS3_PS3CLASS_HPP_
#define PS3_PS3CLASS_HPP_
#include "CAN/CAN.hpp"
class PS3controller
{
private:

public:
	can_bus *cannode;
	PS3controller(can_bus *ps3):cannode(ps3){}
			inline uint8_t SELECT(){return ((cannode->Data[0]>>0)&0x01);}// セレクトボタン
			inline uint8_t L3(){return((cannode->Data[0]>>1)&0x01);}// L3ボタン
			inline uint8_t R3(){return((cannode->Data[0]>>2)&0x01);}
			inline uint8_t START(){return((cannode->Data[0]>>3)&0x01);}
			inline uint8_t UP(){return((cannode->Data[0]>>4)&0x01);}
			inline uint8_t RIGHT(){return((cannode->Data[0]>>5)&0x01);}
			inline uint8_t DOWN(){return((cannode->Data[0]>>6)&0x01);}
			inline uint8_t LEFT(){return((cannode->Data[0]>>7)&0x01);}
			inline uint8_t L2(){return((cannode->Data[1]>>0)&0x01);}
			inline uint8_t R2(){return((cannode->Data[1]>>1)&0x01);}
			inline uint8_t L1(){return((cannode->Data[1]>>2)&0x01);}
			inline uint8_t R1(){return(cannode->Data[1]>>3)&0x01;}
			inline uint8_t SANKAKU(){return((cannode->Data[1]>>4)&0x01);}
			inline uint8_t MARU(){return((cannode->Data[1]>>5)&0x01);}
			inline uint8_t BATSU(){return((cannode->Data[1]>>6)&0x01);}
			inline uint8_t SHIKAKU(){return((cannode->Data[1]>>7)&0x01);}
			inline uint8_t ANALOG_RIGHT_X(){return(cannode->Data[2]);}
			inline uint8_t ANALOG_RIGHT_Y(){return 0xFF-cannode->Data[3];}
			inline uint8_t ANALOG_LEFT_X(){return cannode->Data[4];}
			inline uint8_t ANALOG_LEFT_Y(){return 0xFF-cannode->Data[5];}
};




#endif /* PS3_PS3CLASS_HPP_ */
