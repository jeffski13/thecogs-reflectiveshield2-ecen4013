<h1>uController Prototyping</h1>

<img src='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/uController/Proto_Hardware_uController_headerimg.jpg' height='300px' />


<h2>Table of Contents</h2>




---


## Circuit Schematic ##

![https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/uController/Proto_Hardware_uController_sch.png](https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/uController/Proto_Hardware_uController_sch.png)

## PCB Layout ##

![https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/uController/Proto_Hardware_uController_pcb.png](https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/uController/Proto_Hardware_uController_pcb.png)

## Components ##

<ul>
<blockquote><li>PIC24HJ128GP504 I/PT</li>
<li>1 10kOHM Resistor</li>
<li>1 392 OHM Resistor</li>
<li>1 10uF Cap (Ceramic)</li>
<li>5 0.1uF Cap (Ceramic)</li>
<li>1 Mountain Switch</li>
<li>1 100 OHM Resistor</li>
<li>1 SMT LED (Yellow)</li>
<li>4 11x1 Headers</li>
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

<img src='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/uController/Proto_Hardware_uController_input_vdd.jpg' height='200' />

DC 5V Input Signal

##### Vss Input #####

<img src='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/uController/Proto_Hardware_uController_input_vss.jpg' height='200' />

DC 5V Signal from Microphone

## Hardware Outputs ##

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

<img src='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/uController/Proto_Hardware_uController_output_rb3.jpg' height='200' />

##### RC0 Output #####

<img src='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/uController/Proto_Hardware_uController_output_rc0.jpg' height='200' />

##### RC1 Output #####

<img src='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/uController/Proto_Hardware_uController_output_rc1.jpg' height='200' />


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
</table>