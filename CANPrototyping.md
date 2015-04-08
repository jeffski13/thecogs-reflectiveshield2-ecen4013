<h1>uController Prototyping</h1>

<img src='http://i.imgur.com/GyTcbTs.jpg' height='300px' />


<h2>Table of Contents</h2>




---


## Circuit Schematic ##

![http://i.imgur.com/V2buMAW.png](http://i.imgur.com/V2buMAW.png)

## PCB Layout ##

![http://i.imgur.com/DCEmzI4.png](http://i.imgur.com/DCEmzI4.png)

## Components ##

<ul>
<blockquote><li>MCP2551 CAN Transceiver</li>
<li>PIC24HJ128GP502 (Microcontroller, 40 MIPS)</li>
<li>.1 uF Capacitor</li>
<li>20 pF Capacitor</li>
<li>Mini AB USB Receptacle</li>
</ul></blockquote>

## Outputs ##

<table border='2px'>
<blockquote><tr>
<blockquote><th>Output Name</th>
<th>Description of Signal</th>
<th>Expected Range</th>
</blockquote></tr>
<tr>
<blockquote><td>out1</td>
<td>differential bus signal from the uController</td>
<td></td>
</blockquote></tr>
<tr>
<blockquote><td>CANRx</td>
<td>CANRx Signal from CAN module</td>
<td></td>
</blockquote></tr>
<tr>
<blockquote><td>CANTx</td>
<td>CANTx Signal from CAN module</td>
<td></td>
</blockquote></tr>
</table></blockquote>

##### Differential Signal #####

<img src='http://i.imgur.com/OTWZGHY.jpg' height='200' />

##### CANRx #####

<img src='http://i.imgur.com/0kPfVO2.png' height='200' />

The image shows the input to the CAN RX pin and the CAN TX output. Since the CAN transceiver CAN bus can potentially receive a signal while it’s transmitting (read about signal arbitration in the research section), we see the same signal on the RX pin as the TX.

##### CANTx #####

<img src='http://i.imgur.com/0kPfVO2.png' height='200' />

## Function List ##

The flowchart for the main code is in the <a href='https://code.google.com/p/thecogs-reflectiveshield2-ecen4013/wiki/CANBus#Flow_Charts'>CAN Bus research</a>. The modified function headers is as follows:

_void ecan1WriteMessage(unsigned int data, unsigned long id);;_
-	function description

_void__attribute__((interrupt,no\_auto\_psv)) `_C1Interrupt();_`
-	function description_

_void canBusTX(void);_
-	function description

_void rxecan1();_
-	This function is called in `_C1Interrupt()` above.

## Source Code ##

> CAN\_Config- .h and .c

> CAN\_Driver - .h and .c

> Common.h

> Traps.c

> can.c