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
                timerX = 0;//Reset iterations to 0.
                T4CONbits.TON = 0;//Stop Timer
                IEC1bits.CNIE = 0; // No more pushin'. Buttons Disabled
                break;
            default:
                break;
    }

}

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
}

