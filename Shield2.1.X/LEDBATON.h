
/*
 *                          FUNCTION HEADERS
 */
void updateHP(void);

/*
 *                          FUNCTIONS
 */

void updateHP(void)
{
    HP -= DAMAGE;
    //percentHP = (int)(HP/TOTAL_HP);
    if(HP > 5000)
    {
        LED0 = 1;
        LED1 = 1;
        LED2 = 1;
        LED3 = 1;
        LED4 = 1;
        LED5 = 1;
    }
    else if(HP > 4000)
    {
        LED0 = 1;
        LED1 = 1;
        LED2 = 1;
        LED3 = 1;
        LED4 = 1;
        LED5 = 0;
    }
    else if(HP > 3000)
    {
        LED0 = 1;
        LED1 = 1;
        LED2 = 1;
        LED3 = 1;
        LED4 = 0;
        LED5 = 0;
    }
    else if(HP > 2000)
    {
        LED0 = 1;
        LED1 = 1;
        LED2 = 1;
        LED3 = 0;
        LED4 = 0;
        LED5 = 0;
    }
    else if(HP > 1000)
    {
        LED0 = 1;
        LED1 = 1;
        LED2 = 0;
        LED3 = 0;
        LED4 = 0;
        LED5 = 0;
    }
    else if(HP > 0)
    {
        LED0 = 1;
        LED1 = 0;
        LED2 = 0;
        LED3 = 0;
        LED4 = 0;
        LED5 = 0;
    }
    else
    {
        LED0 = 0;
        LED1 = 0;
        LED2 = 0;
        LED3 = 0;
        LED4 = 0;
        LED5 = 0;
    }
}


// Change Notification Interrupt Service Routine (ISR)
void __attribute__((interrupt,no_auto_psv)) _CNInterrupt(void)
{
    if(REFLECT_BUTTON == PRESSED)
    {
        pushedBttn = attReflect;
        noSoundFlag = 1;
        T4CONbits.TON = 0;  //Turn off timer 4
    }
    else if(HEAL_BUTTON == PRESSED)
    {
        pushedBttn = heal;
        noSoundFlag = 1;
        T4CONbits.TON = 0; // turn off timer 4
    }
    
        IEC1bits.CNIE = 0; // Disable CN interrupts
        IFS1bits.CNIF =0; //Clear Interrupt Flag
}

