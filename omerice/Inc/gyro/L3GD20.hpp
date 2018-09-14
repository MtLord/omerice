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

#define sample_rate 500
extern TIM_HandleTypeDef htim6;
class Gyro
{
private:
int flag=0;
	SPI_HandleTypeDef *hspi3;
	float sample[sample_rate];
	double hataverage=0;
	int i;
	double radvel=0;
	uint8_t readByte(uint8_t reg );
	void writeByte( uint8_t reg, uint8_t val );

	uint8_t ret;
		 double vel;
		 double prevel;



		 double average;
		double stddev;
		double getZvel();
		 double deg;

public:
	void gyro_init();
	double Zrad();
	float Zradvel();//return z axis velocity
	void Monitorvalue();

	 void outdegculc(float stdvalue);
	Gyro(SPI_HandleTypeDef *_hspi3):hspi3(_hspi3),deg(0)
	{


	}
};

#endif /* GYRO_L3GD20_HPP_ */
