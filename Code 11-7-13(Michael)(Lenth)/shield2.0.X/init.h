void init( void )
{
    //*********************************************************
    OSCCONbits.COSC = 0b000; //Internal Fast RC Oscillator
    //Instruction clock speed(FCY) = 3685000
    //Oscillator Speed = 7.37 Mhz
    CLKDIVbits = 0; // Not dividing the clock
    CORCONbits.IPL3 = 0; //Interrupts enabled
    RCONbits.SWDTEN = 0; //Disable WDT
    //*********************************************************

    //*********************************************************
    AD1PCFGL = 0xFFFF;//Set all pins to digital
    PMD1bits.AD1MD = 1;//ADC Disabled.
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
    //*********************************************************

    //HP LED's
    TRISAbits.TRISA1 = 0;
    TRISAbits.TRISA0 = 0;
    TRISBbits.TRISB15 = 0;
    TRISBbits.TRISB14 = 0;
    TRISAbits.TRISA7 = 0;
    TRISAbits.TRISA10 = 0;
    //*********************************************************

    //SPI
    IEC0bits.SPI1IE = 0; //Disable the Interrupt
    SPI1CON1bits.DISSCK = 0; //Internal Serial Clock is Enabled
    SPI1CON1bits.DISSDO = 0; //SDOx pin is controlled by the module
    SPI1CON1bits.MODE16 = 1; //Communication is word-wide (16 bits)
    SPI1CON1bits.SMP = 0; //Input Data is sampled at the middle of data output time
    SPI1CON1bits.CKE = 0; //Serial output data changes on transition from
                          //Idle clock state to active clock state
    SPI1CON1bits.CKP = 0; //Idle state for clock is a low level;
                          //active state is a high level
    SPI1CON1bits.MSTEN = 1; //Master Mode Enabled
    SPI1STATbits.SPIEN = 1; //Enable SPI Module

    __builtin_write_OSCCONL(OSCCON & ~(1<<6)); //Unlock peripheral pin select
    RPOR6bits.RP13R = 0b01000; //Set RP13 to SCK1
    RPINR20bits.SDI1R = 12; //Set RP12 to SDI
    RPOR5bits.RP11R = 0b00111; //Set RP11 to SDO
    RPOR5bits.RP10R = 0b01001; //Set RP10 to SS1
    __builtin_write_OSCCONL(OSCCON | (1<<6)); //Lock peripheral pin select
    //*********************************************************

    //CAN Pin Select
    __builtin_write_OSCCONL(OSCCON & ~(1<<6)); //Unlock peripheral pin select
    RPINR26bits.C1RXR = 25; //Set RP25 to CAN1 receive
    RPOR12bits.RP24R = 0b10000; //Set RP24 to CAN1 transmit
    __builtin_write_OSCCONL(OSCCON | (1<<6)); //Lock peripheral pin select
    //*********************************************************

    //IR (Input Capture)
    //Initialize Capture Modules 1,2,7
    IC1CONbits.ICM= 0b001; // Disable Input Capture 1 module
    IC1CONbits.ICTMR= 1; // Select Timer2 as the IC1 Time base
    IC1CONbits.ICI= 0b00; // Interrupt on every second capture event
    IC1CONbits.ICM= 0b011; // Generate capture event on every Rising edge

    IC2CONbits.ICM= 0b001; // Disable Input Capture 2 module
    IC2CONbits.ICTMR= 0; // Select Timer3 as the IC2 Time base
    IC2CONbits.ICI= 0b00; // Interrupt on every second capture event
    IC2CONbits.ICM= 0b011; // Generate capture event on every Rising edge

    IC7CONbits.ICM= 0b001; // Disable Input Capture 7 module
    IC7CONbits.ICTMR= 0; // Select Timer3 as the IC7 Time base
    IC7CONbits.ICI= 0b00; // Interrupt on every second capture event
    IC7CONbits.ICM= 0b011; // Generate capture event on every Rising edge

    //Enable Capture Interrupts and Timers
    IPC0bits.IC1IP = 7; // Setup IC1 interrupt priority level
    IFS0bits.IC1IF = 0; // Clear IC1 Interrupt Status Flag
    IEC0bits.IC1IE = 1; // Enable IC1 interrupt

    IPC1bits.IC2IP = 7; // Setup IC2 interrupt priority level
    IFS0bits.IC2IF = 0; // Clear IC2 Interrupt Status Flag
    IEC0bits.IC2IE = 1; // Enable IC2 interrupt

    IPC5bits.IC7IP = 7; // Setup IC7 interrupt priority level
    IFS1bits.IC7IF = 0; // Clear IC7 Interrupt Status Flag
    IEC1bits.IC7IE = 1; // Enable IC7 interrupt

    __builtin_write_OSCCONL(OSCCON & ~(1<<6)); //Unlock peripheral pin select
    RPINR7bits.IC1R = 23; //Set Input Capture 1 to RP23
    RPINR7bits.IC2R = 22; //Set Input Capture 2 to RP22
    RPINR10bits.IC7R = 9; //Set Input Capture 7 to RP9
    __builtin_write_OSCCONL(OSCCON | (1<<6)); //Lock peripheral pin select

    TRISBbits.TRISB8 = 0; //Set RB8 to output
    //*********************************************************

    //Push Buttons
    CNEN2bits.CN23IE = 1;//Enable CN 23 for interrupt detect
    CNEN2bits.CN24IE = 1;//Enable CN 24 for interrupt detect
    IEC1bits.CNIE = 0; // Enable CN interrupts
    IFS1bits.CNIF = 0; // Reset CN interrupt
    //*********************************************************

    //Timer4 (Countdown Timer)
    T4CONbits.TON = 0; // Disable Timer
    T4CONbits.TCS = 0; // Select internal instruction cycle clock
    T1CONbits.TGATE = 0; // Disable Gated Timer mode
    T1CONbits.TCKPS = 0b00; // Select 1:1 Prescaler
    //TMR1 = 0x00; // Clear timer register
    //PR1 = 1000000; // Load the period value

    //Interrupt Setup
    IPC6bits.T4IP = 6; // Setup TMR4 interrupt priority level
    IFS1bits.T4IF = 0; // Clear TMR4 Interrupt Status Flag
    IEC1bits.T4IE = 1; // Enable TMR4 interrupt
    //*********************************************************


    //Interrupt Vector Natural Order (per our project)
    //IC1 = 9
    //IC2 = 13
    //CN  = 27
    //IC7 = 30
}