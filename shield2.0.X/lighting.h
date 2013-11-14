void __attribute__ ((interrupt,no_auto_psv)) _SPI1Interrupt()
{
    IFS0bits.SPI1IF =0; //clear the interrupt flag
} //You can set up a timer module to give them spacing.

void lightTransmit(char light)
{
    unsigned int loopIT = 0;

            spi = 0x0002;
            __delay_us(3);
            spi = 0x3fff;
            __delay_us(20);
            spi = 0xff1f;
            __delay_us(3);
            spi = 0xffff;
            __delay_us(20);
            latch = 1;
            __delay_us(20);
            latch = 0;
            __delay_us(4);

    switch(light)
    {
        case 1: //absorb

            spi = 0x0001;
            __delay_us(3);
            spi = 0xc000;
            __delay_us(20);
            spi = 0x0e92;
            __delay_us(3);
            spi = 0x4924;
            __delay_us(20);
            latch = 1;
            __delay_us(20);
            latch = 0;
            __delay_ms(100);

            spi = 0x0000;
            __delay_us(3);
            spi = 0xc000;
            __delay_us(20);
            spi = 0x0c92;
            __delay_us(3);
            spi = 0x4924;
            __delay_us(20);
            latch = 1;
            __delay_us(20);
            latch = 0;
            __delay_ms(100);

            spi = 0x0000;
            __delay_us(3);
            spi = 0xc000;
            __delay_us(20);
            spi = 0x3092;
            __delay_us(3);
            spi = 0x4924;
            __delay_us(20);
            latch = 1;
            __delay_us(20);
            latch = 0;
            __delay_ms(100);

            spi = 0x0000;
            __delay_us(3);
            spi = 0x3000;
            __delay_us(20);
            spi = 0xc092;
            __delay_us(3);
            spi = 0x4924;
            __delay_us(20);
            latch = 1;
            __delay_us(20);
            latch = 0;
            __delay_ms(100);

            spi = 0x0000;
            __delay_us(3);
            spi = 0x0c03;
            __delay_us(20);
            spi = 0x0092;
            __delay_us(3);
            spi = 0x4924;
            __delay_us(20);
            latch = 1;
            __delay_us(20);
            latch = 0;
            __delay_ms(100);

            spi = 0x0000;
            __delay_us(3);
            spi = 0x03c;
            __delay_us(20);
            spi = 0x0092;
            __delay_us(3);
            spi = 0x4924;
            __delay_us(20);
            latch = 1;
            __delay_us(20);
            latch = 0;
            __delay_ms(100);
            break;
        case 2: //countdown
            switch(countVar)
            {
                __delay_ms(50);
                case 1:
                    spi = 0x0001;
                    __delay_us(3);
                    spi = 0xc000;
                    __delay_us(3);
                    spi = 0x0092;
                    __delay_us(3);
                    spi = 0x4924;
                    __delay_us(3);
                    latch = 1;
                    __delay_us(4);
                  latch = 0;
                    __delay_us(4);
                    break;
                case 2:
                    spi = 0x0001;
                    __delay_us(3);
                    spi = 0xfc00;
                    __delay_us(3);
                    spi = 0x0092;
                    __delay_us(3);
                    spi = 0x4924;
                    __delay_us(3);
                    latch = 1;
                    __delay_us(4);
                  latch = 0;
                    __delay_us(4);
                    break;
                case 3:
                    spi = 0x0001;
                    __delay_us(3);
                    spi = 0xffc0;
                    __delay_us(3);
                    spi = 0x0092;
                    __delay_us(3);
                    spi = 0x4924;
                    __delay_us(3);
                    latch = 1;
                    __delay_us(4);
                  latch = 0;
                    __delay_us(4);
                    break;
                case 4:
                    spi = 0x0001;
                    __delay_us(3);
                    spi = 0xfffc;
                    __delay_us(3);
                    spi = 0x0092;
                    __delay_us(3);
                    spi = 0x4924;
                    __delay_us(3);
                    latch = 1;
                    __delay_us(4);
                  latch = 0;
                    __delay_us(4);
                    break;
                case 5:
                    spi = 0x0001;
                    __delay_us(3);
                    spi = 0xffff;
                    __delay_us(3);
                    spi = 0xfe92;
                    __delay_us(3);
                    spi = 0x4924;
                    __delay_us(3);
                    latch = 1;
                    __delay_us(4);
                  latch = 0;
                    __delay_us(4);
                    break;
            }
            break;
        case 3: //attack reflect
             spi = 0x0000;
            __delay_us(3);
            spi = 0x003c;
            __delay_us(3);
            spi = 0x0024;
            __delay_us(3);
            spi = 0x9249;
            __delay_us(20);
            latch = 1;
            __delay_us(20);
            latch = 0;
            __delay_ms(200);

            spi = 0x0000;
            __delay_us(3);
            spi = 0x00c3;
            __delay_us(3);
            spi = 0x0024;
            __delay_us(3);
            spi = 0x9249;
            __delay_us(20);
            latch = 1;
            __delay_us(20);
            latch = 0;
            __delay_ms(200);

            spi = 0x0000;
            __delay_us(3);
            spi = 0x0300;
            __delay_us(3);
            spi = 0xc024;
            __delay_us(3);
            spi = 0x9249;
            __delay_us(20);
            latch = 1;
            __delay_us(20);
            latch = 0;
            __delay_ms(200);

            spi = 0x0000;
            __delay_us(3);
            spi = 0x0c00;
            __delay_us(3);
            spi = 0x3024;
            __delay_us(3);
            spi = 0x9249;
            __delay_us(20);
            latch = 1;
            __delay_us(20);
            latch = 0;
            __delay_ms(200);

            spi = 0x0000;
            __delay_us(3);
            spi = 0x3000;
            __delay_us(3);
            spi = 0x0c24;
            __delay_us(3);
            spi = 0x9249;
            __delay_us(20);
            latch = 1;
            __delay_us(20);
            latch = 0;
            __delay_ms(200);

            spi = 0x0001;
            __delay_us(3);
            spi = 0xc000;
            __delay_us(3);
            spi = 0x0624;
            __delay_us(3);
            spi = 0x9249;
            __delay_us(20);
            latch = 1;
            __delay_us(20);
            latch = 0;
            __delay_ms(200);
            break;
        case 4: //heal
            spi = 0x0000;
            __delay_us(3);
            spi = 0x003c;
            __delay_us(3);
            spi = 0x0049;
            __delay_us(3);
            spi = 0x2492;
            __delay_us(20);
            latch = 1;
            __delay_us(20);
            latch = 0;
            __delay_ms(200);

            spi = 0x0000;
            __delay_us(3);
            spi = 0x00c3;
            __delay_us(3);
            spi = 0x0049;
            __delay_us(3);
            spi = 0x2492;
            __delay_us(20);
            latch = 1;
            __delay_us(20);
            latch = 0;
            __delay_ms(200);

            spi = 0x0000;
            __delay_us(3);
            spi = 0x0300;
            __delay_us(3);
            spi = 0xc049;
            __delay_us(3);
            spi = 0x2492;
            __delay_us(20);
            latch = 1;
            __delay_us(20);
            latch = 0;
            __delay_ms(200);

            spi = 0x0000;
            __delay_us(3);
            spi = 0x0c00;
            __delay_us(3);
            spi = 0x3049;
            __delay_us(3);
            spi = 0x2492;
            __delay_us(20);
            latch = 1;
            __delay_us(20);
            latch = 0;
            __delay_ms(200);

            spi = 0x0000;
            __delay_us(3);
            spi = 0x3000;
            __delay_us(3);
            spi = 0x0c49;
            __delay_us(3);
            spi = 0x2492;
            __delay_us(20);
            latch = 1;
            __delay_us(20);
            latch = 0;
            __delay_ms(200);

            spi = 0x0001;
            __delay_us(3);
            spi = 0xc000;
            __delay_us(3);
            spi = 0x0649;
            __delay_us(3);
            spi = 0x2492;
            __delay_us(20);
            latch = 1;
            __delay_us(20);
            latch = 0;
            __delay_ms(200);
            break;
        case 5: //take damage
            while(loopIT < 2)
            {
             spi = 0x0001;
             __delay_us(3);
             spi = 0x5555;
             __delay_us(3);
             spi = 0x5892;
             __delay_us(3);
             spi = 0x4924;
             __delay_us(3);
             latch = 1;
             __delay_us(4);
             latch = 0;
             __delay_ms(200);


             spi = 0x0000;
             __delay_us(3);
             spi = 0xaaaa;
             __delay_us(3);
             spi = 0xaa24;
             __delay_us(3);
             spi = 0x9249;
             __delay_us(3);
             latch = 1;
             __delay_us(4);
             latch = 0;
             __delay_ms(200);
             loopIT++;
            }
            break;
        case 6: //shield break
            while(loopIT < 6)
            {
             spi = 0x0000;
             __delay_us(3);
             spi = 0x0000;
             __delay_us(3);
             spi = 0x0092;
             __delay_us(3);
             spi = 0x4924;
             __delay_us(3);
             latch = 1;
             __delay_us(4);
             latch = 0;
             __delay_ms(200);


             spi = 0x0001;
             __delay_us(3);
             spi = 0xffff;
             __delay_us(3);
             spi = 0xfe24;
             __delay_us(3);
             spi = 0x9249;
             __delay_us(3);
             latch = 1;
             __delay_us(4);
             latch = 0;
             __delay_ms(200);
             loopIT++;
            }
            break;
        case 7: //cheat
            break;
        case 8: //mime
            break;
    }

    if(light != 2)
    {
        spi = 0x0000;
        __delay_us(3);
            spi = 0x0000;
            __delay_us(20);
            spi = 0x0092;
            __delay_us(3);
            spi = 0x4924;
            __delay_us(20);
            latch = 1;
            __delay_us(20);
            latch = 0;
            __delay_us(4);
    }
}

