/*
 * pid.cpp
 *
 *  Created on: 2018/07/02
 *      Author: takagiyugo
 */
//
//  pid.cpp
//  app
//
//  Created by 高城友豪 on 2018/07/02.
//  Copyright © 2018年 高城友豪. All rights reserved.
//

#include "pid.hpp"
//+++++PID+++++//

void pid::set_present(float pidx) {
    x = pidx;
}

void pid::set_gain(float kp,float ki,float kd)
{
	KP=kp;
	KI=ki;
	KD=kd;
}
float pid::run_pid(float ref)
{
    diff[0] = diff[1];
    diff[1] = ref - x;
    integral += ((diff[1] + diff[0]) / 2)*time;
    adjustment = KP*diff[1] + KI*integral + KD*(diff[1] - diff[0]) / time;

    return adjustment;
}
//+++++++++++++//
