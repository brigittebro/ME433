#include 'i2c_master_noint.h'


#define ADDR 0b0100000 //usr chooses last 3 bits

//initialize i2c peripheral

void initExp(){
//B2 & B3 digital pins
i2c_master_setup();

i2cwrite(0x000,0b1110000); //iodir
i2cwrite(0x0A,0b0001111);
}

void i2cwrite(unsigned char reg, unsigned char val){
// use wiki code :)

i2c_master_start(); // make the start bit

i2c_master_send(ADDR<1|0); // write the address, shifted left by 1, or'ed with a 0 to indicate writing

i2c_master_send(reg); // the register to write to

i2c_master_send(val); // the value to put in the register

i2c_master_stop(); // make the stop bit
}


unsigned char i2cread(){
// code from wiki :)
  //  To read the value from register 7 in a chip with address 12, the code would look like:

i2c_master_start(); // make the start bit

i2c_master_send(ADDR<1|0); // write the address, shifted left by 1, or'ed with a 0 to indicate writing

i2c_master_send(0x09); // the register to read from

i2c_master_restart(); // make the restart bit

i2c_master_send(ADDR<1|1); // write the address, shifted left by 1, or'ed with a 1 to indicate reading

char r = i2c_master_recv(); // save the value returned

i2c_master_ack(1); // make the ack so the slave knows we got it

i2c_master_stop(); // make the stop bit
}



int main(){
//initialize;
if(i2cread()==100000){
i2cwrite 0x0A, 0b0000111; //lat
} else {
    i2cwrite(0x0A, 0b00000); //lat
}
}
