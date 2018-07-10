#ifndef __pspaddata__
#define __pspaddata__
#include "stm32f4xx_hal.h"
#define CS_LOW HAL_GPIO_WritePin(PS2_CS_GPIO_Port, PS2_CS_Pin, GPIO_PIN_RESET)
#define CS_HIGH HAL_GPIO_WritePin(PS2_CS_GPIO_Port,PS2_CS_Pin , GPIO_PIN_SET)
class Pspad
{

private:
	SPI_HandleTypeDef *hspi2;
	 uint8_t CDMdata[9]={0x01,0x42,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
protected:
	 uint8_t GetBytedata[9];

public:
	Pspad(SPI_HandleTypeDef *_hspi2):hspi2(_hspi2){CS_HIGH;}
	void PSpad_get_dat();
};

class PadDataDepot:public Pspad
{

	public:
		using Pspad::Pspad;//コンストラクターの継承
		inline uint8_t SELECT(){return ((~GetBytedata[3]>>0)&0x01);}// セレクトボタン
		inline uint8_t L3(){return((~GetBytedata[3]>>1)&0x01);}// L3ボタン
		inline uint8_t R3(){return((~GetBytedata[3]>>2)&0x01);}
		inline uint8_t START(){return((~GetBytedata[3]>>3)&0x01);}
		inline uint8_t UP(){return((~GetBytedata[3]>>4)&0x01);}
		inline uint8_t RIGHT(){return((~GetBytedata[3]>>5)&0x01);}
		inline uint8_t DOWN(){return((~GetBytedata[3]>>6)&0x01);}
		inline uint8_t LEFT(){return((~GetBytedata[3]>>7)&0x01);}
		inline uint8_t L2(){return((~GetBytedata[4]>>0)&0x01);}
		inline uint8_t R2(){return((~GetBytedata[4]>>1)&0x01);}
		inline uint8_t L1(){return((~GetBytedata[4]>>2)&0x01);}
		inline uint8_t R1(){return(~GetBytedata[4]>>3)&0x01;}
		inline uint8_t SANKAKU(){return((~GetBytedata[4]>>4)&0x01);}
		inline uint8_t MARU(){return((~GetBytedata[4]>>5)&0x01);}
		inline uint8_t BATSU(){return((~GetBytedata[4]>>6)&0x01);}
		inline uint8_t SHIKAKU(){return((~GetBytedata[4]>>7)&0x01);}
		inline uint8_t ANALOG_RIGHT_X(){return(GetBytedata[5]);}
		inline uint8_t ANALOG_RIGHT_Y(){return 0xFF-GetBytedata[6];}
		inline uint8_t ANALOG_LEFT_X(){return GetBytedata[7];}
		inline uint8_t ANALOG_LEFT_Y(){return 0xFF-GetBytedata[8];}
};




#endif
