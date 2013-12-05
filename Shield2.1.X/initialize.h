//Michael Lenth
void init( void )
{
    //*********************************************************
    //OSCCONbits.COSC = 0b000; //Internal Fast RC Oscillator
    //Instruction clock speed(FCY) = 3685000
    //Oscillator Speed = 7.37 Mhz
    //CLKDIV = 0x0000; // Not dividing the clock
    CORCONbits.IPL3 = 0; //Interrupts enabled
    RCONbits.SWDTEN = 0; //Disable WDT
    //*********************************************************

    //*********************************************************
    AD1PCFGL = 0xFFFF;//Set all pins to digital
    PMD1bits.AD1MD = 1;//ADC Disabled.
    //*********************************************************
    //DEBUG LED
    TRISAbits.TRISA9 = 0;//LED Start
    TRISCbits.TRISC3 = 0;
    TRISCbits.TRISC4 = 0;
    LATAbits.LATA9 = 1;
    LATCbits.LATC3 = 1;
    LATCbits.LATC4 = 1;
    //*********************************************************
    
    //Audio Setup
    TRISBbits.TRISB4 = 0;//MC1
    TRISAbits.TRISA8 = 0;//MC2
    TRISAbits.TRISA3 = 0;//MC3
    TRISAbits.TRISA2 = 0;//MC4
    TRISCbits.TRISC2 = 0;//MC5
    TRISCbits.TRISC1 = 0;//MC6
    TRISCbits.TRISC0 = 0;//MC7
    TRISBbits.TRISB3 = 0;//MC8

    //Audio Initialize
    MC1 = 1;//Set MC1 high (off).
    MC2 = 1;//Set MC2 high (off).
    MC3 = 1;//Set MC3 high (off).
    MC4 = 1;//Set MC4 high (off).
    MC5 = 1;//Set MC5 high (off).
    MC6 = 1;//Set MC6 high (off).
    MC7 = 1;//Set MC7 high (off).
    MC8 = 1;//Set MC8 high (off).
    //*********************************************************

    //HP LED's
    TRISAbits.TRISA1 = 0;//HP Light 1 is output.
    TRISAbits.TRISA0 = 0;//HP Light 2 is output.
    TRISBbits.TRISB15 = 0;//HP Light 3 is output.
    TRISBbits.TRISB14 = 0;//HP Light 4 is output.
    TRISAbits.TRISA7 = 0;//HP Light 5 is output.
    TRISAbits.TRISA10 = 0;//HP Light 6 is output.

    LATAbits.LATA1 = 1;//HP Light 1 is on.
    LATAbits.LATA0 = 1;//HP Light 2 is on.
    LATBbits.LATB15 = 1;//HP Light 3 is on.
    LATBbits.LATB14 = 1;//HP Light 4 is on.
    LATAbits.LATA7 = 1;//HP Light 5 is on.
    LATAbits.LATA10 = 1;//HP Light 6 is on.
    //*********************************************************

    //SPI
    TRISBbits.TRISB13 = 0;//RB13 is Latch
    IFS0bits.SPI1IF = 0; //Clear the Interrupt Flag
    IEC0bits.SPI1IE = 0; //Disable the Interrupt
    // SPI1CON1 Register Settings
    // Set Prescalar bits. SPI supports 10MHz max.
    SPI1CON1bits.PPRE = 0b11; //Primary prescalar = 1:1
    SPI1CON1bits.SPRE = 0b100; //Secondary prescalar = 4:1
    SPI1CON1bits.DISSCK = 0; //Internal Serial Clock is Enabled
    SPI1CON1bits.DISSDO = 0; //SDOx pin is controlled by the module
    SPI1CON1bits.MODE16 = 1; //Communication is word-wide (16 bits)
    SPI1CON1bits.SMP = 0; //Input Data is sampled at the middle of data output time
    SPI1CON1bits.CKE = 0; //Serial output data changes on transition from-
    //Idle clock state to active clock state
    SPI1CON1bits.CKP = 0; //Idle state for clock is a low level;
    //active state is a high level
    SPI1CON1bits.MSTEN = 1; //Master Mode Enabled
    SPI1STATbits.SPIEN = 1; //Enable SPI Module
    //spi = data[i];
    //Interrupt Controller Settings
    IFS0bits.SPI1IF = 0; //Clear the Interrupt Flag
    IEC0bits.SPI1IE = 1; //Enable the Interrupt
    
    __builtin_write_OSCCONL(OSCCON & ~(1<<6)); //Unlock peripheral pin select
    RPOR6bits.RP12R = 0b01000; //Set RP12 to SCK1
    //RPINR20bits.SDI1R = 12; //Set RP12 to SDI
    RPOR5bits.RP11R = 0b00111; //Set RP11 to SDO
    //RPOR5bits.RP10R = 0b01001; //Set RP10 to SS1
    __builtin_write_OSCCONL(OSCCON | (1<<6)); //Lock peripheral pin select

//    __delay_us(20);
//    spi = 0x011f;
//    __delay_us(2);
//    spi = 0xffff;
//    __delay_us(20);
//    latch = 1;
//    __delay_us(20);
//    latch = 0;
//    __delay_us(20);
//    spi = 0x0000;
//    __delay_us(2);
//    spi = 0x0000;
//    __delay_us(20);
//    latch = 1;
//    __delay_us(20);
//    latch = 0;
    
    //*********************************************************

    //CAN Pin Select
    TRISCbits.TRISC9 = 1; /// Set RC9 as an input
    TRISCbits.TRISC8 = 0;  // Set RC8 as
    __builtin_write_OSCCONL(OSCCON & ~(1<<6)); //Unlock peripheral pin select
    RPINR26bits.C1RXR = 25; //Set RP25 to CAN1 receive
    RPOR12bits.RP24R = 0b10000; //Set RP24 to CAN1 transmit
    __builtin_write_OSCCONL(OSCCON | (1<<6)); //Lock peripheral pin select
    LATCbits.LATC9 = 0;
    LATCbits.LATC8 = 0;
    IEC2bits.C1IE = 1; //CAN Receive Interrupt Enable
    C1INTEbits.TBIE = 1; //TX DMA Interrupt Enable
    C1INTEbits.RBIE = 1; //RX DMA Interrupt Enable
    //*********************************************************

    //IR (Input Capture)
    //Initialize Capture Modules 1,2,7

    IC1CONbits.ICM= 0b00; // Disable Input Capture 1 module
    IC1CONbits.ICTMR= 1; // Select Timer2 as the IC1 Time base
    IC1CONbits.ICI= 0b01; // Interrupt on every second capture event
    IC1CONbits.ICM= 0b010; // Generate capture event on every Rising edge
    // Enable Capture Interrupt And Timer2
    IPC0bits.IC1IP = 1; // Setup IC1 interrupt priority level
    IFS0bits.IC1IF = 0; // Clear IC1 Interrupt Status Flag
    IEC0bits.IC1IE = 1; // Enable IC1 interrupt

    IC2CONbits.ICM= 0b00; // Disable Input Capture 1 module
    IC2CONbits.ICTMR= 1; // Select Timer2 as the IC1 Time base
    IC2CONbits.ICI= 0b01; // Interrupt on every second capture event
    IC2CONbits.ICM= 0b011; // Generate capture event on every Rising edge
    // Enable Capture Interrupt And Timer2
    IPC1bits.IC2IP = 1; // Setup IC1 interrupt priority level
    IFS0bits.IC2IF = 0; // Clear IC1 Interrupt Status Flag
    IEC0bits.IC2IE = 1; // Enable IC1 interrupt

__builtin_write_OSCCONL(OSCCON & ~(1<<6)); //Unlock peripheral pin select
    RPINR7bits.IC1R = 6; //Set Input Capture 1 to RP6
    RPINR7bits.IC2R = 6; //Set Input Capture 1 to RP6
__builtin_write_OSCCONL(OSCCON | (1<<6)); //Lock peripheral pin select

TRISBbits.TRISB9 = 0;


//Setup Timer 2 for the IC module
    PR2 = 0xFFFF;
    Fall_Time = 0;
    Rise_Time = 0;
    T2CON = 0x8010;

    TRISBbits.TRISB8 = 0; //Set RB8 to output
   
    //*********************************************************

    //Push Buttons
    TRISCbits.TRISC5 = 1;//Set Push Button pin to input
    TRISBbits.TRISB7 = 1;//Set Push Button pin to input
    LATCbits.LATC5 = 0;// Off
    LATBbits.LATB7 = 0;// Off
//    CNPU2bits.CN23PUE = 1;
//    CNPU2bits.CN24PUE = 1;
    CNEN2bits.CN23IE = 1;//Enable CN 23 for interrupt detect
    CNEN2bits.CN26IE = 1;//Enable CN 24 for interrupt detect
    IPC4bits.CNIP = 5; //IC>CN>T4
    IEC1bits.CNIE = 0; // Enable CN interrupts
    IFS1bits.CNIF = 0; // Reset CN interrupt
    //*********************************************************

    //Timer4 (Countdown Timer)
    T4CONbits.TON = 0; // Disable Timer
    T4CONbits.TCS = 0; // Select internal instruction cycle clock
    T4CONbits.TGATE = 0; // Disable Gated Timer mode
    T4CONbits.TCKPS = 0b00; // Select 1:1 Prescaler
    //TMR4 = 0x00; // Clear timer register
    //PR4 = 1000000; // Load the period value

    //Interrupt Setup
    IPC6bits.T4IP = 3; // Setup TMR4 interrupt priority level
    IFS1bits.T4IF = 0; // Clear TMR4 Interrupt Status Flag
    IEC1bits.T4IE = 1; // Enable TMR4 interrupt
    //*********************************************************


    //Interrupt Vector Natural Order (per our project)
    //IC1 = 9
    //IC2 = 13
    //CN  = 27
    //IC7 = 30
}

void configPLL(void)
{
     int M = 43;
     int N1 = 2;
     int N2 = 2;
    // Configure PLL prescaler, PLL postscaler, PLL divisor
    PLLFBD = M-2; // M = 43
    CLKDIVbits.PLLPOST=N1-2; // N1 = 2
    CLKDIVbits.PLLPRE=N2-2; // N2 = 2
    // Initiate Clock Switch to Internal FRC with PLL (NOSC = 0b001)
    __builtin_write_OSCCONH(0x01);
    __builtin_write_OSCCONL(0x01);
    // Wait for Clock switch to occur
    while (OSCCONbits.COSC != 0b001);
    // Wait for PLL to lock
    while(OSCCONbits.LOCK!=1) {};

}