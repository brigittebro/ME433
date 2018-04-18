/* 
 * File:   spi.h
 * Author: brigittebroszus
 *
 * Created on April 18, 2018, 12:17 AM
 */

#ifndef SPI_H
#define	SPI_H

void initSPI1();
char SPI1_IO(char write);
void setVoltage(char channel, int voltage);


#endif	/* SPI_H */

