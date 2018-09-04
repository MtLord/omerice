/*
 * pid.hpp
 *
 *  Created on: 2018/07/02
 *      Author: takagiyugo
 */

#ifndef APP_Y_PID_HPP_
#define APP_Y_PID_HPP_


#include <math.h>

//+++++PID+++++//
class pid
{
private:
    float KP=50;
    float KI=0;
    float KD=0;
    float diff[2];
    float integral;
    float adjustment;
    float time;
    float x;
    float y;
    float yaw;
public:
    pid(void):integral(0),adjustment(0),time(0.01),x(0),y(0),yaw(0){}
    void set_present(float a);
    void set_gain(float kp,float ki,float kd);
    float run_pid(float );
};
//+++++++++++++//
#endif /* APP_Y_PID_HPP_ */
