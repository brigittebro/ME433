#include "spi.h"


/*
 * void setVoltage(char channel, int voltage) where channel is 0 or 1 (for VoutA and VoutB), and voltage is the 10-bit output level.

Write code that:

the DAC outputs a 10Hz sine wave on VoutA and a 5Hz triangle wave on VoutB, updating the values 1000 times a second 
 * 
 * 
 * 
 Use SPI1 to talk to the DAC.

For SPI1, SCK1 is fixed to B14, but you get to choose which pins to use for SDI1 (actually not connected to the DAC, but pick it out anyway), SDO1, and SS1. Use the input and output tables from the pinFunctions pdf to find out what functions the remaining pins can take.

To assign a function to a pin:

if the function is an output (like SDO, SS, or OC), the pin points to the function. For example, RPB15Rbits.RPB15R = 0b0101; assigns OC1 to pin B15.
if the function is an input (like SDI or INT), the function points to the pin. For example, INT4Rbits.INT4R = 0b0011; assigns INT4 to pin B15.
For your library, write an initialization function for the communication, like void initSPI1() and functions that do generic communication, like char SPI1_IO(char write).

When you initialize SPI1, use the fastest bit rate possible (SPI1BRG must be an integer >=1). Do not enable automatic control of SS1, just use your pin as a digital pin (initialized with TRIS and set with LAT).
 */

void initSPI1(){
    
}
char SPI1_IO(char write){
    
}
void setVoltage(char channel, int voltage){
    
}
