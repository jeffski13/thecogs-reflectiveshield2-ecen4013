/*
 * File:   IR_Transmit.c
 * Author: Spencer Gat Dayum Hood
 *
 * Created on October 15, 2013, 1:11 AM
 */

/*
 *Reflective Shield 2.0
 *The COGS
 *IR Transmit Prototype Code
 */

void singleBURSTON(void)
{


        iRLED = ON; //Turns on IR LED
        __delay_us(9);

        iRLED = OFF; // Turns off IR LED
        
      __delay_us(8);
    }

 void singleBURSTOFF(void)
{


    //1.1 turn all LED ON
    iRLED = OFF; // Turns off IR LED
    __delay_us(9);
    // 1.2 turn all LED OFF
    iRLED = OFF; // Turns off IR LED

    __delay_us(8);
}

void burstOFF(int length)
{
   int x;
    for(x = 0; x < length; x++)
    {
        singleBURSTOFF();
    }
}
void burstON(int length)
{
    int x;
    for(x = 0; x < length; x++)
    {
        singleBURSTON();
    }
}
void iRTX(char iRChoice)
{
    if(iRChoice == attReflect)
    {
        //Start packet
        burstON(10);
        burstOFF(140);
        //Data packet
        burstON(20);
        burstOFF(130);
        //Redundant Data Packet
        burstON(20);
        burstOFF(130);
        //Stop Packet
        burstON(150);
    }
     if(iRChoice == heal)
    {
        //Start packet
        burstON(10);
        burstOFF(140);
        //Data packet
        burstON(30);
        burstOFF(120);
        //Redundant Data packet
        burstON(30);
        burstOFF(120);
        //Stop packet
        burstON(150);
    }
}