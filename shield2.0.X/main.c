/* 
 *Reflective Shield 2.0
 *The COGS
 * 
 */

//*********************************************************
#define FOSC 80000000UL //libpic30 needs these to be defined prior to inlcuding it
#define FCY (FOSC/2) //libpic30 needs these to be defined prior to inlcuding it
//*********************************************************
#include <stdio.h>
#include <stdlib.h>
#include <p24HJ128GP504.h>
#include <xc.h>
#include <libpic30.h> //delays are in here
#include "configbitset.h"
#include "defines.h"
#include "globalVariables.h"
#include "initialize.h"
#include "lighting.h"
#include "audio.h"
#include "timerFunction.h"
#include "CAN_Config.h"
#include "CAN_Driver.h"
#include "common.h"
#include "can.h"
#include "iRTX.h"
#include "LEDBATON.h"




/*Function Declerations*/
void init(void);
void iRTX(char iRChoice);
void allLow(void);
void audioTransmit( char sound );
void startCDTimer(void);
void lightTransmit(char light);
void configPLL(void);
void singleBURSTON(void);
void singleBURSTOFF(void);
void busrtON(int length);
void burstOFF(int length);
void updateHP(void);


void main(void) {
    configPLL();
    //char x = 0;
    init();
    ecan1Init();
    dma0init();
    dma2init();
    IEC2bits.C1IE = 1;
    C1INTEbits.TBIE = 1;
    C1INTEbits.RBIE = 1;
    TRISCbits.TRISC5 = 1;
    TRISBbits.TRISB7 = 1;
    LATCbits.LATC5 = 0;

     //IR (Input Capture)
    //Initialize Capture Modules 1,2,7

    AD1PCFGL = 0xFFFF;//Set all pins to digital
    PMD1bits.AD1MD = 1;//ADC Disabled.
    IC1CONbits.ICM= 0b00; // Disable Input Capture 1 module
    IC1CONbits.ICTMR= 1; // Select Timer2 as the IC1 Time base
    IC1CONbits.ICI= 0b01; // Interrupt on every second capture event
    IC1CONbits.ICM= 0b010; // Generate capture event on every Rising edge
    // Enable Capture Interrupt And Timer2
    IPC0bits.IC1IP = 1; // Setup IC1 interrupt priority level
    IFS0bits.IC1IF = 0; // Clear IC1 Interrupt Status Flag
    IEC0bits.IC1IE = 1; // Enable IC1 interrupt

    IC2CONbits.ICM= 0b00; // Disable Input Capture 1 module
    IC2CONbits.ICTMR= 1; // Select Timer2 as the IC1 Time base
    IC2CONbits.ICI= 0b01; // Interrupt on every second capture event
    IC2CONbits.ICM= 0b011; // Generate capture event on every Rising edge
    // Enable Capture Interrupt And Timer2
    IPC1bits.IC2IP = 1; // Setup IC1 interrupt priority level
    IFS0bits.IC2IF = 0; // Clear IC1 Interrupt Status Flag
    IEC0bits.IC2IE = 1; // Enable IC1 interrupt

__builtin_write_OSCCONL(OSCCON & ~(1<<6)); //Unlock peripheral pin select
    RPINR7bits.IC1R = 6; //Set Input Capture 1 to RP9
    RPINR7bits.IC2R = 6; //Set Input Capture 1 to RP9
__builtin_write_OSCCONL(OSCCON | (1<<6)); //Lock peripheral pin select

TRISBbits.TRISB9 = 0;

    PR2 = 0xFFFF;
    Fall_Time = 0;
    Rise_Time = 0;
    T2CON = 0x8010;

//  while(1)
//  {
//      iRTX(heal);
//      __delay_ms(100);
//
//  }
   
    ecan1WriteMessage(0x0001,25);
    C1TR01CONbits.TXREQ0 = 1;

    while(1)
    {
        
//        if (is_bttn_pushed() == 1)
//        {
//            irOccured = 1;
//        }
        //irOccured = 1;
        Width = Rise_Time - Fall_Time;
        if((Width > 1500) && (Width < 2200))
        {
            irOccured = 1;
        }
        countVar = 1;

        if(irOccured)
        {
            timerX = 0;
            irOccured = 0;
            IEC1bits.CNIE = 1; // Enable CN interrupts
            startCDTimer();//Start countdown timer
            //*********************************************************
            while(pushedBttn == 0 && T4CONbits.TON == 1)
            {
                //__delay_us(1);//Delay for short amount, break out of loop only when timer stops or button has been pushed
            }
            __delay_ms(500);

            //*********************************************************
            if(pushedBttn == attReflect)//Attack button was pressed.
            {
                lightTransmit(attReflect);
                audioTransmit(attReflect);
                iRTX(attReflect);

            }
            else if(pushedBttn == heal)//Heal button was pressed.
            {
                lightTransmit(heal);
                audioTransmit(heal);
                iRTX(heal);
            }
            else//No button pressed, damage incurred.
            {
                updateHP();
                if(HP == 0)
                {
                    lightTransmit(shldBroke);
                    audioTransmit(shldBroke);
                    ecan1WriteMessage(0xdead, 0x10FF);
                    while(1);
                }
                else
                {
                    lightTransmit(takeDmg);
                    __delay_ms(250);
                    audioTransmit(takeDmg);
                }
                
            }
            //*********************************************************
            pushedBttn = 0;
            irOccured = 0; //Reset, sit in "idle" waiting state again.
            noSoundFlag = 0;
            timerX = 0;
            Fall_Time = 0;
            Rise_Time = 0;
        }        
    }
}

void __attribute__ ((__interrupt__,no_auto_psv)) _IC1Interrupt(void)
{
    CORCONbits.IPL3 = 1; //Interrupts enabled
    IFS0bits.IC1IF = 0; // Reset respective interrupt flag
    Fall_Time = IC1BUF;
    while(IC1CONbits.ICOV)
    {
       x = IC1BUF;
    }
    IC1CONbits.ICM= 0b00; // Disable Input Capture 1 module
    IC1CONbits.ICTMR= 1; // Select Timer2 as the IC1 Time base
    IC1CONbits.ICI= 0b01; // Interrupt on every second capture event
    IC1CONbits.ICM= 0b010; // Generate capture event on every Rising edge
    // Enable Capture Interrupt And Timer2
    IPC0bits.IC1IP = 1; // Setup IC1 interrupt priority level
    IFS0bits.IC1IF = 0; // Clear IC1 Interrupt Status Flag
    IEC0bits.IC1IE = 1; // Enable IC1 interrupt
    CORCONbits.IPL3 = 0; //Interrupts enabled
}
void __attribute__ ((__interrupt__,no_auto_psv)) _IC2Interrupt(void)
{
    CORCONbits.IPL3 = 1; //Interrupts enabled
    IFS0bits.IC2IF = 0; // Reset respective interrupt flag
    Rise_Time = IC2BUF;
    TMR2 = 0;
    while(IC2CONbits.ICOV)
    {
       x = IC2BUF;
    }
    CORCONbits.IPL3 = 0; //Interrupts enabled
}
