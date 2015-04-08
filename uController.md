<h1>µController</h1>

<img src='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Research/uController/Research_uC_headerimg.jpg' height='300px'>ACK: Digikey<br>
<br>
<br>
<h2>Table of Contents</h2>

<br>
<br>
<hr />


<h2><u>Quick Links</u></h2>

<a href='http://ww1.microchip.com/downloads/en/DeviceDoc/70293E.pdf'>PIC24HJ128GP504 Datasheet</a>

<h2><u>Design Challenges</u></h2>

Most of the <a href='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/ReflectiveShield2.0_MarketingReqs.pdf'> marketing requirements</a> had at least an indirect impact on the design of the µController.<br>
<br>
The µController is the most essential part to the Reflective Shield 2.0. It could be considered the brain of the system; it controls how each of the other components operate and calls upon them to do so when necessary. Therefore, it is essential to choose a µController that is capable of being able to facilitate the needs of all the other system components, especially <a href='https://code.google.com/p/thecogs-reflectiveshield2-ecen4013/wiki/Audio'>audio</a>,<a href='https://code.google.com/p/thecogs-reflectiveshield2-ecen4013/wiki/CANBus'>CANbus</a>, <a href='https://code.google.com/p/thecogs-reflectiveshield2-ecen4013/wiki/FrontLighting'>front lighting</a>, <a href='https://code.google.com/p/thecogs-reflectiveshield2-ecen4013/wiki/IRCommunication'>IR communication</a>, and the <a href='https://code.google.com/p/thecogs-reflectiveshield2-ecen4013/wiki/HumanInterface'>human interface</a>.<br>
<br>
<h2><u>The PIC24HJ128GP504</u></h2>

The µController that was chosen for the shield has been the PIC24HJ128GP504.<br>
<br>
This µController had some key characteristics that made it a great choice for the project:<br>
<ul>
<blockquote><li>Includes all of the functionality that is required for this project </li>
<li>Has a very low power consumption </li>
<li>Made by the same company as the programming software, MPLAB, Is either cheaper or the same price as the competitors </li>
<li>Samples are easily obtainable. </li>
</ul></blockquote>

<h3>Overall Pin Layout Structure</h3>

<img src='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Research/uController/Research_uC_pinLayoutStructure.png' /> ACK: MicroChip<br>
<br>
We will need to utilize four pins for SPI (<a href='https://code.google.com/p/thecogs-reflectiveshield2-ecen4013/wiki/FrontLighting'>front lighting</a>), six for the Health Meter LEDs (<a href='https://code.google.com/p/thecogs-reflectiveshield2-ecen4013/wiki/HumanInterface'>human interface</a>), two for the buttons (also <a href='https://code.google.com/p/thecogs-reflectiveshield2-ecen4013/wiki/HumanInterface'>human interface</a>), 8 for <a href='https://code.google.com/p/thecogs-reflectiveshield2-ecen4013/wiki/Audio'>audio</a>, two to four for <a href='https://code.google.com/p/thecogs-reflectiveshield2-ecen4013/wiki/IRCommunication'>IR communication</a>, and two for <a href='https://code.google.com/p/thecogs-reflectiveshield2-ecen4013/wiki/CANBus'>CANbus</a>. Therefore, it is safe to say that we will need no more than 35 I/O pins (estimated at 26 pins currently).<br>
<br>
<table border='2'>
<blockquote><tr>
<blockquote><th>Design Category</th>
<td>SPI (Front Lighting)</td>
<td>IR</td>
<td>Buttons (Human Interface)</td>
<td>Audio</td>
<td>CANbus</td>
<td>Health Meter (Human Interface)</td>
</blockquote></tr>
<tr>
<blockquote><th>Pin Count</th>
<td>4</td>
<td>4</td>
<td>2</td>
<td>8</td>
<td>2</td>
<td>6</td>
</blockquote></tr>
</table></blockquote>

As seen in the table above, 8 I/O pins will be needed for Audio, 2-4 for IR (one must be able to trigger interrupts), 2 for the pushbuttons, 6 for the HP LEDs, 2 for the CANbus transmission and 4 for the SPI communication with the LED driver, bringing the total to over 26 I/O pins (most 28 pin pics have 21, therefore we will need a µController, PIC24HJ128GP504).<br>
<br>
<h3>Challenges with Front Lighting</h3>
The main reason that we chose a 16 µController PIC over an 8 bit µController has to do with the speed desired when attempting to light up 64 - 72 LEDs.<br>
<br>
The initial plan is to use an LED driver with which the µController must communicate with, over SPI.<br>
<br>
SPI or Serial Peripheral Interface is a “master-slave” communication protocol that allows the master to be able to send and receive data serially from the various slave devices. This is a synchronous protocol, meaning that data can be sent and receive at the same time.  The master device provides a clock signal to the slave devices and those devices will transfer data based on the provided clock. Something to note is that this is an EXCHANGE of data, meaning that the master device also receives Data. The way that the master device chooses which slave to communicate with is through the use of the “slave select”. The code provided by the user will choose when to set the slave select to let the slave know it should receive the data. Data is output during the rising or falling edge of the clock. This data is then latched on the opposite clock edge. Four different signals are used for SPI communication. There must be a data out, data in, clock, and slave select pin on both the master and the slave device. The flow of data is as follows. The data gets loaded into the SPI buffer and then is internally written to the SPI transmit buffer. This data is then shifted out of the µController by the use of an internal shift register. Received data will be stored in the internal SPI receive buffer. This is also done by the use of the internal shift register. The data in the buffer must be read upon reception, else an overflow flag will be thrown. The reading of this received data is performed simply by reading the contents of the SPI buffer. Data is both transmitted and received through this buffer.<br>
<br>
The maximum speed of the 8 bit µControllers are around 10 MIPS. Having to send out at least eight different messages over SPI could possibly cause problems, possibly with the timing that it would take initiate eight different transmits over SPI. There could possibly be some delay issues in the lighting if this is the case.<br>
<br>
A 16 bit µController effectively cuts down the time needed to go through with executing each SPI transmit. This is due to the speed of the instruction clock. The PIC24HJ128GP504 provides is a CPU speed that is over twice the speed of the fastest 8 bit µController speed.<br>
Other reasons for choosing this µController are the program memory size (128 KB) which should be enough for our purposes, the fact that a CAN module is on board, and also the fact that there are two SPI peripherals. While we only need one (will use slave select), it is good to have a back-up. Lastly, the I/O pin count must be taken into consideration. The fact that we will be using an LED driver considerably cuts down on the power requirements of the µController , and lowers the pin count required by the lighting.<br>
<br>
<br>
<br>
<br>
<h2><u>Main Code</u></h2>

<img src='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Research/uController/Research_uC_mainCodeFlowChart.png' />

It is important to note also what exactly the “Initialize uController” will actually be executing. It will be setting the configuration bits, enabling specific interrupts, enabling CANBus operation, setting up SPI, and defining the variables to be used.<br>
<br>
<h3>Function Headers</h3>

<i><code>_iRInterrupt();</code></i>
-	This function is for defining what happens when an IR transmission is detected. Therefore it is not called directly by the main program but is entered upon a level trigger detected by the µController. It will also check to determine if the MIRP packet is a valid attack packet and set the global variable of iRValid to a one if so. This interrupt will have the highest priority of any interrupt.<br>
<br>
<i>void timerCD();</i>
-	No parameters need to be passed here, nor do any returns need to be made. The timer for our countdown will be setup and started.<br>
<br>
<i>void disableButtons();</i>
-	The level trigger interrupts will be disabled here so that after a person has failed to select heal or attack they will not successfully be able to do so after the timer has exceeded five seconds..<br>
<br>
<i>int dmgCount incDmgCount(int dmgCount);</i>
-	Here is where we will update the global variable that keeps track of how much damage the shield has taken.<br>
<br>
<i>void canBusTX();</i>
-	CANbus communication will occur once this function is called. It will be either set up beforehand, or within this function depending on the preference of the person in charge of coding CANBus communication.<br>
<br>
<i>int healorAttack(int iRChoice);</i>
-	Will determine which packet to send on based on the user input (button press). This is checked by determining which interrupt flag is currently set by hardware. It will return a ‘1’ for heal and a ‘0’ for attack.<br>
<br>
<i>void lightTransmit(int lightChoice);</i>
-	The function lightTransmit is designed to take in an integer value between 0 and 8 (0b000 to 0b111). A switch statement will follow this function header and will initiate the SPI communication based on int lightChoice.<br>
<br>
<i>void iRTransmit(int iRChoice);</i>
-	Will send out the IR packet based on the choice returned from healorAttack(). Nothing will be returned from this function.<br>
<br>
<br>
<br>
<h2><u>Design Schematic</u></h2>

<img src='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Research/uController/Research_uC_DesignSch.png' />

<h2><u>Sources</u></h2>

<code>MicroChip(2011) “PIC24HJ32GP302/304, PIC24HJ64GPX02/X04 and PIC24HJ128GPX02/X04 Data Sheet” [Online]</code> Available: <a href='http://ww1.microchip.com/downloads/en/DeviceDoc/70293E.pdf'>http://ww1.microchip.com/downloads/en/DeviceDoc/70293E.pdf</a>

<code>Digikey(2013) “Digi-Key Part Number | MA180028-ND” [Online]</code> Available: <a href='http://www.digikey.com/product-detail/en/MA180028/MA180028-ND/2352010'>http://www.digikey.com/product-detail/en/MA180028/MA180028-ND/2352010</a>