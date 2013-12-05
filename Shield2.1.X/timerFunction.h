//Michael Lenth
//18425000 cycles = 5 seconds.
//3685000 Hz (clock speed)
//3685000 cycles/ second, 5 times this gives us a 5 seconds timer.


//startCDTimer begins when the first IR signal has been received. It will
//only have a period of 1 second intervals though. The purpose for this
//is so that we can update the lights in the expanding ring after every second.
//Push buttons are also enabled here.
void startCDTimer(void)
{
    TMR4 = 0x00; // Clear timer register
    PR4 = 0xFFFF; // Load the period value
    T4CONbits.TON = 1; // Start Timer
    IEC1bits.CNIE = 1; // Push buttons are a go.
}

//This is the timer4 interrupt service routine. It will update the lights
//every interrupt (1 second, set period of timer.) If the 5th second has
//been reached, reset timer counter, turn off timer (will break while loop
//in main.c), disable buttons.
void __attribute__((__interrupt__, __shadow__,no_auto_psv)) _T4Interrupt(void)
{
    
    IFS1bits.T4IF = 0; //Clear Timer1 interrupt flag

    if(noSoundFlag == 1)
    {
        return;
    }
    
    timerX++; //Increment timer til timerX = 5. Once this happens 5 seconds have passed

    switch(timerX)
    {
            case 553:
                audioTransmit(countdown);//Second 1
                lightTransmit(countdown);//""
                countVar = 2;
                break;
            case 1106: //absorb attack
                audioTransmit(countdown);//Second 2
                lightTransmit(countdown);//""
                countVar = 3;
                break;
            case 1659: //countdown
                audioTransmit(countdown);//Second 3
                lightTransmit(countdown);//""
                countVar = 4;
                break;
            case 2212: //attReflect
                audioTransmit(countdown);//Second 4
                lightTransmit(countdown);//""
                countVar = 5;
                break;
            case 2767://Second 5, number of overflows for 5 seconds. -> 3685000/65535((0xFFFF)) = ~56= ~55.
                audioTransmit(countdown);//Second 5
                lightTransmit(countdown);//Second 5
                timerX = 0;//Reset iterations to 0.
                T4CONbits.TON = 0;//Stop Timer
                IEC1bits.CNIE = 0; // No more pushin'. Buttons Disabled
                break;
            default:
                break;
    }

}

/*
unsigned char is_bttn_pushed(void)
{
    if(PORTCbits.RC5 == 1)
    {
        __delay_ms(10);
        if (PORTCbits.RC5 == 1)
        {
            return 1;
        }
    }

    return 0;
}*/

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


