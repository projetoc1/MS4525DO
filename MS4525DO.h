#ifndef MS4525DO_HPP
#define MS4525DO_HPP

#include "I2Cdev.h"
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <math.h>

#define MS4525DO_ADDRESS  0x28
#define MS4525DO_REG      0x28

class MS4525DO {
    public:    

        void initialize();

	    void read_Pressure();
	    void read_Temperature();

	    void calculate_Pressure();
	    void calculate_Temperature();

	    float get_Temperature();
	    float get_Pressure();

    private:
	    
	    uint16_t P_dat,T_dat,Zero_Cal; //Raw data
	    float TEMP; // Calculated temperature
	    float PRES; // Calculated pressure
};




#endif // MS4525DO fim do if