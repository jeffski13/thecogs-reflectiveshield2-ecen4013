<h1>Human Interface Prototyping</h1>

<img src='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/HumanInterface/Proto_Hardware_HumanInterface_headerimg.jpg' height='200px' />


<h2>Table of Contents</h2>




---

## Health Meter ##


### Circuit Schematic ###

![https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/HumanInterface/Proto_Hardware_HumanInterface__damageMeter_sch.png](https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/HumanInterface/Proto_Hardware_HumanInterface__damageMeter_sch.png)

### PCB Layout ###

![https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/HumanInterface/Proto_Hardware_HumanInterface_damageMeter_pcb.png](https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/HumanInterface/Proto_Hardware_HumanInterface_damageMeter_pcb.png)

### Components ###

<ul>
<blockquote><li>2 Green LED's</li>
<li>2 Red LED's</li>
<li>2 Yellow LED's</li>
<li>6 2N2222A BJT's</li>
<li>4 120 OHM Resistors (for Green and Yellow LED's)</li>
<li>2 100 OHM Resistors (for Red LED's)</li>
<li>6 3.3kOHM Resistors</li>
</ul></blockquote>

### Health Meter Inputs ###

<table border='2px'>
<blockquote><tr>
<blockquote><th>Input Name</th>
<th>Description of Signal</th>
<th>Expected Range</th>
</blockquote></tr>
<tr>
<blockquote><td>LED Power</td>
<td>Power supply feeds the current to the LED</td>
<td>5.5-4.5V (27-22mA for each LED)</td>
</blockquote></tr>
<tr>
<blockquote><td>BJT Input Signal</td>
<td>Logic Signal from uController: Pins HP1-HP6</td>
<td>3.3V (>0.6mA)</td>
</blockquote></tr>
</table></blockquote>


### Health Meter Outputs ###

<table border='2px'>
<blockquote><tr>
<blockquote><th>Output Name</th>
<th>Description of Signal</th>
<th>Expected Range</th>
</blockquote></tr>
<tr>
<blockquote><td>Light from LEDs</td>
<td>Luminosity / light intensity</td>
<td>520-640nm / 900-1200mcd</td>
</blockquote></tr>
</table></blockquote>

## Buttons ##


### Circuit Schematic ###

![https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/HumanInterface/Proto_Hardware_HumanInterface_Buttons_sch.png](https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/HumanInterface/Proto_Hardware_HumanInterface_Buttons_sch.png)

### Components ###

<ul>
<blockquote><li>1 Button</li>
<li>1 Green LED</li>
<li>10kOHM Resistor</li>
</ul></blockquote>

### Buttons Inputs ###

<table border='2px'>
<blockquote><tr>
<blockquote><th>Input Name</th>
<th>Description of Signal</th>
<th>Expected Range</th>
</blockquote></tr>
<tr>
<blockquote><td>Button Press</td>
<td>Button State</td>
<td>Pressed/Not Pressed</td>
</blockquote></tr>
<tr>
<blockquote><td>Power</td>
<td>Logic power voltage</td>
<td>3.0V-3.3V</td>
</blockquote></tr>
</table></blockquote>


### Health Meter Outputs ###

<table border='2px'>
<blockquote><tr>
<blockquote><th>Output Name</th>
<th>Description of Signal</th>
<th>Expected Range</th>
</blockquote></tr>
<tr>
<blockquote><td>Button Voltage</td>
<td>Logic signal to PIC</td>
<td>0v or 3.0V-3.3V</td>
</blockquote></tr>
</table></blockquote>

##### Button Voltage #####

<img src='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/HumanInterface/Proto_Hardware_HumanInterface_button_output.jpg' height='200' />

The figure above shows the button pressed on with a 5V signal (instead of the 3.3V that will be used in the final integration).