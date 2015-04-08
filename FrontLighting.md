<h1>Front Lighting</h1>

<img src='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Research/FrontLighting/Research_FrontLighting_headerimg.png' height='300px' /> ACK: Prefecto

<h2>Table of Contents</h2>




---


## Quick Links ##

<a href='http://www.electrosome.com/expanding-output-pins-pic-microcontroller-multiplexing'>Expanding I/O Pins</a>

## Design Challenges ##

The following <a href='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/ReflectiveShield2.0_MarketingReqs.pdf'> marketing requirements</a> had a significant impact in the design of the front lighting:

<ul>
<blockquote><li>MRS 5a: The shield must alert the user with visual and audible indication when the shield has absorbed a valid magical attack.  A countdown timer should be implemented to indicate when the user should release the stored energy.</li>
<li>MRS 5b: The shield should have a health count and decrement with each unsuccessful reflection i.e. when the user doesn’t release the energy absorbed.</li>
<li>MRS 5c: The shield must alert other players when an attack or a healing packet has been reflected by the shield both visually and audibly.</li>
<li>MRS 6a: The shield must be adorned with fabulous, attractive, and animated lighting.</li>
<li>MRS 6b: Each animation should correspond to the received or transmitted MIRP packet.</li>
</ul></blockquote>

The second incarnation of the reflective shield is well known for its bizarre display of lights when it is being used, a departure from the somber appearance of its older, and weaker, sibling.

For the LEDs we knew that quantity of lights was important to make the shield look “fabulous” but also have the ability to better display the actions like attack and heal in color form (ex. red = attack, green = heal). Brightness of the regular LEDs was made prevalent, as our methods kit red LEDs (our color of choice) was not at the brightness intensity we were happy with. The current draw was also a major concern, as you get too many LEDs on the shield that puts further constraints on the battery to obtain the minimum 2 hour battery life. So we decided on 12 RGBs with regular 36 LEDs. We are planning on these LEDs being Though-hole through the front of the shield, With the RGBs in the center and the regular LEDs around the outside in some type of ring fashion.

## The LED Driver: TLC5952 ##

The TLC5952 was chosen for a variety of reasons. First, many shift registers I ran into had only 8 or 16 outputs. This chip has 24 outputs to allow us to use less number of chips for our mass of lights. Another reason for this choice was that it is an RGB LED driver specifically, so the chip already includes the necessary hardware and firmware for easy integration with our RGB LEDs. This will also allow us to control brightness of our other regular LEDs easily without the need for learning new code for the input. This chip also has an input for max current reference, relieving us of having to hook resistors up to individual LEDs.

![https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Research/FrontLighting/Research_FrontLighting_HardwareDemo.png](https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Research/FrontLighting/Research_FrontLighting_HardwareDemo.png)

The micro-controller will serially send 25 bits to each chip every time we want to update the brightness control (BC) or on/off of each LED. The 25th bit (MSB) on each chip is used to determine if the next 24 bits are for BC or on/off data. For the on/off data each bit turns on or off a corresponding output of the chip. For the BC the first group of 7 bits (0-6) corresponds to the brightness of the “red group” (OUTR0-OUTR7). The next 7 bits (7-13) corresponds to the brightness control of the “green group” (OUTG0-OUTG7). The next 7 bits (14-20) corresponds to the brightness control of the “blue group” (OUTB0-OUTB7). The last 3 bits before the MSB are used to set the error detection type.

### Risks ###

The primary concern is that for the “blue group” channels it has a lower current through those outputs compared to the red and green group. This problem is easily correctable through the brightness control of the red and green group to properly match the output current of the blue.

## The Lights ##
Our first choice of regular LED color is red, but we are skeptical of red since our circuit kit red LEDs aren’t as bright as we hope for. For this reason I looked into extra bright red LEDs (WP7113SEC/J3). These have clear red lens and have more luminous intensity per amount of current compared with a lot of LEDs. For all the LEDs we decided to go with through-hole because of our shield size and the spread of them across the shield. Also we wanted the lights to stand out and be a very prominent feature of the shield.

For the RGB LEDs we also wanted a through-hole design in a single package to simplify putting it together. The RGB has a clear lens is through-hole and is all containing it a package the same size as our regular LEDs. This will make fabrication a little easier for the RGB holes to be the same size. This RGB is brighter compared to similar RGBs and also is on the cheaper side at about $1.17 per RGB when ordering over 10 compared to $4+ on other similar products.

## Lighting Code ##
For the lighting portion of the code will work similarly as the audio code. The main code will call the lighting function with some identifier integer, each integer will correspond to a routine in lighting for the specific action that happens. These cases will include all of the cases for audio (ex. Countdown, absorbed magic attack, send healing packet, etc.). The lighting will also have an idle lighting routine as well as potentially a few more. Since the lighting routine number isn’t limited like the number of sounds we are more open to implement more routines over the essential.
The function header is lightTransmit(int lightChoice); will have the first cases similar to audio with a few more cases that can easily be added whenever.

<img src='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Research/FrontLighting/Research_FrontLighting_Flowchart.png' width='600px' />

Switch (lightChoice)
<ul>
<blockquote><li>Case 0:</li>
<blockquote><ul><li>Nothing is done. (potentially idle light routine)</li></ul>
</blockquote><li>Case 1:</li>
<blockquote><ul><li>Routine for absorbed magic attack</li></ul>
</blockquote><li>Case 2:</li>
<blockquote><ul><li>Routine for countdown</li></ul>
</blockquote><li>Case 3:</li>
<blockquote><ul><li>Routine for attack packet</li></ul>
</blockquote><li>Case 4:</li>
<blockquote><ul><li>Routine for healing packet</li></ul>
</blockquote><li>Case 5:</li>
<blockquote><ul><li>Routine for take damage</li></ul>
</blockquote><li>Case 6:</li>
<blockquote><ul><li>Routine for shield breaking</li></ul>
</blockquote><li>Case 7:</li>
<blockquote><ul><li>Routine for cheat code</li></ul>
</blockquote><li>Case 8:</li>
<blockquote><ul><li>Routines for more cases if desired</li></ul>
</blockquote><li>Default Case:</li>
<blockquote><ul><li>No lights(or idle routine)</li></ul>
</ul></blockquote></blockquote>

## Sources ##

Perfecto(2002-2011) “what is LED ?” [Online](Online.md) Available: http://www.ledscreenchina.com/led-display-news/page/2/



Texas Instruments(2013) “24-Channel, Constant-Current LED Driver with
Global Brightness Control and LED Open-Short Detection” [Online](Online.md) Available: http://www.ti.com/lit/ds/sbvs129/sbvs129.pdf