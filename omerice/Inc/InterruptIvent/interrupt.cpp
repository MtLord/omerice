/*
 * interrupt.cpp
 *
 *  Created on: 2018/08/08
 *      Author: 裕汰
 */

#include "stm32f4xx_hal.h"
#include "Robot.hpp"
#include "TimerInterruptCallback.hpp"
#include "encoder/encoders.hpp"
//#include "application/excuteApplication.hpp"
extern  Robot *Robo;
extern TimerInterrupt1 *int1;
/*
extern TimerInterrupt2 *int2;
extern TimerInterrupt3 *int3;
extern TimerInterrupt4 *int4;
extern TimerInterrupt5 *int5;
*/



