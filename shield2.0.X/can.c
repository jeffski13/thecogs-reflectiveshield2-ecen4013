/**********************************************************************
*   MAIN PROGRAM - Includes some Functions below main and declaration of ecan1msg buf in DMA space
*************************************************************************************************/

#if defined(__dsPIC33F__)
#include "p33fxxxx.h"
#elif defined(__PIC24H__)
#include "p24hxxxx.h"
#endif

#define FCY 40000000UL
#define LED1 PORTBbits.RB10
#define LED2 PORTBbits.RB11
#define LED3 PORTBbits.RB12
#define ON 1
#define OFF 0

#include "CAN_Config.h"
#include "common.h"
#include "configs.h"
#include <libpic30.h>

// Define ECAN Message Buffers
ECAN1MSGBUF ecan1msgBuf __attribute__((space(dma),aligned(ECAN1_MSG_BUF_LENGTH*16)));


// CAN Messages in RAM
mID rx_ecan1message;


// Prototype Declaration
void clearIntrflags(void);
void ecan1WriteMessage(void);

int main(void)
{

/* Configure Oscillator Clock Source 	*/
	configPLL();
/* Clear Interrupt Flags 				*/
	clearIntrflags();
   
/* ECAN1 Initialisation
   Configure DMA Channel 0 for ECAN1 Transmit
   Configure DMA Channel 2 for ECAN1 Receive */
	ecan1Init();
	dma0init();
	dma2init();

    /* Enable ECAN1 Interrupt */

	IEC2bits.C1IE = 1;
	C1INTEbits.TBIE = 1;
	C1INTEbits.RBIE = 1;
        __builtin_write_OSCCONL(OSCCON & ~(1<<6));
        TRISA= 0;
        LATA = 0;

        TRISB = 0x4000;
        LATB = 0;
        AD1PCFGL = 0xffff;
        RPINR26 = 14;
        _RP15R = 0x10;
        __builtin_write_OSCCONL(OSCCON | (1<<6));
     
        LED2 = OFF;
        LED1 = OFF;
        LED3 = OFF;
    
       ecan1WriteMessage();         // sends data
       C1TR01CONbits.TXREQ0=1;
       
/* Loop infinitely */
	while (1)
        {

        }

}
 
/* ECAN1 buffer loaded with Identifiers and Data */
void ecan1WriteMessage(void)
{

/* Writing the message for Transmission
ecan1WriteTxMsgBufId(unsigned int buf, long txIdentifier, unsigned int ide, unsigned int remoteTransmit);
ecan1WriteTxMsgBufData(unsigned int buf, unsigned int dataLength, unsigned int data1, unsigned int data2, unsigned int data3, unsigned int data4);

buf -> Transmit Buffer number

txIdentifier -> SID<10:0> : EID<17:0>

ide = 0 -> Message will transmit standard identifier
ide = 1 -> Message will transmit extended identifier

remoteTransmit = 0 -> Normal message
remoteTransmit = 1 -> Message will request remote transmission

dataLength -> Data length can be from 0 to 8 bytes

data1, data2, data3, data4 -> Data words (2 bytes) each

*/
	ecan1WriteTxMsgBufId(0,25,0,0);
	ecan1WriteTxMsgBufData(0,4,0x0102,0x0102,0,0);
        LED2 = ON;
}

/******************************************************************************
*
*    Function:			rxECAN1
*    Description:       moves the message from the DMA memory to RAM
*
*    Arguments:			*message: a pointer to the message structure in RAM
*						that will store the message.
*	 Author:            Jatinder Gharoo
*
*
******************************************************************************/
void rxECAN1(mID *message)
{
	unsigned int ide=0;
	unsigned int srr=0;
	unsigned long id=0;

	/*
	Standard Message Format:
	Word0 : 0bUUUx xxxx xxxx xxxx
		     |____________|||
 			SID10:0   SRR IDE(bit 0)
	Word1 : 0bUUUU xxxx xxxx xxxx
		       |____________|
			 EID17:6
	Word2 : 0bxxxx xxx0 UUU0 xxxx
	          |_____||  |__|
	         EID5:0 RTR  DLC
	word3-word6: data bytes
	word7: filter hit code bits

	Substitute Remote Request Bit
	SRR->	"0"	 Normal Message
			"1"  Message will request remote transmission

	Extended  Identifier Bit
	IDE-> 	"0"  Message will transmit standard identifier
	   		"1"  Message will transmit extended identifier

	Remote Transmission Request Bit
	RTR-> 	"0"  Message transmitted is a normal message
			"1"  Message transmitted is a remote message
	*/
	/* read word 0 to see the message type */
	ide=ecan1msgBuf[message->buffer][0] & 0x0001;
	srr=ecan1msgBuf[message->buffer][0] & 0x0002;

	/* check to see what type of message it is */
	/* message is standard identifier */
	if(ide==0)
	{
		message->id=(ecan1msgBuf[message->buffer][0] & 0x1FFC) >> 2;
		message->frame_type=CAN_FRAME_STD;
	}
	/* mesage is extended identifier */
	else
	{
		id=ecan1msgBuf[message->buffer][0] & 0x1FFC;
		message->id=id << 16;
		id=ecan1msgBuf[message->buffer][1] & 0x0FFF;
		message->id=message->id+(id << 6);
		id=(ecan1msgBuf[message->buffer][2] & 0xFC00) >> 10;
		message->id=message->id+id;
		message->frame_type=CAN_FRAME_EXT;
	}
	/* check to see what type of message it is */
	/* RTR message */
	if(srr==1)
	{
		message->message_type=CAN_MSG_RTR;
	}
	/* normal message */
	else
	{
		message->message_type=CAN_MSG_DATA;
		message->data[0]=(unsigned char)ecan1msgBuf[message->buffer][3];
		message->data[1]=(unsigned char)((ecan1msgBuf[message->buffer][3] & 0xFF00) >> 8);
		message->data[2]=(unsigned char)ecan1msgBuf[message->buffer][4];
		message->data[3]=(unsigned char)((ecan1msgBuf[message->buffer][4] & 0xFF00) >> 8);
		message->data[4]=(unsigned char)ecan1msgBuf[message->buffer][5];
		message->data[5]=(unsigned char)((ecan1msgBuf[message->buffer][5] & 0xFF00) >> 8);
		message->data[6]=(unsigned char)ecan1msgBuf[message->buffer][6];
		message->data[7]=(unsigned char)((ecan1msgBuf[message->buffer][6] & 0xFF00) >> 8);
		message->data_length=(unsigned char)(ecan1msgBuf[message->buffer][2] & 0x000F);
	}
        if((message->data[1] == 0x01))
        {
            if((message->data[0] == 0x02))
            {
                int i = 0;
                for(i = 0; i<4; i++)
                {
                LED2=0;
                __delay_ms(125);
                LED2 =1;
                __delay_ms(125);
                }
            }
        }
}

void clearIntrflags(void)
{
/* Clear Interrupt Flags */

	IFS0=0;
	IFS1=0;
	IFS2=0;
	IFS3=0;
	IFS4=0;
}

void __attribute__((interrupt, no_auto_psv))_C1Interrupt(void)
{
	IFS2bits.C1IF = 0;        // clear interrupt flag
	if(C1INTFbits.TBIF)
    {
    	C1INTFbits.TBIF = 0;
    }

    if(C1INTFbits.RBIF)
    {
		// read the message
	    if(C1RXFUL1bits.RXFUL1==1)
	    {
	    	rx_ecan1message.buffer=1;
	    	C1RXFUL1bits.RXFUL1=0;
	    }
	    rxECAN1(&rx_ecan1message);
		C1INTFbits.RBIF = 0;
	}
}



//------------------------------------------------------------------------------
//    DMA interrupt handlers
//------------------------------------------------------------------------------

void __attribute__((interrupt, no_auto_psv)) _DMA0Interrupt(void)
{
   IFS0bits.DMA0IF = 0;          // Clear the DMA0 Interrupt Flag;
}

void __attribute__((interrupt, no_auto_psv)) _DMA1Interrupt(void)
{
   IFS0bits.DMA1IF = 0;          // Clear the DMA1 Interrupt Flag;
}

void __attribute__((interrupt, no_auto_psv)) _DMA2Interrupt(void)
{
   IFS1bits.DMA2IF = 0;          // Clear the DMA2 Interrupt Flag;
}

void __attribute__((interrupt, no_auto_psv)) _DMA3Interrupt(void)
{
   IFS2bits.DMA3IF = 0;          // Clear the DMA3 Interrupt Flag;
}
