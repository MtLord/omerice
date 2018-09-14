/*
 * OmuniDistributionV.hpp
 *
 *  Created on: 2018/08/08
 *      Author: —T‘¿
 */

#ifndef APPLICATION_OMUNIDISTRIBUTIONV_HPP_
#define APPLICATION_OMUNIDISTRIBUTIONV_HPP_
#include <math.h>
#include "stm32f4xx_hal.h"
class DistributeSpeed3
{
protected:
	const double PI=3.14159265358979323846264338;
	float r=19.873;//19.873
public:
	float v1;
	float v2;
	float v3;
	float v4;
	DistributeSpeed3():v4(0){}
	virtual void DistributeS(float xdis,float ydis,float omega,float theta)
	{
			//v1 = -xdis * cos(-PI*2/3+theta) + ydis * sin(-PI/3+theta) +r*omega;
			v2 = xdis * cos(theta) + ydis * sin(theta) + r*omega;
			//v3 = -xdis * cos(PI*2/3+theta) + ydis * sin(PI/3+theta) + r*omega;
			v1=-xdis*sin((float)(PI)/6+theta)+ydis*cos((float)(PI)/6+theta)+r*omega;
			v3=-xdis*sin((float)(PI)/6-theta)-ydis*cos((float)(PI)/6-theta)+r*omega;
			//printf("%f %f %f\n\r",v1,v2,v3);
			printf("%f %f %f\n\r",v1,v2,v3);
	}
	virtual ~DistributeSpeed3(){}
};

class DistributeSpeed4:public DistributeSpeed3
{

public:
	virtual ~DistributeSpeed4(){}
	virtual void DistributeS(float xdis,float ydis,float omega,float theta)
	{
		v1=-xdis*sin(PI/4)+ydis*sin((PI/2)-PI/4)+r*omega;
		v2=xdis*cos(-PI/4)+ydis*cos((PI/2)+PI/4)+r*omega;
		v3=xdis*sin(-3*PI/4)-ydis*sin((PI/2)+PI*3/4)+r*omega;
		v4=-xdis*cos(3*PI/4)-ydis*cos((PI/2)-PI*3/4)+r*omega;
	}
};




#endif /* APPLICATION_OMUNIDISTRIBUTIONV_HPP_ */
