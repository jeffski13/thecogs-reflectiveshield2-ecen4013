<h1>Human Interface & Packaging</h1>

<img src='' height='300px' />


<h2>Table of Contents</h2>




---


## Health Meter Circuit Schematic ##


This circuit consists of simulating the LED for displaying the health by receiving a High for ON or a Low signal for OFF. The use of the BJT makes the current draw from the pic minimum (0.8mA). Each LED uses the current from the battery we estimated 22-25mA for each LED coming from a 5V source. Each BJT gate will receive 3.3V to turn them on and 0V to turn off.

The header 1 is to connect the power supply (5V) and form 2-7 is to connect to the MCU I/O ports, and the 8 is GND.


## Health Meter PCB Layout ##


## Health Meter Components ##

<ul>
<blockquote><li>2 Red LEDs</li>
<li>2 Yellow LEDs</li>
<li>2 Green LEDs</li>
<li>6 2N2222A BJTs</li>
<li>6 3.3kOHM Resistors</li>
<li>6 100 OHM Resistors</li>
</ul></blockquote>

## Interface Buttons Circuit Schematic ##


## Buttons Interface Components ##

<ul>
<blockquote><li>1 Buttons (NKK Switch)</li>
<li>1 Green LED</li>
<li>1 120OHM Resistor</li>
</ul></blockquote>

## Hardware Inputs ##

<table border='2px'>
<blockquote><tr>
<blockquote><th>Input Name</th>
<th>Description of Signal</th>
<th>Expected Range</th>
</blockquote></tr>
<tr>
<blockquote><td>Vdd</td>
<td>This is the central point providing power to the rest of the microcontroller. All points that require Vdd (shown in schematic) are powered from this bus.</td>
<td>3.2-3.4V</td>
</blockquote></tr>
<tr>
<blockquote><td>Vdd</td>
<td>The reference point for the microcontroller. All power externally (Vdd) as well as the microcontroller itself will use this bus as the ground reference.</td>
<td>0V</td>
</blockquote></tr>
<tr>
<blockquote><td>Debugging LED</td>
<td>Could have been sourced or sunk from the microcontroller. Due to the fact that the PIC pins can only supply 4mA though, the LED is being sunk into pins 35-37.  This way the PIC can equally distribute the current into the PIC.</td>
<td></td>
</blockquote></tr>
</table></blockquote>


##### VDD Input #####

<img src='http://i.imgur.com/hMYhU9y.jpg?1' height='200' />

DC 5V Input Signal

##### Vss Input #####

<img src='http://i.imgur.com/xMbZtRK.jpg?1' height='200' />

DC 5V Signal from Microphone

## Hardware Outputs ##
Output
Name




<table border='2px'>
<blockquote><tr>
<blockquote><th>Name</th>
<th>Description of Signal</th>
<th>Expected Range</th>
</blockquote></tr>
<tr>
<blockquote><td>RB4</td>
<td>MC1, LATBbits.LATB4, Play absorb attack sound when set low.</td>
<td>3.3-3.35V</td>
</blockquote></tr>
<tr>
<blockquote><td>RA8	</td>
<td>MC2, LATAbits.LATA8, Play countdown sound when set low.</td>
<td>3.3-3.35V</td>
</blockquote></tr>
<tr>
<blockquote><td>RA3	</td>
<td>MC3, LATAbits.LATA3, Play attack reflection sound when set low.</td>
<td>3.3-3.35V</td>
</blockquote></tr>
<tr>
<blockquote><td>RA2	</td>
<td>MC4, LATAbits.LATA2, Play healing sound when set low.</td>
<td>3.3-3.35V</td>
</blockquote></tr>
<tr>
<blockquote><td>RC2	</td>
<td>MC5, LATCbits.LATC2, Play damage taken sound when set low.</td>
<td>3.3-3.35V</td>
</blockquote></tr>
<tr>
<blockquote><td>RC1	</td>
<td>MC6, LATCbits.LATC1, Play shield breaking sound when set low.</td>
<td>3.3-3.35V</td>
</blockquote></tr>
<tr>
<blockquote><td>RC0	</td>
<td>MC7, LATCbits.LATC0, Play cheating sound when set low.</td>
<td>3.3-3.35V</td>
</blockquote></tr>
<tr>
<blockquote><td>RB3	</td>
<td>MC8, LATBbits.LATB3, Reserved for additional sound when set low.</td>
<td>3.3-3.35V</td>
</blockquote></tr>
</table></blockquote>

##### RB3 Output #####

<img src='http://i.imgur.com/pKfXjbp.jpg' height='200' />

##### RC0 Output #####

<img src='http://i.imgur.com/faAi3lI.jpg' height='200' />

##### RC1 Output #####

<img src='http://i.imgur.com/it5elyD.jpg' height='200' />


## Test Points ##

<table border='2px'>
<blockquote><tr>
<blockquote><th>T.P. Name</th>
<th>Description of Signal and measurement conditions</th>
<th>Range of Values</th>
</blockquote></tr>
<tr>
<blockquote><td>TP1</td>
<td>Tests the output coming from RP3, should be high until called upon, at which point it will go to low.</td>
<td>3V</td>
</blockquote></tr>
<tr>
<blockquote><td>TP2</td>
<td>Tests the output coming from RC0, should be high until called upon, at which point it will go to low.</td>
<td>3V</td>
</blockquote></tr>
<tr>
<blockquote><td>TP3</td>
<td>Tests the output coming from RC1, should be high until called upon, at which point it will go to low.</td>
<td>3V</td>
</blockquote></tr>
<tr>
<blockquote><td>Switch Pin 1,3(Refer to Schematic)</td>
<td>This is the microcontroller reset path, it will have continuity when pressed, meaning the MCLR pin will go to ground and will reset the device.</td>
<td>0V</td>
</blockquote></tr>
</table></blockquote>

<h2>Function List</h2>

The flowchart for the main code is in the <a href='https://code.google.com/p/thecogs-reflectiveshield2-ecen4013/wiki/uController#Main_Code'>uController research</a>. The modified function headers is as follows:

_iRInterrupt();_
-	This function is for defining what happens when an IR transmission is detected. Therefore it is not called directly by the main program but is entered upon a level trigger detected by the microcontroller. It will also check to determine if the MIRP packet is a valid attack packet and set the global variable of irOccured to a ‘1’ if so. This interrupt will have the highest priority of any interrupt.

_void startCDTimer(void);_
-	Clears the timer register, loads the desired period (1 second), starts the timer, and enables the pushbuttons.

_void canBusTX(void);_
-	CANbus communication will occur once this function is called. It will be called whenever the shield has become destroyed.

_void lightTransmit(char light);_
-	The function lightTransmit is designed to take in an integer value between 0 and 8 (0b000 to 0b111). A switch statement will follow this function header and will initiate the SPI communication based on int lightChoice.

_void iRTX(char iRChoice);_
-	Will send out the IR packet based on the global variable “pushedBttn”.

_void init(void);_
-	This function will initialize everything that has to do with the microcontroller and the inputs/outputs of the peripherals. Sets up the internal oscillator, sets pins to digital, sets audio pins high and output, turns on the HP LED’s, sets up the SPI communication, maps CAN to RP pins, sets up the input captures and the corresponding RP pins, enables the CN interrupts and pins, and finally sets up the countdown timer.

_void__attribute__((__interrupt__,__shadow__,no\_auto\_psv))_T1Interrupt(void);_-	After every period “overflow” will increment the timer counter and after 5 interrupts it will stop the timer, disable button interrupts, and transmit the lights based on the current time value.
void audioTransmit( int soundChoice )
The function audioTransmit is designed to take in an integer value between 0 and 8 (0b000 to 0b111). A switch statement will follow this function header and will set the I/O pins that the ISD1932 is connected to according to the desired sound._

_void audioTransmit( int soundChoice );_
-	The function audioTransmit is designed to take in an integer value between 0 and 8 (0b000 to 0b111). A switch statement will follow this function header and will set the I/O pins that the ISD1932 is connected to according to the desired sound.