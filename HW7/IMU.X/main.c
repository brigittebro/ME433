/* 
 * File:   main.c
 * Author: brigittebroszus
 *
 * Created on June 9, 2018, 7:56 PM
 */

/*
 * 
 * When you get the correct response from WHOAMI, 
 * write an I2CmultipleRead() function to be able 
 * to read many registers in a row. 
 * Read all of the temperature, gyroscope, and 
 * accelerometer data registers, 
 * and shift them into signed shorts 
 * (temperature, gyroX, gyroY, gyroZ, accelX, accelY, accelZ).

Read the LSM6DS33 at 20 Hz, and blink your LED as a heartbeat. Draw bars starting from the center of the LCD in the direction of the chip +X and +Y directions. 
 * Scale the length of the bars to match the readings from the accelerometer. It may help to write the text values of the readings as you debug.
 */

#include<xc.h>           // processor SFR definitions
#include<sys/attribs.h>  // __ISR macro
#include<ST7735.h>
#define  WAIT_TIME 12000
#include <stdio.h>
#include <stdlib.h>
#include "i2c_master_noint.h"

#define ADDR 0b0100000 //usr chooses last 3 bits


// DEVCFG0
#pragma config DEBUG = OFF // no debugging
#pragma config JTAGEN = OFF // no jtag
#pragma config ICESEL = ICS_PGx1 // use PGED1 and PGEC1
#pragma config PWP = OFF // no write protect
#pragma config BWP = OFF // no boot write protect
#pragma config CP = OFF // no code protect

// DEVCFG1
#pragma config FNOSC = PRIPLL // use primary oscillator with pll
#pragma config FSOSCEN = OFF // turn off secondary oscillator
#pragma config IESO = OFF // no switching clocks
#pragma config POSCMOD = HS // high speed crystal mode
#pragma config OSCIOFNC = OFF // disable secondary osc
#pragma config FPBDIV = DIV_1 // divide sysclk freq by 1 for peripheral bus clock
#pragma config FCKSM = CSDCMD // do not enable clock switch
#pragma config WDTPS = PS1 // use slowest wdt
#pragma config WINDIS = OFF // wdt no window mode
#pragma config FWDTEN = OFF // wdt disabled
#pragma config FWDTWINSZ = WINSZ_25 // wdt window at 25%

// DEVCFG2 - get the sysclk clock to 48MHz from the 8MHz crystal
#pragma config FPLLIDIV = DIV_2 // divide input clock to be in range 4-5MHz
#pragma config FPLLMUL = MUL_24 // multiply clock after FPLLIDIV
#pragma config FPLLODIV = DIV_2 // divide clock after FPLLMUL to get 48MHz
#pragma config UPLLIDIV = DIV_2 // divider for the 8MHz input clock, then multiplied by 12 to get 48MHz for USB
#pragma config UPLLEN = ON // USB clock on

// DEVCFG3
#pragma config USERID = 0b0 // some 16bit userid, doesn't matter what
#pragma config PMDL1WAY = OFF // allow multiple reconfigurations
#pragma config IOL1WAY = OFF // allow multiple reconfigurations
#pragma config FUSBIDIO = ON // USB pins controlled by USB module
#pragma config FVBUSONIO = ON // USB BUSON controlled by USB module


int main() {

    __builtin_disable_interrupts();

    // set the CP0 CONFIG register to indicate that kseg0 is cacheable (0x3)
    __builtin_mtc0(_CP0_CONFIG, _CP0_CONFIG_SELECT, 0xa4210583);

    // 0 data RAM access wait states
    BMXCONbits.BMXWSDRM = 0x0;

    // enable multi vector interrupts
    INTCONbits.MVEC = 0x1;

    // disable JTAG to get pins back
    DDPCONbits.JTAGEN = 0;

    // do your TRIS and LAT commands here
    
        LATA = 0x003E;          // sets RA1 through RA5 HIGH, all else on PortA LOW
LATBbits.LATB5 = 1;     // set pin RB5 HIGH
    
   /*
    TRISB.RB0 = 0; //set Port RB0 as output
    PORTB.RB0 = 1; //set Port RB0 to high (turn on LED)
    TRISA = 1; //Set PORTA as inputs 
    */
    
    TRISBbits.TRISB4 = 1; // pushbutton pin input
    TRISAbits.TRISA4 = 0; // set LED pin to output
    PORTAbits.RA4 =1; // LED pin output (initially high)

    __builtin_enable_interrupts();
    
    LCD_init();
    LCD_clearScreen(BLACK);
    
    
/*    
 * Read all of the temperature, gyroscope, and 
 * accelerometer data registers, 
 * and shift them into signed shorts 
 * (temperature, gyroX, gyroY, gyroZ, accelX, accelY, accelZ).

Read the LSM6DS33 at 20 Hz, and blink your LED as a heartbeat. Draw bars starting from the center of the LCD in the direction of the chip +X and +Y directions. 
 * Scale the length of the bars to match the readings from the accelerometer. It may help to write the text values of the readings as you debug.
 */
        short accel_vals[7] = {};
        short temp;
        short gyroX;
        short gyroY;
        short gyroZ;
        short accelX;
        short accelY;
        short accelZ;
        
        while(1) {
        _CP0_SET_COUNT(0);
        while(_CP0_GET_COUNT()<WAIT_TIME){;} // change WAITTIME to be 20Hz
            LATAINV = 0b10000; // invert output
            I2CmultipleRead(accel_vals,ADDR);
            temp = accel_vals[0];
            gyroX = accel_vals[1];
            gyroY = accel_vals[2];
            gyroZ = accel_vals[3];
            accelX = accel_vals[4];
            accelY = accel_vals[5];
            accelZ = accel_vals[6];
            
            LCD_progressBar(10,20,temp/100);
            LCD_progressBar(10,40,gyroX/100);
            LCD_progressBar(10,60,gyroY/100);
            LCD_progressBar(10,80,gyroZ/100);
            LCD_progressBar(10,100,accelX/100);
            LCD_progressBar(10,120,accelY/100);
            LCD_progressBar(10,140,accelZ/100);
            
            
            
            
        // do nothing while pushbutton is pressed
        //Core Timer to toggle your LED at 1000Hz
            
	// use _CP0_SET_COUNT(0) and _CP0_GET_COUNT() to test the PIC timing
	// remember the core timer runs at half the sysclk
    }
    


}
