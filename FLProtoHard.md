<h1>Front Lighting Prototyping</h1>

<img src='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/FrontLghting/Proto_Hardware_FrontLighting_headerimg.jpg' height='300px' />


<h2>Table of Contents</h2>




---


## Circuit Schematic ##

![https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/FrontLghting/Proto_Hardware_FrontLighting_sch.png](https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/FrontLghting/Proto_Hardware_FrontLighting_sch.png)

## PCB Layout ##

![https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/FrontLghting/Proto_Hardware_FrontLighting_pcb.png](https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/FrontLghting/Proto_Hardware_FrontLighting_pcb.png)

## Components ##

<ul>
<blockquote><li>2 TLC5952 LED Driver Chips</li>
<li>2 24x1 Header Pins</li>
<li>2 5x1 Header Pins</li>
<li>8 RGB LEDs</li>
<li>24 RED LEDs</li>
<li>2 2.43kOHM Resistors</li>
</ul></blockquote>

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

<img src='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/FrontLghting/Proto_Hardware_FrontLighting_output_clock.jpg' height='200' />

##### Data #####

<img src='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/FrontLghting/Proto_Hardware_FrontLighting_output_data.jpg' height='200' />

##### Latch #####

<img src='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/FrontLghting/Proto_Hardware_FrontLighting_output_latch.jpg' height='200' />