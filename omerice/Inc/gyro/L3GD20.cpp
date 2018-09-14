/*
 * L3G4200D.cpp
 *
 *  Created on: 2018/06/17
 *
 */

#include <gyro/L3GD20.hpp>
#include "math.h"
 const float pi=3.141592;
#define usecut
uint8_t Gyro::readByte(uint8_t reg )
{
	uint8_t address,val;

		HAL_GPIO_WritePin( gyro_cs_GPIO_Port, gyro_cs_Pin, GPIO_PIN_RESET );

		 address =( reg|0x80);
		HAL_SPI_Transmit( hspi3, &address,1,100 );

		HAL_SPI_Receive( hspi3,&val,1,100 );

		HAL_GPIO_WritePin( gyro_cs_GPIO_Port,gyro_cs_Pin, GPIO_PIN_SET );
return (uint8_t)val;
}

void Gyro::writeByte(uint8_t reg, uint8_t val)
{
	HAL_GPIO_WritePin( gyro_cs_GPIO_Port, gyro_cs_Pin, GPIO_PIN_RESET );

	HAL_SPI_Transmit( hspi3, &reg,1,10 );

	HAL_SPI_Transmit( hspi3, &val,1,10 );

	HAL_GPIO_WritePin( gyro_cs_GPIO_Port,gyro_cs_Pin, GPIO_PIN_SET );



}

  double Gyro::getZvel(  ){
	  signed short ret= (readByte(OUT_Z_H)<<8 | readByte(OUT_Z_L)) ;
	return (double)ret*0.00875;

}

double Gyro::Zrad()
{
	return deg*pi/180;
}


void Gyro::outdegculc(float stdvalue)
{

#ifdef usecut
	vel=getZvel();

	if((vel<(average-stddev*stdvalue))||vel>(average+stddev*stdvalue))
	{
								deg+=(vel+prevel)*0.0025/2;
								prevel=vel;
								radvel=getZvel();
	}
#endif
	//常に足し続ける
#ifndef usecut
	if(getZvel()>=0)
	{
		vel=(getZvel()-this->average)-stddev*stdvalue;
		deg+=(vel+prevel)*0.0025/2;
		prevel=vel;
		radvel=getZvel();
	}
	else if(getZvel()<0)
	{
		vel=(getZvel()-this->average)+stddev*stdvalue;
		deg+=(vel+prevel)*0.0025/2;
				prevel=vel;
				radvel=getZvel();
	}
#endif
}

float Gyro::Zradvel()
{
	return radvel*pi/180;
}

void Gyro::gyro_init()
	{
		ret = readByte( WHO_AM_I );
		if(ret!=0xd4)
		{
			while(1)
			{
				printf("gyro error:%x\n\r",ret);
			}
		}
				//writeByte(CTRL_REG2,CTRL_REG2_cmd);
				writeByte( CTRL_REG4,L3GD20_250dps );
				writeByte( CTRL_REG1, CTRL_REG1_cmd );//outputrate
				//writeByte( CTRL_REG5, CTRL_REG5_cmd );//outputrate
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
				  HAL_TIM_Base_Start_IT(&htim6);
	}
void Gyro::Monitorvalue()
{
	printf("%f %f %f %f \n\r",this->deg,this->getZvel(),stddev,average);
}
