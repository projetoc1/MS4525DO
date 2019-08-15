/* Esta biblioteca tem como objetivo implementar  o sensor MS4525DO.
Ete sensor mede pressão diferencial e temperatura.*/

#include "MS4525DO.h"

//Inicilialização do Sensor e calibração de pressão zero

void MS4525DO::initialize() {

	uint8_t buff[4];
	I2Cdev::readBytes( MS4525DO_ADDRESS , MS4525DO_REG, 4, buff);
	Zero_Cal = (buff[0] & 0x3f)<<8 | buff[1];

}

void MS4525DO::read_Pressure() {
    
	uint8_t buff[4];
	I2Cdev::readBytes( MS4525DO_ADDRESS , MS4525DO_REG, 4, buff);
	P_dat = (buff[0] & 0x3f)<<8 | buff[1];
}

void MS4525DO::read_Temperature() {
    
	uint8_t buff[4];
	I2Cdev::readBytes( MS4525DO_ADDRESS , MS4525DO_REG, 4, buff);
	buff[3] = buff[3]>>5;
	T_dat = ((uint16_t)buff[2]<<3) | buff[3];
}

void MS4525DO::calculate_Pressure() {
    float psi;
	psi  = (0.1*((float)P_dat-(float)Zero_Cal))*(0.8/655.32);
	PRES = 6894.757*psi;
}

void MS4525DO::calculate_Temperature() {

    float t;
    t    = (float)T_dat;
	TEMP = -50 + (200*t/2047);
}

float MS4525DO::get_Pressure() {

	read_Pressure();
	calculate_Pressure();
	return PRES;
}

float MS4525DO::get_Temperature() {

	read_Temperature();
	calculate_Temperature();
	return TEMP;
}