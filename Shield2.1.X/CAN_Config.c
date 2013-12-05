/**********************************************************************
* Configuration Functions for DMA and ECAN modules
*************************************************************************************************/


#if defined(__dsPIC33F__)
#include "p33fxxxx.h"
#elif defined(__PIC24H__)
#include "p24hxxxx.h"
#endif

#include "CAN_Config.h"


/* Dma Initialization for ECAN1 Transmission */
void dma0init(void){

	 DMACS0=0;
         DMA0CON=0x2020;
	 DMA0PAD=0x0442;	/* ECAN 1 (C1TXD) */
 	 DMA0CNT=0x0007;
	 DMA0REQ=0x0046;	/* ECAN 1 Transmit */
	 DMA0STA=  __builtin_dmaoffset(ecan1msgBuf);
	 DMA0CONbits.CHEN=1;

}


/* Dma Initialization for ECAN1 Reception */
void dma2init(void){

	 DMACS0=0;
         DMA2CON=0x0020;
	 DMA2PAD=0x0440;	/* ECAN 1 (C1RXD) */
 	 DMA2CNT=0x0007;
	 DMA2REQ=0x0022;	/* ECAN 1 Receive */
	 DMA2STA= __builtin_dmaoffset(ecan1msgBuf);
	 DMA2CONbits.CHEN=1;

}



void ecan1ClkInit(void){

/* FCAN is selected to be FCY
// FCAN = FCY = 40MHz */
	C1CTRL1bits.CANCKS = 0x1;

/*
Bit Time = (Sync Segment + Propagation Delay + Phase Segment 1 + Phase Segment 2)=20*TQ
Phase Segment 1 = 1TQ
Phase Segment 2 = 2Tq
Propagation Delay = 4Tq
Sync Segment = 1TQ
 N = 8
CiCFG1<BRP> =(FCAN /(2 ×N×FBAUD))- 1
*/

	/* Synchronization Jump Width set to 1 TQ */
	C1CFG1bits.SJW = 0x0;
	/* Baud Rate Prescaler */
	C1CFG1bits.BRP = BRP_VAL;
	/* Phase Segment 1 time is 1 TQ */
	C1CFG2bits.SEG1PH=0x0;
	/* Phase Segment 2 time is set to be programmable */
	C1CFG2bits.SEG2PHTS = 0x1;
	/* Phase Segment 2 time is 2 TQ */
	C1CFG2bits.SEG2PH = 0x1;
	/* Propagation Segment time is 4 TQ */
	C1CFG2bits.PRSEG = 0x3;
	/* Bus line is sampled three times at the sample point */
	C1CFG2bits.SAM = 0x1;



}



void ecan1Init(void){

/* Request Configuration Mode */
	C1CTRL1bits.REQOP=4;
	while(C1CTRL1bits.OPMODE!=4);

	ecan1ClkInit();

	C1FCTRLbits.DMABS=0b000;		/* 4 CAN Message Buffers in DMA RAM */

/*	Filter Configuration

	ecan1WriteRxAcptFilter(int n, long identifier, unsigned int exide,unsigned int bufPnt,unsigned int maskSel)

	n = 0 to 15 -> Filter number

	identifier -> SID <10:0> : EID <17:0>

	exide = 0 -> Match messages with standard identifier addresses
	exide = 1 -> Match messages with extended identifier addresses

	bufPnt = 0 to 14  -> RX Buffer 0 to 14
	bufPnt = 15 -> RX FIFO Buffer

	maskSel = 0	->	Acceptance Mask 0 register contains mask
	maskSel = 1	->	Acceptance Mask 1 register contains mask
	maskSel = 2	->	Acceptance Mask 2 register contains mask
	maskSel = 3	->	No Mask Selection

*/

	ecan1WriteRxAcptFilter(1,0x000,0,1,0);  //Setup to read only SIDs


/*	Mask Configuration

	ecan1WriteRxAcptMask(int m, long identifierMask, unsigned int mide, unsigned int exide)

	m = 0 to 2 -> Mask Number

	identifier -> SID <10:0> : EID <17:0>

	mide = 0 -> Match either standard or extended address message if filters match
	mide = 1 -> Match only message types that correpond to 'exide' bit in filter

	exide = 0 -> Match messages with standard identifier addresses
	exide = 1 -> Match messages with extended identifier addresses

*/

	ecan1WriteRxAcptMask(0,0x000,0,0);  // Mask/Accept all SIDs


/* Enter LOOPBACK Mode */
	C1CTRL1bits.REQOP= 0;
	while(C1CTRL1bits.OPMODE!=0);

/* ECAN transmit/receive message control */

	C1RXFUL1=C1RXFUL2=C1RXOVF1=C1RXOVF2=0x0000;
	C1TR01CONbits.TXEN0=1;			/* ECAN1, Buffer 0 is a Transmit Buffer */
	C1TR01CONbits.TXEN1=0;			/* ECAN1, Buffer 1 is a Receive Buffer */
	C1TR01CONbits.TX0PRI=0b11; 		/* Message Buffer 0 Priority Level */
	C1TR01CONbits.TX1PRI=0b11; 		/* Message Buffer 1 Priority Level */

}


