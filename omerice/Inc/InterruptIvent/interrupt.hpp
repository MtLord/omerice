/*
 * interrupt.cpp
 *
 *  Created on: 2018/08/08
 *      Author: 裕汰
 */
#ifndef __interrupt__HPP
#define __interrupt__HPP
#include "stm32f4xx_hal.h"
#include "Robot.hpp"
#include "TimerInterruptCallback.hpp"
extern  Robot *Robo;
extern TimerInterrupt1 *int1;
extern TimerInterrupt2 *int2;
extern TimerInterrupt3 *int3;
extern TimerInterrupt4 *int4;
extern TimerInterrupt5 *int5;
int flag;
  //excution excu;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
			{
	flag++;
				if(htim->Instance == TIM3)
				{
					Robo->en_b.flag++;
					if(Robo->en_b.flag>=1){
					Robo->en_b.InterruptIventCallback();
					}
				}
				if(htim->Instance == TIM4)
				{
					Robo->en_c.flag++;
					if(Robo->en_c.flag>=1){
					Robo->en_c.InterruptIventCallback();
					}
				}
				if(htim->Instance==TIM7)
				{

					int1->TIMinterrupt();
				}
				if(htim->Instance==TIM10)
				{


				}
				if(htim->Instance==TIM11)
								{


								}
				if(htim->Instance==TIM13)
				{


				}
				if(htim->Instance==TIM14)
				{

				}

				if(htim->Instance == TIM6)//0.025�ｿｽﾍア�ｿｽE�ｿｽg�ｿｽv�ｿｽb�ｿｽg�ｿｽ�ｿｽ�ｿｽ�ｿｽ
					{

					Robo->gyro.outdegculc(2.1);
					Robo->loca.integralcount();
					}
			}
	void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
	{
		if(GPIO_Pin==GPIO_PIN_3)
		{
			Robo->sensor.interrupter();
		}
	}
#endif
