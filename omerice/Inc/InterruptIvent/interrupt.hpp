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
int flag=0;
extern TIM_HandleTypeDef htim13;
extern TIM_HandleTypeDef htim14;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
			{
				if(htim->Instance == TIM2)
				{
					flag++;
					Robo->en_a.Increment();
				}
				if(htim->Instance == TIM3)
				{
				    Robo->en_b.Increment();
				}
				if(htim->Instance == TIM4)
				{
					Robo->en_c.InterruptIventCallback();

				}
				if(htim->Instance == TIM5)
				{
					Robo->en_d.InterruptIventCallback();
				}

				if(htim->Instance==TIM13)
				{
					Robo->en_a.flag=0;
					HAL_TIM_Base_Stop_IT(&htim13);
				}
				if(htim->Instance==TIM14)
				{
					Robo->en_b.flag=0;
					HAL_TIM_Base_Stop_IT(&htim14);
				}
#ifdef use_gyro_
				if(htim->Instance == TIM6)//0.025�ｿｽﾍア�ｿｽE�ｿｽg�ｿｽv�ｿｽb�ｿｽg�ｿｽ�ｿｽ�ｿｽ�ｿｽ
					{
					Robo->gyro.outdegculc(2.3);
					}
#endif
			}


