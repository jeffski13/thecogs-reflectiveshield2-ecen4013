<h1>CAN Bus Software Prototyping</h1>

<img src='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Software/CAN/Proto_Software_CAN_headerimg.png' height='300px' />


<h2>Table of Contents</h2>




---


void ecan1WriteRxAcptFilter(int n, long identifier, unsigned int exide, unsigned int bufPnt,unsigned int maskSel)
## Software Inputs ##

<table border='2px'>
<blockquote><tr>
<blockquote><th>Input Name</th>
<th>Description</th>
<th>Expected Range</th>
</blockquote></tr>
<tr>
<blockquote><td>int n</td>
<td>ecan1WriteRxAcptFilter: filter number</td>
<td>0 to 15</td>
</blockquote></tr>
<tr>
<blockquote><td>long identifier</td>
<td>ecan1WriteRxAcptFilter: id for CAN, specifies which types of messages can go through the filter (the filter is defined by the "n" parameter)</td>
<td>any 11-bit(standard) or 29-bit number(extended)</td>
</blockquote></tr>
<tr>
<blockquote><td>unsigned int exide</td>
<td>ecan1WriteRxAcptFilter method and ecan1WriteRxAcptMask method: determines whether or not the filter uses an extended identifier</td>
<td>0 (false) or 1(true)</td>
</blockquote></tr>
<tr>
<blockquote><td>unsigned int bufPnt</td>
<td>ecan1WriteRxAcptFilter: points the data that goes through to the correct buffer</td>
<td>0 to 7</td>
</blockquote></tr>
<tr>
<blockquote><td>unsigned int maskSel</td>
<td>ecan1WriteRxAcptFilter: Optinal Masking of identifier bits</td>
<td>0 to 3</td>
</blockquote></tr>
<tr>
<blockquote><td>int m</td>
<td>ecan1WriteRxAcptMask: number of the mask</td>
<td>0 to 3</td>
</blockquote></tr>
<tr>
<blockquote><td>long identifier</td>
<td>ecan1WriteRxAcptMask: id for CAN, specifies which types of messages can go through the mask(the mask is defined by the "m" parameter)</td>
<td>any 11-bit(standard) or 29-bit number(extended)</td>
</blockquote></tr>
<tr>
<blockquote><td>unsigned int mide</td>
<td>ecan1WriteRxAcptMask: specifies whether to match any identifier OR to match with the exide bit</td>
<td>0 or 1</td>
</blockquote></tr>
<tr>
<blockquote><td>unsigned int buf</td>
<td>ecan1WriteTxMsgBufId: defines which buffer to use</td>
<td>0 to 3</td>
</blockquote></tr>
<tr>
<blockquote><td>long txIdentifier</td>
<td>ecan1WriteTxMsgBufId: the ID that will be broadcasted</td>
<td>any 11-bit(standard) or 29-bit number(extended)</td>
</blockquote></tr>
<tr>
<blockquote><td>unsigned int ide</td>
<td>ecan1WriteTxMsgBufId: determines whether or not the filter uses an extended identifier</td>
<td>0 or 1</td>
</blockquote></tr>
<tr>
<blockquote><td>unsigned int remoteTransmit</td>
<td>ecan1WriteTxMsgBufId: determines whether or not message is a remote transmit frame</td>
<td>0 (standard frame) or 1(Remote Transmit Request)</td>
</blockquote></tr>
<tr>
<blockquote><td>unsigned int buf</td>
<td>ecan1WriteTxMsgBufData: defines which buffer message is transmitted from</td>
<td>0 to 3</td>
</blockquote></tr>
<tr>
<blockquote><td>unsigned int dataLength</td>
<td>ecan1WriteTxMsgBufData: number of bytes to be transmitted</td>
<td>0 to 8</td>
</blockquote></tr>
<tr>
<blockquote><td>unsigned int data1</td>
<td>ecan1WriteTxMsgBufData: data being sent in message</td>
<td>2 byte number</td>
</blockquote></tr>
<tr>
<blockquote><td>unsigned int data2</td>
<td>ecan1WriteTxMsgBufData: data being sent in message</td>
<td>2 byte number</td>
</blockquote></tr>
<tr>
<blockquote><td>unsigned int data3</td>
<td>ecan1WriteTxMsgBufData: data being sent in message</td>
<td>2 byte number</td>
</blockquote></tr>
<tr>
<blockquote><td>unsigned int data4</td>
<td>ecan1WriteTxMsgBufData: data being sent in message</td>
<td>2 byte number</td>
</blockquote></tr>
<tr>
<blockquote><td>long ID</td>
<td>ecan1WriteMessage: identifier</td>
<td>any 11-bit(standard) or 29-bit number(extended)</td>
</blockquote></tr>
<tr>
<blockquote><td>unsigned int data</td>
<td>ecan1WriteMessage: data being sent in message</td>
<td>2 byte number</td>
</blockquote></tr>
</table></blockquote>

## Software Outputs ##


<table border='2px'>
<blockquote><tr>
<blockquote><th>Input Name</th>
<th>Description</th>
<th>Expected Range</th>
</blockquote></tr>
<tr>
<blockquote><td></td>
<td></td>
<td></td>
</blockquote></tr>
<tr>
<blockquote><td></td>
<td></td>
<td></td>
</blockquote></tr>
<tr>
<blockquote><td></td>
<td></td>
<td></td>
</blockquote></tr>
</table></blockquote>

## Public Function List ##




The flowchart for the main code is in the <a href='https://code.google.com/p/thecogs-reflectiveshield2-ecen4013/wiki/CANBus#Flow_Charts'>CAN Bus research</a>. The modified function headers is as follows:

_void ecan1WriteMessage(long ID, int data);_
-	writes a 1byte message with a specified ID

_void dma0init(void);_
-	DMA (Direct Memory Access) Initialization for ECAN Transmission

_void dma2init(void);_
-	DMA Initialization for ECAN Reception

_void ecan1ClkInit(void);_
-	Configures the baud rate and the CAN module frequency

_void ecan1Init(void);_
-	calls the ecan1WriteRxAcptFilter method, ecan1WriteRxAcptMask method, and the ecan1ClkInit method


_void ecan1WriteRxAcptFilter(int n, long identifier, unsigned int exide, unsigned int bufPnt,unsigned int maskSel);_
-	This function configures Acceptance Filter "n"


_void ecan1WriteRxAcptMask(int m, long identifier, unsigned int mide, unsigned int exide);_
-	This function configures Acceptance Filter Mask "m"

_void ecan1WriteTxMsgBufId(unsigned int buf, long txIdentifier, unsigned int ide, unsigned int remoteTransmit);_
-	ECAN (Enhanced CAN) Transmit Message Buffer Configuration

_void ecan1WriteTxMsgBufData(unsigned int buf, unsigned int dataLength, unsigned int data1, unsigned int data2, unsigned int data3, unsigned int data4);_
-	ECAN Transmit Data




## Source Code ##

> CAN\_Config- .h and .c

> CAN\_Driver - .h and .c

> Common.h

> Traps.c

> can.c