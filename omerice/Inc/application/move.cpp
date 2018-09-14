/*
 * localization.cpp
 *
 *  Created on: 2018/08/18
 *      Author: 裕汰
 */

#include <application/move.hpp>
#include "Robot.hpp"
extern Robot *Robo;
void move::GOPosition(float x,float y,float yaw)
{
	PIDx.set_present(Robo->loca.GetX());//現在地をセット
	PIDy.set_present(Robo->loca.GetY());

	PIDtheta.set_present(Robo->loca.GetYaw());
	//dist->DistributeS(PIDx.run_pid(x),PIDy.run_pid(y),PIDtheta.run_pid(yaw),Robo->loca.GetYaw());
	dist->DistributeS(x,y,yaw,Robo->loca.GetYaw());
	//printf("x%f y%f\n\r",x,y);
	//printf("%f %f\n\r",Robo->loca.GetYaw()*180/3.141592,PIDomega.run_pid(yaw));
	Robo->m_a.setDuty(dist->v1);
	Robo->m_b.setDuty(dist->v2);
	Robo->m_c.setDuty(dist->v3);
	//Robo->m_d.setDuty(dist->v4);
}


//GetX(void){エンコーダーを継承してgetxを作る
//return -1*Get_d().x*1000-38.65*sin(Get_d().yaw)-60*cos(Get_d().yaw)+60;
//}
/*
float GetY(){
	return Get_d().Y*1000+60*sin(Get_d().yaw)+38.65*cos(Get_d().yaw);
}*/


