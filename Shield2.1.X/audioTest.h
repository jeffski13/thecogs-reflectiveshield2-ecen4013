//audioTransmit is based off of what sound is chosen to be played. A switch
//statement will take care of this. It will set the pin low to play them and
//high again to turn them off. Default case is just a fail safe, it will
//reset all values high again (turning the sound off).

void audioTransmit1()
{
    char soundChoice = 1;
    switch(soundChoice)
    {
        case 1: //absorb attack
            MC1 = 0;//Set MC1 low (on).
            MC1 = 1;
            __delay_ms(3000);
            MC1 = 0;
            soundChoice = 2;
        case 2: //countdown
            MC2 = 0;//Set MC2 low (on).
            MC2 = 1;
            __delay_ms(3000);
            MC2 = 0;
            soundChoice = 3;
        case 3: //attReflect
            MC3 = 0;//Set MC3 low (on).
            MC3 = 1;
            __delay_ms(3000);
            MC3 = 0;
            soundChoice = 4;
        case 4: //heal
            MC4 = 0;//Set MC4 low (on).
            MC4 = 1;
            __delay_ms(3000);
            MC4 = 0;
            soundChoice = 5;
        case 5: //takeDmg
            MC5 = 0;//Set MC5 low (on).
            MC5 = 1;
            __delay_ms(3000);
            MC5 = 0;
            soundChoice = 6;
        case 6: //shldBroke
            MC6 = 0;//Set MC6 low (on).
            MC6 = 1;
            __delay_ms(3000);
            MC6 = 0;
            soundChoice = 7;
        case 7: //cheater
            MC7 = 0;//Set MC7 low (on).
            MC7 = 1;
            __delay_ms(3000);
            MC7 = 0;
            soundChoice = 8;
        case 8: //mime
            MC8 = 0;//Set MC8 low (on).
            MC8 = 1;
            __delay_ms(3000);
            MC8 = 0;
            break;
        default: //do nothing
            MC1 = 1;//Set MC1 high (off).
            MC2 = 1;//Set MC2 high (off).
            MC3 = 1;//Set MC3 high (off).
            MC4 = 1;//Set MC4 high (off).
            MC5 = 1;//Set MC5 high (off).
            MC6 = 1;//Set MC6 high (off).
            MC7 = 1;//Set MC7 high (off).
            MC8 = 1;//Set MC8 high (off).
            break;

    }
}