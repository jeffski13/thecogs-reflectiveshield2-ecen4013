#ifndef __CAN_Driver_H__
#define __CAN_Driver_H__

#define Device_ID                   0x20
#define MCAN_Weapon_Outbound_ID     0x02
#define MCAN_Dead_Packet_ID         0x03
#define Connection_Request          0x01
#define Dead_Packet                 0xFE
#define HIU_Connection_Response_ID  0x02
#define HIU_Ping_ID                 0x03
#define HIU_Headband_ID             0x00
#define IR_Hit_Received             0x02


extern void ecan1WriteRxAcptFilter(int n, long identifier, unsigned int exide,unsigned int bufPnt,unsigned int maskSel);
extern void ecan1WriteRxAcptMask(int m, long identifierMask, unsigned int mide,unsigned int exide);

extern void ecan1WriteTxMsgBufId(unsigned int buf, long txIdentifier, unsigned int ide, unsigned int remoteTransmit);
extern void ecan1WriteTxMsgBufData(unsigned int buf, unsigned int dataLength, unsigned int data1, unsigned int data2, unsigned int data3, unsigned int data4);

extern void ecan1DisableRXFilter(int n);

#endif
