<h1>Audio Software Prototyping</h1>

<img src='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Software/Audio/Proto_Software_Audio_headerimg.png' height='300px' />


<h2>Table of Contents</h2>




---


## Software Inputs ##

<table border='2px'>
<blockquote><tr>
<blockquote><th>Input Name</th>
<th>Description</th>
<th>Expected Range</th>
</blockquote></tr>
<tr>
<blockquote><td>char soundChoice</td>
<td>char variable that defines which sound will be played</td>
<td>1-8</td>
</blockquote></tr>
</table></blockquote>

## Public Function List ##

The flowchart for the audio code is in the <a href='https://code.google.com/p/thecogs-reflectiveshield2-ecen4013/wiki/Audio?ts=1384709881&updated=Audio#Code_Flowchart'>audio research</a>.

_void audioTransmit(char soundChoice)_
audioTransmit is based off of what sound is chosen to be played. A switch statement will take care of this. It will set the pin low to play them and high again to turn them off. Default case is just a fail safe, it will reset all values high again (turning the sound off).

_void allLow(void)_
- Sets all pins for audio chip (ISD1932) to high
NOTE: When a pin is set low, a sound clip plays.