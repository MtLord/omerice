/*
 * interrupt.cpp
 *
 *  Created on: 2018/08/08
 *      Author: 裕汰
 */
#include "stm32f4xx_hal.h"
#include "Robot.hpp"
#define use_gyro_
  extern  Robot *Robo;


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
			{

				if(htim->Instance == TIM3)
				{


				}
				if(htim->Instance == TIM4)
				{
					Robo->en_c.InterruptIventCallback();

				}

				if(htim->Instance==TIM13)
				{


				}
				if(htim->Instance==TIM14)
				{

				}
#ifdef use_gyro_
				if(htim->Instance == TIM6)//0.025�ｿｽﾍア�ｿｽE�ｿｽg�ｿｽv�ｿｽb�ｿｽg�ｿｽ�ｿｽ�ｿｽ�ｿｽ
					{
					Robo->gyro.outdegculc(2.3);
					}
#endif
			}


