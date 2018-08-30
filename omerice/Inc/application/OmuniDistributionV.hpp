/*
 * OmuniDistributionV.hpp
 *
 *  Created on: 2018/08/08
 *      Author: —T‘¿
 */

#ifndef APPLICATION_OMUNIDISTRIBUTIONV_HPP_
#define APPLICATION_OMUNIDISTRIBUTIONV_HPP_
#include <math.h>
class DistributeSpeed
{
private:
	const double PI=3.14159265358979323846464338;
	float r;
public:
	float v1;
	float v2;
	float v3;
	DistributeSpeed( float _r):r(_r){}
	void DistributeS(float xdis,float ydis,float omega,float theta)
	{
			//v1 = -xdis * cos(-PI*2/3+theta) + ydis * sin(-PI/3+theta) +r*omega;
			v2 = xdis * cos(theta) + ydis * sin(theta) + r*omega;
			//v3 = -xdis * cos(PI*2/3+theta) + ydis * sin(PI/3+theta) + r*omega;
			v1=-xdis*cos(PI/3+theta)+ydis*sin(PI/3+theta)+r*omega;
			v3=-xdis*cos(PI/3+theta)-ydis*sin(PI/3+theta)+r*omega;
	}

};




#endif /* APPLICATION_OMUNIDISTRIBUTIONV_HPP_ */
