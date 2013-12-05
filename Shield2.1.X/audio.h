//Michael Lenth
//audioTransmit is based off of what sound is chosen to be played. A switch
//statement will take care of this. It will set the pin low to play them and
//high again to turn them off. Default case is just a fail safe, it will
//reset all values high again (turning the sound off).

void allLow(void)
{
    __delay_ms(50);
            MC1 = 1;//Set MC1 high (off).
            MC2 = 1;//Set MC2 high (off).
            MC3 = 1;//Set MC3 high (off).
            MC4 = 1;//Set MC4 high (off).
            MC5 = 1;//Set MC5 high (off).
            MC6 = 1;//Set MC6 high (off).
            MC7 = 1;//Set MC7 high (off).
            MC8 = 1;//Set MC8 high (off).
}

void audioTransmit(char soundChoice)
{
    switch(soundChoice)
    {
        case 1: //absorb attack
            MC1 = 0;//Set MC1 low (on).
            allLow();
            break;
        case 2: //countdown
           MC2 = 0;//Set MC2 low (on).
           allLow();
            break;
        case 3: //attReflect
            MC3 = 0;//Set MC3 low (on).
            allLow();
            break;
        case 4: //heal
            MC4 = 0;//Set MC4 low (on).
            allLow();
            break;
        case 5: //takeDmg
            MC5 = 0;//Set MC5 low (on).
            allLow();
            break;
        case 6: //shldBroke
            MC6 = 0;//Set MC6 low (on).
            allLow();
            break;
        case 7: //cheater
            MC7 = 0;//Set MC7 low (on).
            allLow();
            break;
        case 8: //mime
            MC8 = 0;//Set MC8 low (on).
            allLow();
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


        allLow();
    }
}
