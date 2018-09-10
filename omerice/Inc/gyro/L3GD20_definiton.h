/*
 * L3G4200D_definiton.h
 *
 *  Created on: 2018/06/16
 *      Author: —T‘¿
 */

#ifndef GYRO_L3GD20_DEFINITON_H_
#define GYRO_L3GD20_DEFINITON_H_

/******address*************/
#define WHO_AM_I 0x0F
#define CTRL_REG1 0x20
#define CTRL_REG2 0x21
#define CTRL_REG4 0x23
#define CTRL_REG5 0x24
#define OUT_Z_L 0x2C
#define OUT_Z_H 0x2D
#define Certain 0xD4
#define STATUS_reg 0x27
/************command******************/
#define CTRL_REG1_cmd 0x8C//cutoff 20hz
#define CTRL_REG2_cmd 0x01//cutoff15hz
#define L3GD20_500dps 0x10
#define L3GD20_2000dps 0x20
#define CTRL_REG5_cmd 0x10

#endif /* GYRO_L3GD20_DEFINITON_H_ */
