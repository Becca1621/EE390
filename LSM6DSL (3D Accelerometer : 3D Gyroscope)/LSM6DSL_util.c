#include "stm32l4xx_hal.h"
#include "LIS3MDL_util.h"

#define LSM6DSL_WRITE_ADDRESS 0xD4
#define LSM6DSL_READ_ADDRESS 0xD5
#define FUNC_CFG_ACCESS 0x01
#define SENSOR_SYNC_TIME_FRAME 0x04
#define SENSOR_SYNC_RES_RATIO 0x05
#define FIFO_CTRL1 0x06
#define FIFO_CTRL2 0x07
#define FIFO_CTRL3 0x08
#define FIFO_CTRL4 0x09
#define FIFO_CTRL5 0x0A
#define DRDY_PULSE_CFG_G 0x0B
#define INT1_CTRL 0x0D
#define INT2_CTRL 0x0E
#define WHO_AM_I 0x0F
#define CTRL_XL 0x10
#define CTRL2_G 0x11
#define CTRL3_C 0x12
#define CTRL4_C 0x13
#define CTRL5_C 0x14
#define CTRL6_C 0x15
#define CTRL7_G 0x16
#define CTRL8_XL 0x17
#define CTRL9_XL 0x18
#define CTRL10_C 0x19
#define MASTER_CONFIG 0x1A
#define WAKE_UP_SRC 0x1B
#define TAP_SRC 0x1C
#define D6D_SRC 0x1D
#define STATUS_REG 0x1E
#define OUT_TEMP_L 0x20
#define OUT_TEMP_H 0x21
//Output for Gyro X,Y,Z
#define OUTX_L_G 0x22
#define OUTX_H_G 0x23
#define OUTY_L_G 0x24
#define OUTY_H_G 0x25
#define OUTZ_L_G 0x26
#define OUTZ_H_G 0x27
//Accelerometer OUT X,Y,Z
#define OUTX_L_XL 0x28
#define OUTX_H_XL 0x29
#define OUTY_L_XL 0x2A
#define OUTY_H_XL 0x2B
#define OUTZ_L_XL 0x2C
#define OUTZ_H_XL 0x2D

void LSM6DSL_acc_init_default() {
	//
}

void LSM6DSL_gyro_init_default() {
	
}

//Accelerometer
void LSM6DSL_acc_Read_OUT_X() {
	
}
void LSM6DSL_acc_Read_OUT_Y() {
	
}
void LSM6DSL_acc_Read_OUT_Z() {
	
}

//Gyro
void LSM6DSL_gyro_Read_OUT_X() {
	
}
void LSM6DSL_gyro_Read_OUT_Y() {
	
}
void LSM6DSL_gyro_Read_OUT_Z() {
	
}

