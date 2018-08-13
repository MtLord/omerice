/*
 * L3G4200D.hpp
 *
 *  Created on: 2018/06/17
 *      Author: 鬮ｯ�ｽｬ陟�髮｣�ｽｽ�ｽｱ�ｿｽ�ｽｽ�ｽｰ
 */

#ifndef GYRO_L3GD20_HPP_
#define GYRO_L3GD20_HPP_
#include <gyro/L3GD20_definiton.h>
#include "stm32f4xx_hal.h"
#include "math.h"

#define sample_rate 400
class Gyro
{
private:
	SPI_HandleTypeDef *hspi3;

	float sample[sample_rate];
	float hataverage=0;
	int i;
	float radvel=0;
	uint8_t readByte(uint8_t reg );
	void writeByte( uint8_t reg, uint8_t val );
	float getZvel();
	uint8_t ret;
		 float vel;
		 float prevel;
		 float deg;
		 float average;
		 float stddev;
public:


	void gyro_init()
	{
		ret = readByte( WHO_AM_I );
		if(ret!=0xd4)
		{
			while(1)
			{
				printf("gyro error:%x\n\r",ret);
			}
		}
				writeByte(CTRL_REG2,CTRL_REG2_cmd);
				writeByte( CTRL_REG4,L3GD20_2000dps );
				writeByte( CTRL_REG1, CTRL_REG1_cmd );//outputrate
				 HAL_Delay(250);//郢昜ｻ｣ﾎ｡郢晢ｽｼ郢ｧ�ｽｪ郢晢ｽｳ邵ｺ荵晢ｽ会ｿｽ�ｽｿ�ｽｽ?邵ｺ貅倪�托ｿｽ�ｽｿ�ｽｽ?邵ｺ�ｽｨ�ｿｽ�ｽｿ�ｽｽ?邵ｺ莉｣竊托ｿｽ�ｽｿ�ｽｽ?
				  for(i=0;i<sample_rate;i++)
				  {
					sample[i]=getZvel();
					HAL_Delay(2);
				  }
				  for(i=0;i<sample_rate;i++)
				  {
					  hataverage+=sample[i]*sample[i]/sample_rate;
					  average+=sample[i]/sample_rate;
				  }
				  stddev=sqrt(hataverage-average*average);
	}

	float Zrad();
	float Zradvel();//return z axis velocity


	 void outdegculc(float stdvalue);
	Gyro(SPI_HandleTypeDef *_hspi3):hspi3(_hspi3),deg(0)
	{}
};

#endif /* GYRO_L3GD20_HPP_ */
