/*
 * bezier.hpp
 *
 *  Created on: 2018/07/02
 *      Author: takagiyugo
 */

#ifndef APP_Y_BEZIER_HPP_
#define APP_Y_BEZIER_HPP_

class bezier{
private:
	float p_x;
    float p_y;
public:
    float bezier3(int anc1,int anc2,int anc3,int anc4,double t);
    float bezier4(int anc1,int anc2,int anc3,int anc4,int anc5,int t);
    //float get_point(int);
};

#endif /* APP_Y_BEZIER_HPP_ */
