/*
 * File:   IR_Receive.c
 * Author: Jesus
 *
 * Created on October 21, 2013, 2:01 PM
 */

#define FOSC 7370000ULL
#define FCY (FOSC/2)
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
/*
 *
 */

#include <libpic30.h>

#define LED1 LATBbits.LATB8
#define ON 1
#define OFF 0
#define LED2 LATBbits.LATB7

unsigned int Cap1, Cap2, Cap3, Cap4, Cap5, Cap6, Cap7, Cap8, x;


void main(void) {


 AD1PCFGL = 0xFFFF;//Set all pins to digital
 PMD1bits.AD1MD = 1;//ADC Disabled.
 TRISAbits.TRISA0 = 0;
// The following code example will set the Input Capture 1 module
// for interrupts on every second capture event, capture on every
// fourth rising edge and select Timer 2 as the time-base. This
// code example clears IC1CON to avoid unexpected interrupts.
 // Initialize Capture Module
IC1CONbits.ICM= 0b00; // Disable Input Capture 1 module
IC1CONbits.ICTMR= 1; // Select Timer2 as the IC1 Time base
IC1CONbits.ICI= 0b00; // Interrupt on every second capture event
IC1CONbits.ICM= 0b001; // Generate capture event on every Rising edge
// Enable Capture Interrupt And Timer2
IPC0bits.IC1IP = 1; // Setup IC1 interrupt priority level
IFS0bits.IC1IF = 0; // Clear IC1 Interrupt Status Flag
IEC0bits.IC1IE = 1; // Enable IC1 interrupt

 TRISBbits.TRISB8 = 0;
 TRISBbits.TRISB7 = 0;
 
 __builtin_write_OSCCONL(OSCCON & ~(1<<6)); //Unlock peripheral pin select
    RPINR7bits.IC1R = 6; //Set Input Capture 1 to RP23
__builtin_write_OSCCONL(OSCCON | (1<<6)); //Lock peripheral pin select


 


  T2CON = 0x8020; //sets up a 8 prescaler for the pic and enables timer 2
  x = 0;

  while(1)
  {
      //if((Cap2 - Cap1) >= 70 && (Cap2 - Cap1) <= 80 && (Cap4 - Cap3) >= 170 &&(Cap4 - Cap3) <= 180) // requirements for Damage packet
     // {
      //    LED1 = ON;
      //    LED2 = OFF;
      //}
      //if((Cap2 - Cap1) >= 85 && (Cap2 - Cap1) <= 95 && (Cap4 - Cap3) >= 265 &&(Cap4 - Cap3) <= 275) // requirements for Damage packet
      //{
      //    LED2 = ON;
      //    LED1 = OFF;
      //}
      if((Cap2 - Cap1) >= 70 && (Cap2 - Cap1) <= 80)
      {
          LED2 = ON;
      }
   
  }

}

void __attribute__ ((__interrupt__,no_auto_psv)) _IC1Interrupt(void)
{

 IFS0bits.IC1IF = 0; // Reset respective interrupt flag
 LATAbits.LATA0 = 1;
 
 Cap1 = IC1BUF; // Read and save off first capture entry
 Cap2 = IC1BUF; // Read and save off second capture entry
 Cap3 = IC1BUF; // Read and save off third capture entry
 Cap4 = IC1BUF; // Read and save off fourth capture entry
 Cap5 = IC1BUF; // Read and save off fourth capture entry
 Cap6 = IC1BUF; // Read and save off fourth capture entry
 Cap7 = IC1BUF; // Read and save off fourth capture entry
 Cap8 = IC1BUF; // Read and save off fourth capture entry


 /*
 if(x = 1)
 {
 Cap3 = IC1BUF; // Read and save off third capture entry
 Cap4 = IC1BUF; // Read and save off fourth capture entry
 x = 0;
 }
 else
 {
 Cap1 = IC1BUF; // Read and save off first capture entry
 Cap2 = IC1BUF; // Read and save off second capture entry
 x = 1;
 }
  */

}