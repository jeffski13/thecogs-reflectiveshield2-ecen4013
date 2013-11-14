

#ifndef __COMMON_H__
#define __COMMON_H__

#define CAN_MSG_DATA	0x01 // message type
#define CAN_MSG_RTR		0x02 // data or RTR
#define CAN_FRAME_EXT	0x03 // Frame type
#define CAN_FRAME_STD	0x04 // extended or standard

/* message structure in RAM */
typedef struct{
	/* keep track of the buffer status */
	unsigned char buffer_status;
	/* RTR message or data message */
	unsigned char message_type;
	/* frame type extended or standard */
	unsigned char frame_type;
	/* buffer being used to reference the message */
	unsigned char buffer;
	/* 29 bit id max of 0x1FFF FFFF
	*  11 bit id max of 0x7FF */
	unsigned long id;
	/* message data */
	unsigned char data[8];
	/* received message data length */
	unsigned char data_length;
}mID;


/* structure used to queue the FIFO messages in RAM */
typedef struct{
	/* keep track of the FIFO status */
	unsigned char FIFO_status;
	/* the structure of each message */
	mID FIFO[7];
}FIFO;


#endif
