/*
 * encoders.hpp
 *
 *  Created on: 2018/05/29
 *      Author: —T‘¿
 */

#ifndef ENCODER_ENCODERS_HPP_
#define ENCODER_ENCODERS_HPP_
#include "encoderA.hpp"
#include "encoderB.hpp"
class encoders
{
long count[2];
float point[2]={0,};
long b_count[2]={0,};
long hensa[2];
public:
	void countintegral();
	long GetXcount()
{
	return point[0];
}
	long GetYcount()
{
	return point[1];
}
};







#endif /* ENCODER_ENCODERS_HPP_ */
