/*
 * locarization.hpp
 *
 *  Created on: 2018/08/18
 *      Author: �T��
 */

#ifndef APPLICATION_MOVE_HPP_
#define APPLICATION_MOVE_HPP_
#include "pid.hpp"
#include "OmuniDistributionV.hpp"
class move
{
private:
    int i=4;


public:
    DistributeSpeed dist;
	move():dist(16){}
		pid PIDx;
		pid PIDy;
		pid PIDomega;
		pid PIDtheta;
	void GOPosition(float x,float y,float yaw); //(point_x,point_y,angular velocity)

};



#endif /* APPLICATION_MOVE_HPP_ */