//Michael Lenth
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
    dma0init();;
    dma2init();
    
    int i;
    for(i = 0; i<8; i++)  // This flushes the Lighting chips buffers, turning the lights off.
    {
        spi = 0x0000;
        latch = 1;
        __delay_us(2);
        latch = 0;
        __delay_us(2);

    }

    latch = 0;  // CONTROL DATA - Sets light brightness to full
    spi = 0xFFFF;
    __delay_ms(2);
    spi = 0xFFFF;
    __delay_ms(2);
    spi = 0xFFFF;
    __delay_ms(2);
    spi = 0xFFFF;
    __delay_ms(2);
    latch = 1;
    __delay_us(2);
        latch = 0;

    audioTransmit(absorbAtt);
    lightTransmit(9);
    lightTransmit(9);

    // MAGE Connection Request over CAN
    ecan1WriteMessage(2, Device_ID | (Connection_Request << 8), 0, MCAN_Weapon_Outbound_ID);
    while(MAGE != CONNECTED);  //Nothing happens if we don't receive connection acknowledgement

    lightTransmit(mime);
    while(1)
    {
        //Calculate width of data received
        Width = Rise_Time - Fall_Time;

        //If the Width is correct for a damage packet, set the irOccured variable
        if((Width > 1500) && (Width < 2200))
        {
            irOccured = 1;
        }
        countVar = 1;

        if(irOccured)
        {
            lightTransmit(absorbAtt);
            lightTransmit(mime);
            audioTransmit(countdown);
            timerX = 0;
            irOccured = 0;
            IEC1bits.CNIE = 1; // Enable CN interrupts
            startCDTimer();//Start countdown timer
            //*********************************************************
            while(pushedBttn == 0 && T4CONbits.TON == 1)
            {
                //Delay for short amount, break out of loop only when timer stops or button has been pushed
            }
            __delay_ms(500);

            //*********************************************************
            if(pushedBttn == attReflect)//Attack button was pressed.
            {
                audioTransmit(attReflect);
                lightTransmit(attReflect);
                lightTransmit(mime);
                iRTX(attReflect);

            }
            else if(pushedBttn == heal)//Heal button was pressed.
            {
                audioTransmit(heal);
                lightTransmit(heal);
                lightTransmit(mime);
                iRTX(heal);
            }
            else//No button pressed, damage incurred.
            {
                updateHP();
                ecan1WriteMessage(4, Device_ID | (IR_Hit_Received << 8), numAttacks, MCAN_Weapon_Outbound_ID);
                if(HP == 0)
                {
                    __delay_ms(1000);
                    audioTransmit(shldBroke);
                    lightTransmit(shldBroke);
                    ecan1WriteMessage(2, Device_ID | (Dead_Packet << 8), 0, MCAN_Dead_Packet_ID);
                    while(1);
                }
                else
                {
                    __delay_ms(1000);
                    audioTransmit(takeDmg);
                    lightTransmit(takeDmg);
                    lightTransmit(mime);
                    
                }
                
            }
            //*********************************************************
            pushedBttn = 0; //Clear button push variable
            irOccured = 0; //Reset, sit in "idle" waiting state again.
            noSoundFlag = 0; // Make sure the countdown isn't playing
            timerX = 0; //Reset countdown timer value
            Fall_Time = 0; //Allow new IR to be received
            Rise_Time = 0 ;//Allow new IR to be received
        }
        idleCnt++;
    }
}