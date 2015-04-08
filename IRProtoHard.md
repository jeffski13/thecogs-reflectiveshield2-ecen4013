<h1>Infrared Communication Prototyping</h1>

<img src='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/IR/Proto_Hardware_IR_headerimg_receive.jpg' width='300px' /> <img src='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/IR/Proto_Hardware_IR_headerimg_send.jpg' width='300px' />


<h2>Table of Contents</h2>




---


## Circuit Schematic ##

IR Transmit

<img src='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/IR/Proto_Hardware_IR_sch_tx.jpg' width='400' />


IR Receive

<img src='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/IR/Proto_Hardware_IR_sch_rx.png' width='400' />


## PCB Layout ##


## Hardware Inputs ##

<table border='2px'>
<blockquote><tr>
<blockquote><th>Input Name</th>
<th>Description of Signal</th>
<th>Expected Range</th>
</blockquote></tr>
<tr>
<blockquote><td>IR_TX</td>
<td>56Khz square wave</td>
<td>0-3.3V</td>
</blockquote></tr>
</table></blockquote>


##### IR 56Khz Input Signal #####

<img src='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/IR/Proto_Hardware_IR_input_56khz.jpg' height='200' />

Measured Data:

DC Analysis:
<ul>With a 56kHz signal and 40 mA from 5VDC power supply<br>
<blockquote><li>85mA from 5VDC power supply</li>
<li>1mA from IR_TX</li>
</ul></blockquote>

##### BJT Measurement #####

<img src='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/IR/Proto_Hardware_IR_input_bjt.jpg' height='200' />

Transient voltage measured from the collector of BJT
Note: The voltage drop across the led rises as more current goes through the device.

## Hardware Outputs ##

<table border='2px'>
<blockquote><tr>
<blockquote><th>Output Name</th>
<th>Description of Signal</th>
<th>Expected Range</th>
</blockquote></tr>
<tr>
<blockquote><td>Pic (IR_RX)</td>
<td>PWM signal</td>
<td>3.3V -0V</td>
</blockquote></tr>
<tr>
<blockquote><td>Pic2</td>
<td>PWM signal</td>
<td>3.3V -0V</td>
</blockquote></tr>
<tr>
<blockquote><td>Pic3</td>
<td>PWM signal</td>
<td>3.3V -0V</td>
</blockquote></tr>
</table></blockquote>

##### Receive Output #####

<img src='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/IR/Proto_Hardware_IR_output_damage.jpg' width='300' />

This was captured from the receiver after a damage packet was sent from the transmitter. The receiver is working as expected.

##### Continuous Output #####

The following screenshot is of the IR transmit code transmitting continuous damage packets.

<img src='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/IR/Proto_Hardware_IR_output_continuous.jpg' width='300' />

You can clearly see the start packet, two data packets, and the stop packet.