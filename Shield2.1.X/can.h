/**********************************************************************
*   MAIN PROGRAM - Includes some Functions below main and declaration of ecan1msg buf in DMA space
*************************************************************************************************/

#if defined(__dsPIC33F__)
#include "p33fxxxx.h"
#elif defined(__PIC24H__)
#include "p24hxxxx.h"
#include "common.h"
#endif


// Define ECAN Message Buffers
ECAN1MSGBUF ecan1msgBuf __attribute__((space(dma),aligned(ECAN1_MSG_BUF_LENGTH*16)));


// CAN Messages in RAM
mID rx_ecan1message;


// Prototype Declaration
void clearIntrflags(void);
void ecan1WriteMessage(unsigned int, unsigned long, unsigned long, unsigned long);


/* ECAN1 buffer loaded with Identifiers and Data */
void ecan1WriteMessage(unsigned int numOfBytes, unsigned long data1, unsigned long data2, unsigned long id)
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
	ecan1WriteTxMsgBufId(0,id,0,0);
	ecan1WriteTxMsgBufData(0,numOfBytes,data1,data2,0x0000,0x0000);
   
        C1TR01CONbits.TXREQ0=1; //Starts transmission
}

/******************************************************************************
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
        
        if((message->id == 0x02) && (message->data[0] == Device_ID) && (message->data[1] == 0x50))     //This is data for receiving a successful Connection request to HIU
        {
            MAGE = CONNECTED;
            level = message->data[3];
        }
        else if((message->id == 0x03) && (message->data[1] == Device_ID) && (message->data[0] == 0xFF) && (message->data[2] == 0xFE)) //This is a Ping from HIU
        {
            ecan1WriteMessage(2, 0, 0, MCAN_Weapon_Outbound_ID);
        }
        else if((message->id == 0x02) && (message->data[2] == 0xFF) && (message->data[3] == 0xFF))  //This data reception signals a failed connection request
        {
            ecan1WriteMessage(2, Device_ID | (Connection_Request << 2), 0, MCAN_Weapon_Outbound_ID); //ask for connection again
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
