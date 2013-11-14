#ifndef __CAN_Config_H__
#define __CAN_Config_H__


#include "CAN_Driver.h"

/* CAN Baud Rate Configuration 		*/
#define FCAN  	40000000
#define BITRATE 62500
#define NTQ 	8		// 8 Time Quanta in a Bit Time
#define BRP_VAL		39

/* CAN Message Buffer Configuration */
#define  ECAN1_MSG_BUF_LENGTH 	4
typedef unsigned int ECAN1MSGBUF [ECAN1_MSG_BUF_LENGTH][8];
extern ECAN1MSGBUF  ecan1msgBuf __attribute__((space(dma)));


/* Function Prototype 	*/
extern void ecan1Init(void);
extern void dma0init(void);
extern void dma2init(void);



#endif
