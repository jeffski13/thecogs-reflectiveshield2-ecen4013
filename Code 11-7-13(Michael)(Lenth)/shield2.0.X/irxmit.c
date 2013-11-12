/*
 * File:   IR_Transmit.c
 * Author: Spencer Gat Dayum Hood
 *
 * Created on October 15, 2013, 1:11 AM
 */

// PIC24HJ128GP502 Configuration Bit Settings

#define iRLED LATBbits.LATB8
#define ON 1
#define OFF 0
/*
 *Reflective Shield 2.0
 *The COGS
 *IR Transmit Prototype Code
 */


#include <stdio.h>
#include <stdlib.h>
#include <p24HJ128GP202.h>
#include <xc.h>
#include <libpic30.h>

//**********************************************************
//Define functions
void singleBURSTON(void);
void singleBURSTOFF(void);
void busrtON(int length);
void burstOFF(int length);
void iRTX(char choice);

/*
 *
 */
void main(void) {
    TRISBbits.TRISB8 = 0;
    TRISAbits.TRISA0 = 0;

    while(1)
    {
        iRTX('H');
        __delay_ms(250);
        iRTX('D');
        __delay_ms(250);

    }
}

void singleBURSTON(void)
{
    

        iRLED = ON; //Turns on IR LED
        __delay_us(8.4);

        iRLED = OFF; // Turns off IR LED
        TMR5 = 0;
      __delay_us(4.4);
    }

 void singleBURSTOFF(void)
{
    
    
    //1.1 turn all LED ON
    iRLED = OFF; // Turns off IR LED
    TMR5 = 0;
 __delay_us(8.4);
    // 1.2 turn all LED OFF
    iRLED = OFF; // Turns off IR LED
    
    __delay_us(4.4);
}

void burstOFF(int length)
{
   int x;
    for(x = 0; x < length; x++)
    {
        singleBURSTOFF();
    }
}
void burstON(int length)
{
    int x;
    for(x = 0; x < length; x++)
    {
        singleBURSTON();
    }
}
void iRTX(char iRChoice)
{
    if(iRChoice == attReflect)
    {
        LATAbits.LATA0 = 1;
        __delay_ms(100);
        LATAbits.LATA0 = 0;
        //Start packet
        burstON(10);
        burstOFF(140);
        //Data packet
        burstON(20);
        burstOFF(130);
        //Redundant Data Packet
        burstON(20);
        burstOFF(130);
        //Stop Packet
        burstON(150);
    }
     if(iRChoice == heal)
    {
        //Start packet
        burstON(10);
        burstOFF(140);
        //Data packet
        burstON(30);
        burstOFF(120);
        //Redundant Data packet
        burstON(30);
        burstOFF(120);
        //Stop packet
        burstON(150);
    }
}