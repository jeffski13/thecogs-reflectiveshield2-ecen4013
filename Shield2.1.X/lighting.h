void __attribute__ ((interrupt,no_auto_psv)) _SPI1Interrupt()
{
    IFS0bits.SPI1IF =0; //clear the interrupt flag
} //You can set up a timer module to give them spacing.

void lightTransmit(char light)
{
    unsigned int loopIT = 0;

            __delay_us(2);
            spi = 0x0002;
            __delay_us(2);
            spi = 0x3fff;
            __delay_us(2);
            spi = 0xff1f;
            __delay_us(2);
            spi = 0xffff;
            __delay_us(2);
            latch = 1;
            __delay_us(3);
            latch = 0;
            __delay_us(2);

    switch(light)
    {
        case 1: //absorb
            latch = 0;
            __delay_us(2);
            spi = rgb8g_1;
            __delay_us(2);
            spi = rgb8g_2 | rgb7g | rgb6g | rgb5g | rgb4g | rgb3g;
            __delay_ms(2);
            spi = rgb2g | rgb1g;
            __delay_us(2);
            spi = led1 | led2 | led3 | led4 | led5 | led6 | led7 | led8;
            __delay_ms(2);
            latch = 1;
            __delay_ms(delayvar);

            latch = 0;
            __delay_us(2);
            spi = rgb8g_1;
            __delay_us(2);
            spi = rgb8g_2 | rgb7g | rgb6g | rgb5g | rgb4g | rgb3g;
            __delay_ms(2);
            spi = rgb2g | rgb1g | led16_1;
            __delay_us(2);
            spi = led9 | led10 | led11 | led12 | led13 | led14 | led15 | led16_2 ;
            __delay_ms(2);
            latch = 1;
            __delay_ms(delayvar);

            latch = 0;
            __delay_us(2);
            spi = rgb8g_1;
            __delay_us(2);
            spi = rgb8g_2 | rgb7g | rgb6g | rgb5g | rgb4g | rgb3g;
            __delay_ms(2);
            spi = rgb2g | rgb1g | led17 | led18 | led19 |led20 | led21 | led22 | led23 | led24;
            __delay_us(2);
            spi = 0 ;
            __delay_ms(2);
            latch = 1;
            __delay_ms(delayvar);

            latch = 0;
            __delay_us(2);
            spi = rgb8g_1;
            __delay_us(2);
            spi = rgb8g_2 | rgb7g | rgb6g | rgb5g | rgb4g | rgb3g;
            __delay_ms(2);
            spi = rgb2g | rgb1g;
            __delay_us(2);
            spi = led1 | led2 | led3 | led4 | led5 | led6 | led7 | led8;
            __delay_ms(2);
            latch = 1;
            __delay_ms(delayvar*2);

            latch = 0;
            __delay_us(2);
            spi = rgb8g_1;
            __delay_us(2);
            spi = rgb8g_2 | rgb7g | rgb6g | rgb5g | rgb4g | rgb3g;
            __delay_ms(2);
            spi = rgb2g | rgb1g | led16_1;
            __delay_us(2);
            spi = led9 | led10 | led11 | led12 | led13 | led14 | led15 | led16_2 ;
            __delay_ms(2);
            latch = 1;
            __delay_ms(delayvar*2);

            latch = 0;
            __delay_us(2);
            spi = rgb8g_1;
            __delay_us(2);
            spi = rgb8g_2 | rgb7g | rgb6g | rgb5g | rgb4g | rgb3g;
            __delay_ms(2);
            spi = rgb2g | rgb1g | led17 | led18 | led19 |led20 | led21 | led22 | led23 | led24;
            __delay_us(2);
            spi = 0 ;
            __delay_ms(2);
            latch = 1;
            __delay_ms(delayvar*2);

        break;
        case 2: //countdown
            switch(countVar)
            {
                case 1:
                    latch = 0;
                    __delay_us(2);
                    spi = rgb8g_1;
                    __delay_us(2);
                    spi = rgb8g_2 | rgb7g | rgb6g | rgb5g | rgb4g | rgb3g;
                    __delay_ms(2);
                    spi = rgb2g | rgb1g | led17 | led18 | led19 |led20 | led21 | led22 | led23 | led24;
                    __delay_us(2);
                    spi = 0 ;
                    __delay_ms(2);
                    latch = 1;
                    break;
                case 2:
                    latch = 0;
                    __delay_us(2);
                    spi = rgb8g_1;
                    __delay_us(2);
                    spi = rgb8g_2 | rgb7g | rgb6g | rgb5g | rgb4g | rgb3g;
                    __delay_ms(2);
                    spi = rgb2g | rgb1g | led16_1;
                    __delay_us(2);
                    spi = led9 | led10 | led11 | led12 | led13 | led14 | led15 | led16_2 ;
                    __delay_ms(2);
                    latch = 1;
                    break;
                case 3:
                    latch = 0;
                    __delay_us(2);
                    spi = rgb8g_1;
                    __delay_us(2);
                    spi = rgb8g_2 | rgb7g | rgb6g | rgb5g | rgb4g | rgb3g;
                    __delay_ms(2);
                    spi = rgb2g | rgb1g;
                    __delay_us(2);
                    spi = led1 | led2 | led3 | led4 | led5 | led6 | led7 | led8;
                    __delay_ms(2);
                    latch = 1;
                    break;
                case 4:
                   latch = 0;
                    __delay_us(2);
                    spi = rgb8g_1;
                    __delay_us(2);
                    spi = rgb8g_2 | rgb7g | rgb6g | rgb5g | rgb4g | rgb3g;
                    __delay_ms(2);
                    spi = rgb2g | rgb1g | led16_1;
                    __delay_us(2);
                    spi = led9 | led10 | led11 | led12 | led13 | led14 | led15 | led16_2 ;
                    __delay_ms(2);
                    latch = 1;
                    break;
                case 5:
                    latch = 0;
                    __delay_us(2);
                    spi = rgb8g_1;
                    __delay_us(2);
                    spi = rgb8g_2 | rgb7g | rgb6g | rgb5g | rgb4g | rgb3g;
                    __delay_ms(2);
                    spi = rgb2g | rgb1g | led17 | led18 | led19 |led20 | led21 | led22 | led23 | led24;
                    __delay_us(2);
                    spi = 0 ;
                    __delay_ms(2);
                    latch = 1;
                    break;
            }
            break;

        case 3: //attack reflect
             latch = 0;
                __delay_us(2);
                spi = 0;
                __delay_us(2);
                spi = rgb8r | rgb7r | rgb6r | rgb5r | rgb4r | rgb3r_1;
                __delay_ms(2);
                spi = rgb3r_2 | rgb1r | led17 | led18 | led19 |led20 | led21 | led22 | led23;
                __delay_us(2);
                spi = 0;
                __delay_ms(2);
                latch = 1;
                 __delay_ms(delayvar*10);

                 latch = 0;
                __delay_us(2);
                spi = 0;
                __delay_us(2);
                spi = rgb8r | rgb7r | rgb6r | rgb5r | rgb4r | rgb3r_1;
                __delay_ms(2);
                spi = rgb3r_2 | rgb1r | led16_1;
                __delay_us(2);
                spi = led9 | led10 | led11 | led12 | led13 | led14 | led15 | led16_2;
                __delay_ms(2);
                latch = 1;
                 __delay_ms(delayvar*10);

                 latch = 0;
                __delay_us(2);
                spi = 0;
                __delay_us(2);
                spi = rgb8r | rgb7r | rgb6r | rgb5r | rgb4r | rgb3r_1;
                __delay_ms(2);
                spi = rgb3r_2 | rgb1r;
                __delay_us(2);
                spi = led1 | led2 | led3 | led4 | led5 | led6 | led7 | led8;
                __delay_ms(2);
                latch = 1;
                 __delay_ms(delayvar*10);
            break;
        case 4: //heal
            
            latch = 0;
                __delay_us(2);
                spi = rgb8b;
                __delay_us(2);
                spi = rgb7b | rgb6b | rgb5b | rgb4b | rgb3b;
                __delay_ms(2);
                spi = rgb1b | rgb2b| led17 | led18 | led19 |led20 | led21 | led22 | led23 | led24;
                __delay_us(2);
                spi = 0;
                __delay_ms(2);
                latch = 1;
                 __delay_ms(delayvar*10);

             latch = 0;
                __delay_us(2);
                spi = rgb8b;
                __delay_us(2);
                spi = rgb7b | rgb6b | rgb5b | rgb4b | rgb3b;
                __delay_ms(2);
                spi = rgb1b | rgb2b | led16_1;
                __delay_us(2);
                spi = led9 | led10 | led11 | led12 | led13 | led14 | led15 | led16_2;
                __delay_ms(2);
                latch = 1;
                 __delay_ms(delayvar*10);

            latch = 0;
                __delay_us(2);
                spi = rgb8b;
                __delay_us(2);
                spi = rgb7b | rgb6b | rgb5b | rgb4b | rgb3b;
                __delay_ms(2);
                spi = rgb1b | rgb2b;
                __delay_us(2);
                spi = led1 | led2 | led3 | led4 | led5 | led6 | led7 | led8;
                __delay_ms(2);
                latch = 1;
                 __delay_ms(delayvar*10);
            break;

        case 5: //take damage
            while(loopIT < 5)
            {

                latch = 0;
                __delay_us(2);
                spi = rgb8g_1 | rgb8b;
                __delay_us(2);
                spi = rgb8g_2 | rgb7g | rgb6g | rgb5g | rgb4g | rgb3g | rgb3r_1 | rgb3b | rgb3r_1 | rgb4r | rgb4b | rgb5r | rgb5b | rgb6r | rgb6b | rgb7r | rgb7b | rgb8r;
                __delay_ms(2);
                spi = rgb3r_2 | rgb2g | rgb2r | rgb2b | rgb1g |  rgb1b | led16_1 | led17 | led18 | led19 | led20 | led21 | led22 | led23 | led24;
                __delay_us(2);
                spi = led1 | led2 | led3 | led4 | led5 | led6 | led7 | led8 | led9 | led10 | led11 | led12 | led13 | led14 | led15 | led16_2;
                __delay_ms(2);
                latch = 1;
                __delay_ms(delayvar);

                latch = 0;
                __delay_us(2);
                spi = 0;
                __delay_us(2);
                spi = 0;
                __delay_ms(2);
                spi = 0;
                __delay_us(2);
                spi = 0;
                __delay_ms(2);
                latch = 1;
                 __delay_ms(delayvar);

                 latch = 0;
                    __delay_us(2);
                    spi = rgb8g_1;
                    __delay_us(2);
                    spi = rgb8g_2 | rgb7g | rgb6g | rgb5g | rgb4g | rgb3g;
                    __delay_ms(2);
                    spi = rgb2g | rgb1g;
                    __delay_us(2);
                    spi = led1 | led2 | led3 | led4 | led5 | led6 | led7 | led8;
                    __delay_ms(2);
                    latch = 1;

                latch = 0;
                __delay_us(2);
                spi = rgb8b;
                __delay_us(2);
                spi = rgb7b | rgb6b | rgb5b | rgb4b | rgb3b;
                __delay_ms(2);
                spi = rgb1b | rgb2b | led16_1;
                __delay_us(2);
                spi = led9 | led10 | led11 | led12 | led13 | led14 | led15 | led16_2 ;
                __delay_ms(2);
                latch = 1;
                 __delay_ms(delayvar);

                 latch = 0;
                __delay_us(2);
                spi = 0;
                __delay_us(2);
                spi = rgb8r | rgb7r | rgb6r | rgb5r | rgb4r | rgb3r_1;
                __delay_ms(2);
                spi = rgb3r_2 | rgb1r | rgb2r | led17 | led18 | led19 |led20 | led21 | led22 | led23;
                __delay_us(2);
                spi = 0;
                __delay_ms(2);
                latch = 1;
                 __delay_ms(delayvar);

                 loopIT++;
            }


            break;
        case 6: //shield break

            latch = 0;
                __delay_us(2);
                spi = 0;
                __delay_us(2);
                spi = 0;
                __delay_ms(2);
                spi = 0;
                __delay_us(2);
                spi = 0;
                __delay_ms(2);
                latch = 1;
                 __delay_ms(delayvar);

            break;
        case 7: //cheat
            break;
        case 8: //mime
             latch = 0;
            __delay_us(2);
            spi = rgb8g_1;
            __delay_us(2);
            spi = rgb8g_2 | rgb7g | rgb6g | rgb5g | rgb4g | rgb3g;
            __delay_ms(2);
            spi = rgb2g | rgb1g;
            __delay_us(2);
            spi = 0 ;
            __delay_ms(2);
            latch = 1;

            break;
    
        case 9: //start-up
            latch = 0;
            __delay_us(2);
            spi = 0;
            __delay_us(2);
            spi = 0;
            __delay_ms(2);
            spi = led17;
            __delay_us(2);
            spi = led1 | led9 ;
            __delay_ms(2);
            latch = 1;
            __delay_ms(delayvar);

            latch = 0;
            __delay_us(2);
            spi = 0;
            __delay_us(2);
            spi = 0;
            __delay_ms(2);
            spi = led17 | led18;
            __delay_us(2);
            spi = led1 | led2 | led9 | led10 ;
            __delay_ms(2);
            latch = 1;
            __delay_ms(delayvar);

            latch = 0;
            __delay_us(2);
            spi = 0;
            __delay_us(2);
            spi = 0;
            __delay_ms(2);
            spi = led17 | led18 | led19;
            __delay_us(2);
            spi = led1 | led2 |led3 | led9 |led10 | led11 ;
            __delay_ms(2);
            latch = 1;
            __delay_ms(delayvar);

            latch = 0;
            __delay_us(2);
            spi = 0;
            __delay_us(2);
            spi = 0;
            __delay_ms(2);
            spi = led17 | led18 | led19 | led20;
            __delay_us(2);
            spi = led1 | led2 |led3 | led9 |led10 | led11 | led4 | led12 ;
            __delay_ms(2);
            latch = 1;
            __delay_ms(delayvar);

            latch = 0;
            __delay_us(2);
            spi = 0;
            __delay_us(2);
            spi = 0;
            __delay_ms(2);
            spi = led17 | led18 | led19 | led20 | led21;
            __delay_us(2);
            spi = led1 | led2 |led3 | led9 | led10 | led11 | led4 | led12 | led5 | led13 ;
            __delay_ms(2);
            latch = 1;
            __delay_ms(delayvar);

            latch = 0;
            __delay_us(2);
            spi = 0;
            __delay_us(2);
            spi = 0;
            __delay_ms(2);
            spi =  led17 | led18 | led19 | led20 | led21 | led22;
            __delay_us(2);
            spi = led1 | led2 |led3 | led9 | led10 | led11 | led4 | led12 | led5 | led13 | led6 | led14 ;
            __delay_ms(2);
            latch = 1;
            __delay_ms(delayvar);

            latch = 0;
            __delay_us(2);
            spi = 0;
            __delay_us(2);
            spi = 0;
            __delay_ms(2);
            spi = led17 | led18 | led19 | led20 | led21 | led22 | led23;
            __delay_us(2);
            spi = led1 | led2 |led3 | led9 | led10 | led11 | led4 | led12 | led5 | led13 | led6 | led14 | led7 | led15 ;
            __delay_ms(2);
            latch = 1;
            __delay_ms(delayvar);

            latch = 0;
            __delay_us(2);
            spi = 0;
            __delay_us(2);
            spi = 0;
            __delay_ms(2);
            spi = led17 | led18 | led19 | led20 | led21 | led22 | led23 | led16_1 | led24;
            __delay_us(2);
            spi = led1 | led2 |led3 | led9 | led10 | led11 | led4 | led12 | led5 | led13 | led6 | led14 | led7 | led15 | led8 | led16_2 ;
            __delay_ms(2);
            latch = 1;
            __delay_ms(delayvar);

            latch = 0;
            __delay_us(2);
            spi = 0;
            __delay_us(2);
            spi = 0;
            __delay_ms(2);
            spi =  led18 | led19 | led20 | led21 | led22 | led23 | led16_1 | led24;
            __delay_us(2);
            spi =  led2 |led3 |led10 | led11 | led4 | led12 | led5 | led13 | led6 | led14 | led7 | led15 | led8 | led16_2 ;
            __delay_ms(2);
            latch = 1;
            __delay_ms(delayvar);

            latch = 0;
            __delay_us(2);
            spi = 0;
            __delay_us(2);
            spi = 0;
            __delay_ms(2);
            spi =   led19 | led20 | led21 | led22 | led23 | led16_1 | led24;
            __delay_us(2);
            spi =  led3  | led11 | led4 | led12 | led5 | led13 | led6 | led14 | led7 | led15 | led8 | led16_2 ;
            __delay_ms(2);
            latch = 1;
            __delay_ms(delayvar);

            latch = 0;
            __delay_us(2);
            spi = 0;
            __delay_us(2);
            spi = 0;
            __delay_ms(2);
            spi =  led20 | led21 | led22 | led23 | led16_1 | led24;
            __delay_us(2);
            spi =  led4 | led12 | led5 | led13 | led6 | led14 | led7 | led15 | led8 | led16_2 ;
            __delay_ms(2);
            latch = 1;
            __delay_ms(delayvar);

            latch = 0;
            __delay_us(2);
            spi = 0;
            __delay_us(2);
            spi = 0;
            __delay_ms(2);
            spi =   led21 | led22 | led23 | led16_1 | led24;
            __delay_us(2);
            spi =   led5 | led13 | led6 | led14 | led7 | led15 | led8 | led16_2 ;
            __delay_ms(2);
            latch = 1;
            __delay_ms(delayvar);

            latch = 0;
            __delay_us(2);
            spi = 0;
            __delay_us(2);
            spi = 0;
            __delay_ms(2);
            spi =    led22 | led23 | led16_1 | led24;
            __delay_us(2);
            spi =    led6 | led14 | led7 | led15 | led8 | led16_2 ;
            __delay_ms(2);
            latch = 1;
            __delay_ms(delayvar);

            latch = 0;
            __delay_us(2);
            spi = 0;
            __delay_us(2);
            spi = 0;
            __delay_ms(2);
            spi =     led23 | led16_1 | led24;
            __delay_us(2);
            spi =     led7 | led15 | led8 | led16_2 ;
            __delay_ms(2);
            latch = 1;
            __delay_ms(delayvar);

            latch = 0;
            __delay_us(2);
            spi = 0;
            __delay_us(2);
            spi = 0;
            __delay_ms(2);
            spi =   led16_1 | led24;
            __delay_us(2);
            spi =   led8 | led16_2 ;
            __delay_ms(2);
            latch = 1;
            __delay_ms(delayvar);

            latch = 0;
            __delay_us(2);
            spi = 0;
            __delay_us(2);
            spi = 0;
            __delay_ms(2);
            spi =   0;
            __delay_us(2);
            spi =   0;
            __delay_ms(2);
            latch = 1;
            __delay_ms(delayvar);
            break;

            case 10:

                latch = 0;
                __delay_us(2);
                spi = rgb8g_1;
                __delay_us(2);
                spi = rgb8r | rgb7r | rgb6r | rgb5r | rgb4r | rgb3r_1 | rgb8g_2 | rgb7g | rgb6g | rgb5g | rgb4g | rgb3g;
                __delay_ms(2);
                spi = rgb2g | rgb1g | rgb3r_2 | rgb1r;
                __delay_us(2);
                spi = 0;
                __delay_ms(2);
                latch = 1;

                break;

    }
}