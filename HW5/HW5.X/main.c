#include "i2c_master_noint.h"


#define ADDR 0b0100000 //usr chooses last 3 bits

//initialize i2c peripheral

int main(){
//initialize;
    
  Startup(); 
  __builtin_disable_interrupts();
  i2c_slave_setup(ADDR);              // init I2C5, which we use as a slave 
                                            //  (comment out if slave is on another pic)
  i2c_master_se
  tup();                       // init I2C2, which we use as a master
  __builtin_enable_interrupts();
  
  
  
if(i2cread(ADDR)==0b0100000){
i2cwrite(ADDR,0x0A, 0b0000111); //lat
} else {
    i2cwrite(ADDR,0x0A, 0b00000); //lat
}
}
