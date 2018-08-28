/*
 * Get_position.hpp
 *
 *  Created on: 2018/08/28
 *      Author: —T‘¿
 */

#ifndef APPLICATION_LOCALIZATON_HPP_
#define APPLICATION_LOCALIZATON_HPP_

class localization
{
public:
	virtual double GetX();
	virtual double GetY();
	virtual float GetZvel();
	virtual float GetYaw();
	virtual ~localization();
};



#endif /* APPLICATION_LOCALIZATON_HPP_ */
