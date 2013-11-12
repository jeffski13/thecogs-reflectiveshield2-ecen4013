/*Define*/
//*Audio
#ifndef defines_h
#define defines_h

#define outputAudio 0 //Will drive the output pin low
#define MC1 LATBbits.LATB4 //Audio
#define MC2 LATAbits.LATA8 //Audio
#define MC3 LATAbits.LATA3 //Audio
#define MC4 LATAbits.LATA2 //Audio
#define MC5 LATCbits.LATC2 //Audio
#define MC6 LATCbits.LATC1 //Audio
#define MC7 LATCbits.LATC0 //Audio
#define MC8 LATBbits.LATB3 //Audio

#define ON 1
#define OFF 0

#define LED0            LATAbits.LATA0 //HP LED
#define LED1            LATAbits.LATA1 //HP LED
#define LED2            LATBbits.LATB15 //HP LED
#define LED3            LATBbits.LATB14 //HP LED
#define LED4            LATAbits.LATA7 //HP LED
#define LED5            LATAbits.LATA10 //HP LED
#define TOTAL_HP        10000
#define REFLECT_BUTTON  PORTCbits.RC5
#define HEAL_BUTTON     PORTBbits.RB7
#define PRESSED         1

//#define FOSC 7370000UL //libpic30 needs these to be defined prior to inlcuding it
//#define FCY (FOSC/2)
#define iRLED LATBbits.LATB8 //IR

#define sdo 0b00111 //peripheral register value
#define sco 0b01000
#define spi SPI1BUF
#define latch LATBbits.LATB12

#endif