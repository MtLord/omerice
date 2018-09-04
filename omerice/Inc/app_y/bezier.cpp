/*
 * bezier.cpp
 *
 *  Created on: 2018/07/02
 *      Author: takagiyugo
 */
//
//  bezier.cpp
//  app
//
//  Created by 高城友豪 on 2018/07/02.
//  Copyright © 2018年 高城友豪. All rights reserved.
//

#include "bezier.hpp"
//#define X 0
//#define Y 1

float bezier::bezier3(int anc1,int anc2,int anc3,int anc4,double t)
{
   return (1-t)*(1-t)*(1-t)*anc1 + 3*(1-t)*(1-t)*t*anc2 + 3*(1-t)*t*t*anc3 + t*t*t*anc4;

}
float bezier::bezier4(int anc1,int anc2,int anc3,int anc4,int anc5,int t)
{
    return (1-t)*(1-t)*(1-t)*(1-t)*anc1 + 4*(1-t)*(1-t)*(1-t)*t*anc2 + 6*(1-t)*(1-t)*t*t*anc3 + 4*(1-t)*t*t*t*anc4 + t*t*t*anc5;

}
/*
float bezier::get_point(int tipe)
{
	if(tipe==0)
	{
		return p_x;
	}else{
		return p_y;
	}
}*/
