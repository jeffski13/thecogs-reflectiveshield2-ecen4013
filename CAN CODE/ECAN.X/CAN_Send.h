/* 
 * File:   CAN_Send.h
 * Author: Michael
 *
 * Created on September 21, 2013, 6:01 PM
 */

#ifndef CAN_SEND_H
#define	CAN_SEND_H

#ifdef	__cplusplus
extern "C" {
#endif

void ecan1WriteTxMsgBufId(unsigned int buf, long txIdentifier, unsigned int ide, unsigned int remoteTransmit)
{

        unsigned long word0=0, word1=0, word2=0;
        unsigned long sid10_0=0, eid5_0=0, eid17_6=0;


        if(ide)
        {
                        eid5_0  = (txIdentifier & 0x3F);
                        eid17_6 = (txIdentifier>>6) & 0xFFF;
                        sid10_0 = (txIdentifier>>18) & 0x7FF;
                        word1 = eid17_6;
        } else {
                sid10_0 = (txIdentifier & 0x7FF);
        }


        if(remoteTransmit==1)  	// Transmit Remote Frame
        {
                word0 = ((sid10_0 << 2) | ide | 0x2);
                word2 = ((eid5_0 << 10)| 0x0200);
        } else {

                word0 = ((sid10_0 << 2) | ide);
                word2 = (eid5_0 << 10);
        }

        // Obtain the Address of Transmit Buffer in DMA RAM for a given Transmit Buffer number
        if(ide)
                Ecan1Tx[buf][0] = (word0 | 0x0002);
        else
                Ecan1Tx[buf][0] = word0;

                Ecan1Tx[buf][1] = word1;
                Ecan1Tx[buf][2] = word2;
}



#ifdef	__cplusplus
}
#endif

#endif	/* CAN_SEND_H */

