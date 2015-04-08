<h1>Audio Prototyping</h1>

<img src='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/Audio/Proto_Hardware_Audio_headerimg.jpg' height='300px' />


<h2>Table of Contents</h2>




---


## Circuit Schematic ##

![https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/Audio/Proto_Hardware_Audio_sch.png](https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/Audio/Proto_Hardware_Audio_sch.png)

## PCB Layout ##

![https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/Audio/Proto_Hardware_Audio_pcb.png](https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/Audio/Proto_Hardware_Audio_pcb.png)

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

<img src='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/Audio/Proto_Hardware_Audio_input_vcc.jpg' height='200' />

DC 5V Input Signal

##### Microphone Input #####

<img src='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/Audio/Proto_Hardware_Audio_input_nic.jpg' height='200' />

DC 5V Signal from Microphone

##### Record/Playback Input #####

<img src='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/Audio/Proto_Hardware_Audio_input_record.jpg' height='200' /> <img src='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/Audio/Proto_Hardware_Audio_input_playback.jpg' height='200' />

0V Signal Record Mode (GND)         5V Signal Playback Mode

##### FMC1-FMC3 Input #####

<img src='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/Audio/Proto_Hardware_Audio_input_fmc1-fmc3.jpg' height='200' />

5V Signal for all FMC1-FMC3

##### M1-M8 Input #####

<img src='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/Audio/Proto_Hardware_Audio_input_m1-m8.jpg' height='200' /> <img src='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/Audio/Proto_Hardware_Audio_input_m1-m82.jpg' height='200' />

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

<img src='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/Audio/Proto_Hardware_Audio_tp_speaker.jpg' height='200' />

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

<img src='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/Audio/Proto_Hardware_Audio_tp_vcc.jpg' height='200' />

DC 5V Input Signal

##### M1 & M7 Test Points #####
<img src='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/Audio/Proto_Hardware_Audio_tp_m1m71.jpg' height='200' /> <img src='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/Audio/Proto_Hardware_Audio_tp_m1m72.jpg' height='200' />

3.2V Signal from M1&M7 pins)         0V Signal from M1&M7 pins (GND)

##### Speaker #####
<img src='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Hardware/Audio/Proto_Hardware_Audio_tp_speaker.jpg' height='200' />

Output 5V-0V Signal from Speaker Pin