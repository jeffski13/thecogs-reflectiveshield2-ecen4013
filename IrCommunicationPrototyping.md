<h1>Infrared Communication Prototyping</h1>

<img src='http://i.imgur.com/yMQo9Vv.jpg' width='300px' /> <img src='http://i.imgur.com/kyy6Jdg.jpg' width='300px' />


<h2>Table of Contents</h2>




---


## Circuit Schematic ##

IR Transmit

<img src='http://i.imgur.com/rfaDudN.jpg' width='400' />


IR Receive

<img src='http://i.imgur.com/6WSKeC5.png' width='400' />


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

<img src='http://i.imgur.com/bgET7Vg.jpg' height='200' />

Measured Data:

DC Analysis:
<ul>With a 56kHz signal and 40 mA from 5VDC power supply<br>
<blockquote><li>85mA from 5VDC power supply</li>
<li>1mA from IR_TX</li>
</ul></blockquote>

##### BJT Measurement #####

<img src='http://i.imgur.com/SVQDarj.jpg' height='200' />

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

<img src='http://i.imgur.com/vHItErG.jpg' height='200' />

This was captured from the receiver after a damage packet was sent from the transmitter. The receiver is working as expected.


## Transmit Code ##

The flow chart for the transmit code can be located on the <a href='https://code.google.com/p/thecogs-reflectiveshield2-ecen4013/wiki/IRCommunication'>IR research</a> page.

<table border='2px'>
<blockquote><tr>
<blockquote><th>Function Name</th>
<th>Description of expected outputs to function</th>
<th>Input Parameters</th>
<th>Return Value</th>
</blockquote></tr>
<tr>
<blockquote><td>singleCycleON</td>
<td>One cycle of on then off</td>
<td>void</td>
<td>void</td>
</blockquote></tr>
<tr>
<blockquote><td>burstOFF</td>
<td>Loop singleCycleOFF</td>
<td>Int length</td>
<td>void</td>
</blockquote></tr>
<tr>
<blockquote><td>burstON</td>
<td>Loop singleCycleOFF</td>
<td>Int length</td>
<td>void</td>
</blockquote></tr>
<tr>
<blockquote><td>iRTX</td>
<td>Send damage or healing packet</td>
<td>Char selection</td>
<td>void</td>
</blockquote></tr>
</table></blockquote>

##### IR Transmit Code, Continuous Output #####

The following screenshot is of the IR transmit code transmitting continuous damage packets.

<img src='http://i.imgur.com/oSCScnn.jpg' width='400' />

You can clearly see the start packet, two data packets, and the stop packet.