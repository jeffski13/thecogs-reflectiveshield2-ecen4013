<h1>uController Prototyping</h1>

<img src='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/CAN/Proto_Hardware_CAN_headerimg.jpg' height='300px' />


<h2>Table of Contents</h2>




---


## Circuit Schematic ##

![https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/CAN/Proto_Hardware_CAN_sch.png](https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/CAN/Proto_Hardware_CAN_sch.png)

## PCB Layout ##

![https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/CAN/Proto_Hardware_CAN_pcb.png](https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/CAN/Proto_Hardware_CAN_pcb.png)

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

<img src='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/CAN/Proto_Hardware_CAN_output_differential.jpg' width='500' />

##### CANRx #####

<img src='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/CAN/Proto_Hardware_CAN_output_canrx.png' width='500' />

The image shows the input to the CAN RX pin and the CAN TX output. Since the CAN transceiver CAN bus can potentially receive a signal while it’s transmitting (read about signal arbitration in the research section), we see the same signal on the RX pin as the TX.

##### CANTx #####

<img src='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/CAN/Proto_Hardware_CAN_output_cantx.png' width='500' />