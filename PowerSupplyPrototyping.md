<h1>Power Supply Prototyping</h1>

<img src='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/Power/Proto_Hardware_Power_headerimg.jpg' height='300px' />


<h2>Table of Contents</h2>




---


The power supply had to demonstrate the ability to last a minimum of two hours (as per <a href='http://ecen4013.okstate.edu/docs/project2/fa2013/Reflective%20Shield%202.0.pdf'> marketing requirement</a> 8b). The battery lasted two hours on a full load.

The following shows the battery level indication throughout the testing process.

<img src='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/Power/Proto_Hardware_Power_batteryLevel1.jpg' width='250px' /> <img src='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/Power/Proto_Hardware_Power_batteryLevel2.jpg' width='250px' /> <img src='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/Power/Proto_Hardware_Power_batteryLevel3.jpg' width='250px' />

## Circuit Schematic ##

<img src='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/Power/Proto_Hardware_Power_sch.png' width='450px' />

## PCB Layout ##


## Hardware Inputs ##

<table border='2px'>
<blockquote><tr>
<blockquote><th>Input Name</th>
<th>Description of Signal</th>
<th>Expected Range</th>
</blockquote></tr>
<tr>
<blockquote><td>I1</td>
<td>5V input signal to headers</td>
<td>5V</td>
</blockquote></tr>
<tr>
<blockquote><td>I2</td>
<td>5V input signal to miniUSB (type-B)</td>
<td>5V</td>
</blockquote></tr>
</table></blockquote>


##### I1 and I2 Input #####

<img src='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/Power/Proto_Hardware_Power_input_i1i2.png' height='350' />

![https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/Power/Proto_Hardware_Power_input_i1i2table.png](https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/Power/Proto_Hardware_Power_input_i1i2table.png)

## Hardware Outputs ##
Output
Name




<table border='2px'>
<blockquote><tr>
<blockquote><th>Output Name</th>
<th>Description of Signal</th>
<th>Expected Range</th>
</blockquote></tr>
<tr>
<blockquote><td>O1</td>
<td>5V output to model resistor (25 kOhm)</td>
<td>5V</td>
</blockquote></tr>
<tr>
<blockquote><td>O2</td>
<td>3.3V output to model load resistor (4.7 kΩ)</td>
<td>3.0V -3.3V</td>
</blockquote></tr>
<tr>
<blockquote><td>O3</td>
<td>3.3V output to model load resistor (4.7 kΩ)</td>
<td>3.0V -3.3V</td>
</blockquote></tr>
<tr>
<blockquote><td>O4</td>
<td>3.3V output to model load resistor (4.7 kΩ)</td>
<td>3.0V -3.3V</td>
</blockquote></tr>
</table></blockquote>


##### O1, O2, O3, and O4 Output #####

<img src='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/Power/Proto_Hardware_Power_output_o1o2o3o4.png' height='350' />

![https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/Power/Proto_Hardware_Power_output_o1o2o3o4table.png](https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/Power/Proto_Hardware_Power_output_o1o2o3o4table.png)

## Test Points ##

<table border='2px'>
<blockquote><tr>
<blockquote><th>T.P. Name</th>
<th>Description of Signal and measurement conditions</th>
<th>Range of Values</th>
</blockquote></tr>
<tr>
<blockquote><td>TPV1</td>
<td>Power </td>
<td>4.5V-5V</td>
</blockquote></tr>
<tr>
<blockquote><td>TPV2</td>
<td>Power </td>
<td>3.0V-3.3V</td>
</blockquote></tr>
<tr>
<blockquote><td>TPV3</td>
<td>Power </td>
<td>3.0V-3.3V</td>
</blockquote></tr>
<tr>
<blockquote><td>TPV4</td>
<td>Power </td>
<td>3.0V-3.3V</td>
</blockquote></tr>
<tr>
<blockquote><td>TPI1</td>
<td>Load Current Draw </td>
<td>0 to 200mA<b></td>
</blockquote></tr></b><tr>
<blockquote><td>TPI2</td>
<td>Load Current Draw </td>
<td>0 to 700mA<b></td>
</blockquote></tr></b><tr>
<blockquote><td>TPI3</td>
<td>Load Current Draw </td>
<td>0 to 700mA<b></td>
</blockquote></tr></b><tr>
<blockquote><td>TPI4</td>
<td>Load Current Draw </td>
<td>0 to 700mA**</td>
</blockquote></tr>
</table></blockquote>**

