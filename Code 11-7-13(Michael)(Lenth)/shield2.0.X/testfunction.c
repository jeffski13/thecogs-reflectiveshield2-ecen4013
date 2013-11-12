/*
 *Reflective Shield 2.0
 *The COGS
 *
 */

//*********************************************************
#define FOSC 7370000UL //libpic30 needs these to be defined prior to inlcuding it
#define FCY (FOSC/2) //libpic30 needs these to be defined prior to inlcuding it
//*********************************************************


// PIC24HJ128GP504 Configuration Bit Settings

#include <xc.h>

// FBS
#pragma config BWRP = WRPROTECT_OFF     // Boot Segment Write Protect (Boot Segment may be written)
#pragma config BSS = NO_FLASH           // Boot Segment Program Flash Code Protection (No Boot program Flash segment)
#pragma config RBS = NO_RAM             // Boot Segment RAM Protection (No Boot RAM)

// FSS
#pragma config SWRP = WRPROTECT_OFF     // Secure Segment Program Write Protect (Secure segment may be written)
#pragma config SSS = NO_FLASH           // Secure Segment Program Flash Code Protection (No Secure Segment)
#pragma config RSS = NO_RAM             // Secure Segment Data RAM Protection (No Secure RAM)

// FGS
#pragma config GWRP = OFF               // General Code Segment Write Protect (User program memory is not write-protected)
#pragma config GSS = OFF                // General Segment Code Protection (User program memory is not code-protected)

// FOSCSEL
#pragma config FNOSC = FRC              // Oscillator Mode (Internal Fast RC (FRC))
#pragma config IESO = ON                // Internal External Switch Over Mode (Start-up device with FRC, then automatically switch to user-selected oscillator source when ready)

// FOSC
#pragma config POSCMD = NONE            // Primary Oscillator Source (Primary Oscillator Disabled)
#pragma config OSCIOFNC = ON            // OSC2 Pin Function (OSC2 pin has digital I/O function)
#pragma config IOL1WAY = OFF            // Peripheral Pin Select Configuration (Allow Multiple Re-configurations)
#pragma config FCKSM = CSDCMD           // Clock Switching and Monitor (Both Clock Switching and Fail-Safe Clock Monitor are disabled)

// FWDT
#pragma config WDTPOST = PS32768        // Watchdog Timer Postscaler (1:32,768)
#pragma config WDTPRE = PR128           // WDT Prescaler (1:128)
#pragma config WINDIS = OFF             // Watchdog Timer Window (Watchdog Timer in Non-Window mode)
#pragma config FWDTEN = OFF              // Watchdog Timer Enable (Watchdog timer always enabled)

// FPOR
#pragma config FPWRT = PWR128           // POR Timer Value (128ms)
#pragma config ALTI2C = OFF             // Alternate I2C  pins (I2C mapped to SDA1/SCL1 pins)

// FICD
#pragma config ICS = PGD3               // Comm Channel Select (Communicate on PGC3/EMUC3 and PGD3/EMUD3)
#pragma config JTAGEN = OFF             // JTAG Port Enable (JTAG is Disabled)





#include <stdio.h>
#include <stdlib.h>
#include <p24HJ128GP504.h>
#include <libpic30.h>
#include "globalVariables.h"
#include "defines.h"
#include "audioTest.h"
#include "timerTest.h"



/*Function Declerations*/
//void init(void);
//void canBusTX(void);
//void iRTX(char iRChoice);
void audioTransmit( char sound );
void startCDTimer(void);
unsigned char is_bttn_pushed(void);//for test function
//void lightTransmit(char light);



void main(void) {
    RCONbits.SWDTEN = 0;//Disable watchdog timer
    AD1PCFGL = 0xFFFF;//Set all pins to digital
    PMD1bits.AD1MD = 1;//ADC Disabled.
    //Timer4 (Countdown Timer)
    //////////////////////////////////
    TRISAbits.TRISA9 = 0;//LED Start
    TRISCbits.TRISC3 = 0;
    TRISCbits.TRISC4 = 0;
    LATAbits.LATA9 = 0;
    LATCbits.LATC3 = 0;
    LATCbits.LATC4 = 0;
    __delay_ms(500);
    LATAbits.LATA9 = 1;
    LATCbits.LATC3 = 1;
    LATCbits.LATC4 = 1;//LED End
    //////////////////////////////////
    T4CONbits.TON = 0; // Disable Timer
    T4CONbits.TCS = 0; // Select internal instruction cycle clock
    T4CONbits.TGATE = 0; // Disable Gated Timer mode
    T4CONbits.TCKPS = 0b00; // Select 1:1 Prescaler
    IPC6bits.T4IP = 6; // Setup TMR4 interrupt priority level
    IFS1bits.T4IF = 0; // Clear TMR4 Interrupt Status Flag
    IEC1bits.T4IE = 1; // Enable TMR4 interrupt
    //init();
    
    
    TRISBbits.TRISB4 = 0;//MC1
    TRISAbits.TRISA8 = 0;//MC2
    TRISAbits.TRISA3 = 0;//MC3
    TRISAbits.TRISA2 = 0;//MC4
    TRISCbits.TRISC2 = 0;//MC5
    TRISCbits.TRISC1 = 0;//MC6
    TRISCbits.TRISC0 = 0;//MC7
    TRISBbits.TRISB3 = 0;//MC8
    ////////////////////////////
    TRISAbits.TRISA10 = 1;
    TRISAbits.TRISA7 = 1;



    while(1)
    {
        if (is_bttn_pushed() == 1)
        {
            irOccured = 1;
        }
        if(irOccured == 1)
        {
            __delay_ms(500);
            //audioTransmit1(countdown);//Start countdown audio
            startCDTimer();//Start countdown timer
            //*********************************************************
            while(pushedBttn == 0 && T4CONbits.TON == 1)
            {
                 if(is_bttn_pushed() == 2 )
                 {
                     pushedBttn = 3;
                 }
            }
            TRISAbits.TRISA9 = 0;//LED Start
            TRISCbits.TRISC3 = 0;
            TRISCbits.TRISC4 = 0;
            LATAbits.LATA9 = 0;
            LATCbits.LATC3 = 0;
            LATCbits.LATC4 = 0;
            __delay_ms(2000);
            LATAbits.LATA9 = 1;
            LATCbits.LATC3 = 1;
            LATCbits.LATC4 = 1;//LED End
            
            //*********************************************************
            if(pushedBttn == attReflect)//Attack button was pressed.
            {
                //lightTransmit(attReflect);
                audioTransmit1();
                //iRTX(attReflect);
            }
            else if(pushedBttn == heal)//Heal button was pressed.
            {
                //lightTransmit(heal);
                audioTransmit1(heal);
                //iRTX(heal);
            }
            else//No button pressed, damage incurred.
            {
                dmgCounter++; //Increment the shield damage.
                //updateDmgLights(dmgCounter); //Set new values for the HP light.
                if(dmgCounter == 5) //If the shield has received too many hits.
                {
                    //canBusTX();//Send information over CAN that our shield has been destroyed.
                    while(1)
                    {
                        //Looping around in this idle state since the sheild is now destroyed.
                    }
                }
            }
            //*********************************************************

            pushedBttn = 0;
            irOccured = 0; //Reset, sit in "idle" waiting state again.
        }
    }
}
