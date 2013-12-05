//Michael Lenth
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
#define latch LATBbits.LATB13
#define CONNECTED 1
#define NOT_CONNECTED 0


// LED Addresses
// 4th word sent
#define led1    0x0003
#define led2    0x0006
#define led3    0x000C
#define led4    0x0018
#define led5    0x0030
#define led6    0x0060
#define led7    0x00C0
#define led8    0x0180
#define led9    0x0300
#define led10   0x0600
#define led11   0x0C00
#define led12   0x1800
#define led13   0x3000
#define led14   0x6000
#define led15   0xC000
#define led16_2 0x8000
//3rd word sent
#define led16_1 0x0001
#define led17   0x0003
#define led18   0x0006
#define led19   0x000C
#define led20   0x0018
#define led21   0x0030
#define led22   0x0060
#define led23   0x00C0
#define led24   0x0180

#define rgb1r   0x0600
#define rgb1g   0x0C00
#define rgb1b   0x1800

#define rgb2r   0x3000
#define rgb2g   0x6000
#define rgb2b   0xC000

#define rgb3r_2 0x8000
//2nd word
#define rgb3r_1 0x0001
#define rgb3g   0x0003
#define rgb3b   0x0006

#define rgb4r   0x000C
#define rgb4g   0x0018
#define rgb4b   0x0030

#define rgb5r   0x0060
#define rgb5g   0x00C0
#define rgb5b   0x0180

#define rgb6r   0x0300
#define rgb6g   0x0600
#define rgb6b   0x0C00

#define rgb7r   0x1800
#define rgb7g   0x3000
#define rgb7b   0x6000

#define rgb8r   0xC000
#define rgb8g_2 0x8000
//1st word
#define rgb8g_1 0x0001
#define rgb8b   0x0003

//  Outer ring  ( led1  | led2  | led3  | led4  | led5  | led6  | led7  | led8  )
//  Middle ring ( led9  | led10 | led11 | led12 | led13 | led14 | led15 | led16 )
//  Inner ring  ( led17 | led18 | led19 | led20 | led21 | led22 | led23 | led24 )

//  row1 (led1 | led9  | led17)
//  row2 (led2 | led10 | led18)
//  row3 (led3 | led11 | led19)
//  row4 (led4 | led12 | led20)
//  row5 (led5 | led13 | led21)
//  row6 (led6 | led14 | led22)
//  row7 (led7 | led15 | led23)
//  row8 (led8 | led16 | led24)

#endif