<h1>Audio Prototyping</h1>

<img src='http://i.imgur.com/sA0M1mO.jpg' height='300px' />


<h2>Table of Contents</h2>




---


## Circuit Schematic ##

![http://i.imgur.com/eDE40Kf.png](http://i.imgur.com/eDE40Kf.png)

## PCB Layout ##

![http://i.imgur.com/vrcRvxr.png](http://i.imgur.com/vrcRvxr.png)

## Inputs ##

<table border='2px'>
<blockquote><tr>
<blockquote><th>Input Name</th>
<th>Description of Signal</th>
<th>Expected Range</th>
</blockquote></tr>
<tr>
<blockquote><td>Vcc</td>
<td>DC 5V Signal from Power Supply</td>
<td>5V</td>
</blockquote></tr>
<tr>
<blockquote><td>Microphone</td>
<td>Sinusoidal Audio Signal to PWM Signal Mic+ and Mic-</td>
<td>0V-5V</td>
</blockquote></tr>
<tr>
<blockquote><td>Record/Playback</td>
<td>Connected wither to Ground or Vcc controlled by a switch to produce a DC Signal</td>
<td>GND-5V</td>
</blockquote></tr>
<tr>
<blockquote><td>FMC1-FMC3</td>
<td>Connected to DC Signal of Vcc</td>
<td>5V</td>
</blockquote></tr>
<tr>
<blockquote><td>M1-M8</td>
<td>Input  0V (GND)</td>
<td>0V</td>
</blockquote></tr>
</table></blockquote>

##### Vcc Input #####

<img src='http://i.imgur.com/9z42N1m.jpg' height='200' />

DC 5V Input Signal

##### Microphone Input #####

<img src='http://i.imgur.com/bKqL7wd.jpg' height='200' />

DC 5V Signal from Microphone

##### Record/Playback Input #####

<img src='http://i.imgur.com/Ic3SxT8.jpg' height='200' /> <img src='http://i.imgur.com/IiA09h4.jpg' height='200' />

0V Signal Record Mode (GND)         5V Signal Playback Mode

##### FMC1-FMC3 Input #####

<img src='http://i.imgur.com/x1jdwAS.jpg' height='200' />

5V Signal for all FMC1-FMC3

##### M1-M8 Input #####

<img src='http://i.imgur.com/Ax3lSw9.jpg' height='200' /> <img src='http://i.imgur.com/wUfTcVs.jpg' height='200' />

3.2V Signal from M1-M8 pins (Before Input)   0V Signal from M1-M8 pins (GND) (After Input)

## Outputs ##

<table border='2px'>
<blockquote><tr>
<blockquote><th>Output Name</th>
<th>Description of Signal</th>
<th>Expected Range</th>
</blockquote></tr>
<tr>
<blockquote><td>Speaker</td>
<td>PWM Audio Signal Spk+ Spk-</td>
<td>0V-5V<br>
60dB<br>
300Hz-20kHz<br>
</td>
</blockquote></tr>
</table></blockquote>

##### Speaker Output #####

<img src='http://i.imgur.com/HnWbV1f.jpg' height='200' />

Output 5V-0V Signal from Speaker Pin

## Test Points ##

<table border='2px'>
<blockquote><tr>
<blockquote><th>T.P. Name</th>
<th>Description of Signal and measurement conditions</th>
<th>Range of Values</th>
</blockquote></tr>
<tr>
<blockquote><td>Vcc</td>
<td>DC 5V Signal from Power Supply</td>
<td>5V</td>
</blockquote></tr>
<tr>
<blockquote><td>M1</td>
<td>No input (3.3V DC) Input (0V DC)</td>
<td>0V-3.3V</td>
</blockquote></tr>
<tr>
<blockquote><td>M7</td>
<td>No input (3.3V DC) Input (0V DC)</td>
<td>0V-3.3V</td>
</blockquote></tr>
<tr>
<blockquote><td>Speaker Output</td>
<td>PWM Audio Signal Spk+ Spk-</td>
<td>0V-5V<br>
60dB<br>
300Hz-20kHz<br>
</td>
</blockquote></tr>
</table></blockquote>

<table border='2px'>
<blockquote><tr>
<blockquote><th>Debug Location</th>
<th>Description of signal and debug statement method</th>
<th>Expected outputs</th>
</blockquote></tr>
<tr>
<blockquote><td>Header Pins</td>
<td>Used for probing to test continuity and voltage drops.</td>
<td>Voltages between 0V-5V</td>
</blockquote></tr>
<tr>
<blockquote><td>LED</td>
<td>Identification that the ISD chip is operating probably.</td>
<td>Illuminating Red Light</td>
</blockquote></tr>
</table></blockquote>

##### Vcc Test Point #####

<img src='http://i.imgur.com/ThObNBD.jpg' height='200' />

DC 5V Input Signal

##### M1 & M7 Test Points #####
<img src='http://i.imgur.com/kHqsBGv.jpg' height='200' /> <img src='http://i.imgur.com/4a36nHy.jpg' height='200' />

3.2V Signal from M1&M7 pins)         0V Signal from M1&M7 pins (GND)

##### Speaker #####
<img src='http://i.imgur.com/VeuRg9I.jpg' height='200' />

Output 5V-0V Signal from Speaker Pin