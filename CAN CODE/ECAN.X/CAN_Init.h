/* 
 * File:   CAN_Init.h
 * Author: Michael
 *
 * Created on September 21, 2013, 6:01 PM
 */

#ifndef CAN_INIT_H
#define	CAN_INIT_H

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef	__cplusplus
}
#endif

#endif	/* CAN_INIT_H */

#define FCAN (40000000)
#define BITRATE (125000)
#define NTQ (20)                                   // Time Quanta in a bit time
#define BRP_VAL ((FCAN/ (2*NTQ*BITRATE))-1)
#define SID1 (0xAA)
#define xMessage (0x7FF)
#define BUFF0PRIORITY (0b11)


unsigned int Ecan1Rx[12][8] __attribute__((space(dma)));     // 12 buffers, 8 words each
unsigned int Ecan1Tx[2][8] __attribute((space(dma)));      // 2 buffers, 8 words

void set_bitTiming(void);
void set_filters(void);
void set_txRx(void);
void dmaConfig(void);
void ecan1WriteRxAcptFilter(int, long, unsigned int, unsigned int,unsigned int);
void ecan1WriteRxAcptMask(int, long, unsigned int, unsigned int);
void init_buffers(void);
void set_priority(void);

    void CAN_INIT()
    {
        C1CTRL1bits.REQOP = 0b100;              //Request Configuration mode
        while(!C1CTRL1bits.OPMODE2);            //Wait until module is in config mode
        set_bitTiming();                            // TQ initialization
        set_filters();                              //filter initialization
        C1CTRL1bits.REQOP = 0;                  //request normal mode
        while(C1CTRL1bits.OPMODE != 0);         //Wait for normal mode
        set_txRx();
        dmaConfig();

        C1CTRL1bits.REQOP = 0;
        while(C1CTRL1bits.OPMODE!=0);
        init_buffers();
        set_priority();
    }




    void set_bitTiming(void)
    {
        C1CTRL1bits.CANCKS = 0x1;
        /*                       TIMING SETUP                                                           */
        /* Bit Time = (Sync Segment + Propagation Delay + Phase Segment 1 + Phase Segment 2) = 20 * TQ  */
        /* Phase Segment 1 = 2 TQ                                                                       */
        /* Phase Segment 2 = 2 TQ                                                                       */
        /* Propagation Delay = 4 TQ                                                                     */
        /* Sync Segment = 1 TQ                                                                          */
        /* CiCFG1<BRP> =(FCAN/(2 * N * FBAUD))- 1                                                       */
        /* BIT RATE OF 125 kbps                                                                         */
        /* 20 TQ Total                     40 / 20 = 2; data sheet says must be int                     */
        C1CFG1bits.BRP = BRP_VAL;
        C1CFG1bits.SJW = 0x01;                   //Set Synch Jump Width to 1
        C1CFG2bits.SEG1PH = 0x0C;               //Set Phase Seg. 1 time to 12TQ; 60%
        C1CFG2bits.SEG2PH = 0x06;                //Set Phase Seg. 2 time to 6TQ; 30%
        C1CFG2bits.PRSEG = 0x02;                 //Set Prop. Seg. Time to 2TQ
        C1CFG2bits.SAM = 0x01;                //Bus is sampled 3 times @ sample point
    }

    void set_filters(void)
    {
        C1FCTRLbits.FSA= 0b00010;                               //FIFO Starts at Message buffer 4
        C1FCTRLbits.DMABS = 0b010;                              //assign 8 DMA buffers to ECAN
        // ecan1WriteRxAcptFilter(int n, long identifier, unsigned int exide,unsigned int bufPnt,unsigned int maskSel)
        ecan1WriteRxAcptFilter(1, 0b11110100101, 0, 15, 0);
        // ecan1WriteRxAcptMask(int m, long identifierMask, unsigned int mide, unsigned int exide)
        ecan1WriteRxAcptMask(1, 0b11111100101, 1, 0);
  
        C1BUFPNT1bits.F0BP = 0b0001;                            // acceptance fileter to use buffer 1 for incoming messages
        C1FEN1bits.FLTEN0 = 1;                                  // enable filter 0
    }

    void set_txRx(void)
    {
         C1TR01CONbits.TXEN0 = 1;                               //Buffer 0 is tx
         C1TR01CONbits.TXEN1 = 0;                               //Buffer 1 is rx
         C1TR01CONbits.TX0PRI = BUFF0PRIORITY;                  //Buffer 0 priority
    }

    void dmaConfig(void)
    {
        /* RX CONFIG*/
        DMA0CONbits.AMODE = 2;                                  //Continuous mode, 1 buffer
        DMA0CONbits.MODE = 0;                                   //Peripheral Indirect Addressing
        DMA0PAD = (volatile unsigned int) &C1RXD;               //Point to ECAN1 Rx register
        DMA0STA = __builtin_dmaoffset(&Ecan1Rx);                 //Point DMA to ECAN1 buffers
        DMA0CNT = 7;                                            //8 DMA Request, 1 buffer 8 words
        DMA0REQ = 0x22;                                         //Select ECAN1 RX as DMA request source
        IEC0bits.DMA0IE = 1;                                    //Enable DMA Channel 0 interrupt
        DMA0CONbits.CHEN = 1;                                   //Enable DMA channel 0

        /* TX config*/
        DMA2CONbits.AMODE = 2;                                  //Continuous mode, 1 buffer
        DMA2CONbits.MODE = 0;                                   //Peripheral Indirect Addressing
        DMA2PAD = (volatile unsigned int) &C1TXD;               //Point to ECAN1 Rx register
        DMA2STA = __builtin_dmaoffset(&Ecan1Tx);                 //Point DMA to ECAN1 buffers
        DMA2CNT = 7;                                            //8 DMA Request, 1 buffer 8 words
        DMA2REQ = 0x22;                                         //Select ECAN1 RX as DMA request source
                                           //Enable DMA Channel 0 interrupt

        DMA0CONbits.CHEN = 1;                                   //Enable DMA channel 0
    }

    void ecan1WriteRxAcptFilter(int n, long identifier, unsigned int exide, unsigned int bufPnt,unsigned int maskSel) {

    unsigned long sid10_0=0, eid15_0=0, eid17_16=0;
    unsigned int *sidRegAddr,*bufPntRegAddr,*maskSelRegAddr, *fltEnRegAddr;


        C1CTRL1bits.WIN=1;

        // Obtain the Address of CiRXFnSID, CiBUFPNTn, CiFMSKSELn and CiFEN register for a given filter number "n"
        sidRegAddr = (unsigned int *)(&C1RXF0SID + (n << 1));
        bufPntRegAddr = (unsigned int *)(&C1BUFPNT1 + (n >> 2));
        maskSelRegAddr = (unsigned int *)(&C1FMSKSEL1 + (n >> 3));
        fltEnRegAddr = (unsigned int *)(&C1FEN1);


        // Bit-filed manupulation to write to Filter identifier register
        if(exide==1) { 	// Filter Extended Identifier
                eid15_0 = (identifier & 0xFFFF);
                eid17_16= (identifier>>16) & 0x3;
                sid10_0 = (identifier>>18) & 0x7FF;

                *sidRegAddr=(((sid10_0)<<5) + 0x8) + eid17_16;	// Write to CiRXFnSID Register
            *(sidRegAddr+1)= eid15_0;					// Write to CiRXFnEID Register

        }else{			// Filter Standard Identifier
                sid10_0 = (identifier & 0x7FF);
                *sidRegAddr=(sid10_0)<<5;					// Write to CiRXFnSID Register
                *(sidRegAddr+1)=0;							// Write to CiRXFnEID Register
        }


       *bufPntRegAddr = (*bufPntRegAddr) & (0xFFFF - (0xF << (4 *(n & 3)))); // clear nibble
       *bufPntRegAddr = ((bufPnt << (4 *(n & 3))) | (*bufPntRegAddr));       // Write to C1BUFPNTn Register

       *maskSelRegAddr = (*maskSelRegAddr) & (0xFFFF - (0x3 << ((n & 7) * 2))); // clear 2 bits
       *maskSelRegAddr = ((maskSel << (2 * (n & 7))) | (*maskSelRegAddr));      // Write to C1FMSKSELn Register

       *fltEnRegAddr = ((0x1 << n) | (*fltEnRegAddr)); // Write to C1FEN1 Register

       C1CTRL1bits.WIN=0;


}

    void ecan1WriteRxAcptMask(int m, long identifier, unsigned int mide, unsigned int exide)
    {

        unsigned long sid10_0=0, eid15_0=0, eid17_16=0;
        unsigned int *maskRegAddr;

        C1CTRL1bits.WIN=1;

        // Obtain the Address of CiRXMmSID register for given Mask number "m"
        maskRegAddr = (unsigned int *)(&C1RXM0SID + (m << 1));

        // Bit-filed manupulation to write to Filter Mask register
        if(exide==1)
        { 	// Filter Extended Identifier
                eid15_0 = (identifier & 0xFFFF);
                eid17_16= (identifier>>16) & 0x3;
                sid10_0 = (identifier>>18) & 0x7FF;

                if(mide==1)
                        *maskRegAddr=((sid10_0)<<5) + 0x0008 + eid17_16;	// Write to CiRXMnSID Register
                else
                        *maskRegAddr=((sid10_0)<<5) + eid17_16;                 // Write to CiRXMnSID Register
            *(maskRegAddr+1)= eid15_0;                                          // Write to CiRXMnEID Register

        }
        else
        {       // Filter Standard Identifier
                sid10_0 = (identifier & 0x7FF);
                if(mide==1)
                        *maskRegAddr=((sid10_0)<<5) + 0x0008;                   // Write to CiRXMnSID Register
                else
                        *maskRegAddr=(sid10_0)<<5;                              // Write to CiRXMnSID Register

                *(maskRegAddr+1)=0;                                             // Write to CiRXMnEID Register
        }
        C1CTRL1bits.WIN=0;

    }

    void init_buffers(void)
    {
        C1RXFUL1 = 0x0000;
        C1RXFUL2 = 0x0000;
        C1RXOVF1 = 0x0000;
        C1RXOVF2 = 0x0000;
        C1TR01CONbits.TXEN0=1;			/* ECAN1, Buffer 0 is a Transmit Buffer */
	C1TR01CONbits.TXEN1=1;			/* ECAN1, Buffer 0 is a Transmit Buffer */
	C1TR23CONbits.TXEN2=1;			/* ECAN1, Buffer 0 is a Transmit Buffer */
	C1TR23CONbits.TXEN3=1;			/* ECAN1, Buffer 0 is a Transmit Buffer */
	C1TR45CONbits.TXEN4=1;			/* ECAN1, Buffer 0 is a Transmit Buffer */
	C1TR45CONbits.TXEN5=1;			/* ECAN1, Buffer 0 is a Transmit Buffer */
    }

    void set_priority(void)
    {
	C1TR01CONbits.TX0PRI=0b11; 		/* Message Buffer 0 Priority Level */
	C1TR01CONbits.TX1PRI=0b11; 		/* Message Buffer 0 Priority Level */
	C1TR23CONbits.TX2PRI=0b11; 		/* Message Buffer 0 Priority Level */
	C1TR23CONbits.TX3PRI=0b11; 		/* Message Buffer 0 Priority Level */
	C1TR45CONbits.TX4PRI=0b11; 		/* Message Buffer 0 Priority Level */
	C1TR45CONbits.TX5PRI=0b11; 		/* Message Buffer 0 Priority Level */
    }
