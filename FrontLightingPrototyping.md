<h1>Front Lighting Prototyping</h1>

<img src='http://i.imgur.com/E90uafZ.jpg' height='300px' />


<h2>Table of Contents</h2>




---


## Circuit Schematic ##

![http://i.imgur.com/9hZWHPv.png](http://i.imgur.com/9hZWHPv.png)

## PCB Layout ##

![http://i.imgur.com/Hec7QwO.png](http://i.imgur.com/Hec7QwO.png)

## Components ##

<ul>
<blockquote><li>2 TLC5952 LED Driver Chips</li>
<li>2 24x1 Header Pins</li>
<li>2 5x1 Header Pins</li>
<li>8 RGB LEDs</li>
<li>24 RED LEDs</li>
<li>2 2.43kOHM Resistors</li>
</ul></blockquote>

## Software Inputs ##

Lighting Code Input

<table border='2px'>
<blockquote><tr>
<blockquote><th>Input Name</th>
<th>Description of Signal</th>
<th>Expected Range</th>
</blockquote></tr>
<tr>
<blockquote><td>char light</td>
<td>Char value depending of the light routine to run</td>
<td>0 to 7</td>
</blockquote></tr>
<tr>
<blockquote><td>chipNum</td>
<td>Number of LED driver chips currently being used</td>
<td>1 to 4</td>
</blockquote></tr>
</table></blockquote>

## Software Outputs ##

<table border='2px'>
<blockquote><tr>
<blockquote><th>Output Name</th>
<th>Description of Signal</th>
<th>Expected Range</th>
</blockquote></tr>
<tr>
<blockquote><td>CLOCK12</td>
<td>Clock turns high and low to capture from the data line</td>
<td>0v or 3.3v</td>
</blockquote></tr>
<tr>
<blockquote><td>DATA13</td>
<td>Data is high or low depending on the bit for the led it’s controlling</td>
<td>0v or 3.3v</td>
</blockquote></tr>
<tr>
<blockquote><td>LATCH11</td>
<td>Goes high to update the lights</td>
<td>0v or 3.3v</td>
</blockquote></tr>
</table></blockquote>

##### Clock #####

<img src='http://i.imgur.com/R3SVqAd.jpg' height='200' />

##### Data #####

<img src='http://i.imgur.com/ONCEpy3.jpg' height='200' />

##### Latch #####

<img src='http://i.imgur.com/MtmR21B.jpg' height='200' />

## Hardware Inputs ##

LED Driver Inputs

<table border='2px'>
<blockquote><tr>
<blockquote><th>Input Name</th>
<th>Description of Signal</th>
<th>Expected Range</th>
</blockquote></tr>
<tr>
<blockquote><td>LED Power</td>
<td>3.3V Power from Power Supply</td>
<td>3.0V-3.3V, 20mA for each LED</td>
</blockquote></tr>
<tr>
<blockquote><td>TLC5952 Chip Power</td>
<td>3.3V Power from Power Supply</td>
<td>3.0V-3.3V, 20-50mA</td>
</blockquote></tr>
</table></blockquote>

## Hardware Outputs ##

LED Driver Output

<table border='2px'>
<blockquote><tr>
<blockquote><th>Output Name</th>
<th>Description of Signal</th>
<th>Expected Range</th>
</blockquote></tr>
<tr>
<blockquote><td>24 Outputs to LEDs</td>
<td>Sinks specific channels to turn LEDs on</td>
<td>No current or current sink</td>
</blockquote></tr>
</table></blockquote>

## Software Function List ##

The flowchart for the front lighting code is in the <a href='https://code.google.com/p/thecogs-reflectiveshield2-ecen4013/wiki/FrontLighting#Lighting_Code'>front lighting research</a>. The modified function headers is as follows:

CALLED BY MICHAEL
_void lightTransmit(char chipNum, char light);_
-	Case statement to determine which routine to run

NOT CALLED by MICHAEL
_void writeBRIT(char chipNum, char britInfo`[chipNum][24]`);_
-	Manually sends 25\*chipNum of bits to the LED drivers with the MSB on each chip equal to 1

_void writeONOFF(char chipNum, char lightInfo`[chipNum][24]`);_
-	Manually sends 25\*chipNum of bits to the LED drivers with the MSB on each chip equal to 0