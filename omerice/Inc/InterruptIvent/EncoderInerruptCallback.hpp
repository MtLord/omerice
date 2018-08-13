/*
 * InerruptCallback.hpp
 *
 *  Created on: 2018/08/11
 *      Author: —T‘¿
 */

#ifndef INTERRUPTIVENT_ENCODERINERRUPTCALLBACK_HPP_
#define INTERRUPTIVENT_ENCODERINERRUPTCALLBACK_HPP_
#include "encoder/encoderC.hpp"
#include "encoder/encoderD.hpp"
extern Robot *Robo;
class enocerC_callback:public encoderC
{
public:
	using encoderC::encoderC;

	void InterruptIventCallback()
	{
		/****************enocoderC callback function here*************************/



		/*****************************************************************/
	}

};

class enocerD_callback:public encoderD
{
public:
	using encoderD::encoderD;

	void InterruptIventCallback()
	{
		/****************enocoderD callback function here*************************/









		/*****************************************************************/

	}

};













































#endif /* INTERRUPTIVENT_ENCODERINERRUPTCALLBACK_HPP_ */
