<h1>Human Interface</h1>

ourshieldcutout

<h2>Design Challenges<h2 />

The following <a href='http://ecen4013.okstate.edu/docs/project2/fa2013/Reflective%20Shield%202.0.pdf'> marketing requirements</a> had a significant impact in the design of the human interface:<br>
<br>
<ul>
<blockquote><li>MRS 7a: Being a shield it should reasonably resemble an arm mounted shield.</li>
<li>MRS 7b: Should be light weight (easily carried on one arm) and durable in design.</li>
<li>MRS 7c: Should be usable by both left and right handed users.</li>
<li>MRS 7d: Dimensions: should not exceed 2 square feet in area and 1.5 inches in thickness.</li>
</ul></blockquote>

The human interface research consists of finding the best way to create a user friendly interaction with the shield. This research explains how the shield is formed while coordinating with other team member’s block diagram and meeting the above requirements.<br>
<br>
<h2>Form Factor and Casing</h2>

This research consisted of finding a “cool” look of the shield and what type of material should be made of without interfering with the components used. The requirements ask for a light weight arm mounted shield for both left and right arm, with dimensions that should not exceed 2square feet in area and 1.5 inches in thickness (MRS 7d).<br>
<br>
<h2>Arm Mounts</h2>

The easiest way to arm mounted the shield was to wire up two identical strips in the back of the shield that can be adjusted for left and right hand arm and any size.<br>
<br>
The pictures below show a the concept of the material and mounting style.<br>
<br>
ARMMountPics<br>
<br>
<h2>Indicators</h2>

All the required visual indicators will be displayed using 36 regular LEDs (5mm) and 12 RGB LEDs (5mm). The LED locations where choose wisely to simplify and accommodate the wiring. All the required visuals (LEDs) will be distributed all around the front of shield. Below are diagrams of LED, RGB-LED, and Health-Meter placements.<br>
<br>
LED<br>
RGB<br>
HPMeter<br>
<br>
<h2>Visual Animation</h2>

This research consists on finding diverse lighting patterns regarding the different types of action the shield is performing.<br>
<br>
The picture below shows that numbering scheme for the <a href='https://code.google.com/p/thecogs-reflectiveshield2-ecen4013/wiki/FrontLighting'>front lighting</a>

LightingSCHEMEPIC<br>
<ol>
<blockquote><li>POWERING UP</li>
<ol>
<blockquote><li>When powering up the shield by pressing the power button. The shield should light up the entire front LEDs from the inside (center) to the outside like a swirl.</li>
<li>The LEDs will turn and stay on one every 1/4sec.</li>
<li>The RGB LEDs (eyes) will blink different colors each 1/4sec.</li>
</blockquote></ol>
<li>NORMAL MODE<br>
<ol>
<blockquote><li>After the powering up mode the shield will light up 6 LEDs on the back to display the maximum life and the RGB LEDs (eyes) should maintain green.</li>
<li>RGB LEDs should stay green every time unless in other mode.</li>
</blockquote></ol>
<li>ABSORB</li>
<ol>
<blockquote><li>When the shield gets attacked we know that the shield can only absorb “energy” for 5 seconds. The LEDs will blink from outside to center (5sec):</li>
<li>LED Ring 1 should light for 1 sec then turn off…</li>
<li>LED Ring 2 should light for 1 sec then turn off…</li>
<li>LED Ring 3 should light then stay on and RGBs should bright up.</li>
<li>LED Ring 2 should light then stay on,</li>
<li>LED Ring 1 should light then stay on, and RGBs should bright up.</li>
<li>Note: that it works like a countdown as the shield gets fully light up it means its maximum energy abortion, it’s time to release.</li>
</blockquote></ol>
<li>ATTACK</li>
<ol>
<blockquote><li>When sending IR there are two types of packets: Healing and Attacking. For this animation will use the RGB LEDs to emit different colors to separate the healing from attacking. The LED will blink from inside to the outside of the shield.</li>
<li>LED Ring 3 should light for 1/4 sec then turn off…</li>
<li>LED Ring 2 should light for 1/4 sec then turn off…</li>
<li>LED Ring 1 should light for 1/4 sec then turn off… then loop back to i.</li>
<li>Note: When attacking the RGB lights stays on with red color.</li>
</blockquote></ol>
<li>HEALING</li>
<ol>
<blockquote><li>Consist doing the same thing as attacking but this time the LED RGBs will change from green color to color blue instead of RED.</li>
</blockquote></ol>
<li>DO NOTHING</li>
<ol>
<blockquote><li>When the shield is inactive for a period of 20 seconds this will enter in an “idle mode”. In this mode the LED of the shield will light up divided in 10 vertical lines each with 3 LEDs. Every second like an analog clock each 3 LEDs will turn on clockwise.</li>
<li>Starting at 1’oclock 3 LEDs (1-3) will turn on…</li>
<li>For every other second more 3 LEDs will turn on following in a clockwise pattern: 1sec (LEDs1-3), 2sec (LEDs4-6), 3sec (LEDs7-9)…</li>
<li>When all the 3x10 LEDs turned on, the animation starts over again from i.</li>
</blockquote></ol>
<li>DAMAGE</li>
<ol>
<blockquote><li>When the shield countdown exceeds 5 seconds, all the LEDs should blink.</li>
<li>If damage is taken all the LEDs should blink rapidly T=¼ sec.</li>
<li>The shield should go back to normal mode after 3 seconds if no other mode is activated.</li>
</blockquote></ol>
<li>HEALTHMETER “LIFE”</li>
<ol>
<blockquote><li>There are 6 LEDs on the back of the shield to display the health meter. When received damage greater than 200 packets an LED’s should turn off.</li>
<li>There is 6 LEDs for life 6x200 = 1200 life unit (packets) </li>
<li>Each LEDs will be assign a range of health: 6 leds MAX life (1200), 5 leds 1000 life units.</li>
<li>Since the MCU keeps track of the damage taken, it only has to display whenever the values change those 6 ranges.</li>
</blockquote></ol>
<li>GAME OVER</li>
<ol>
<blockquote><li>When all damage is taken the shield should “break”.</li>
<li>To indicate this all lights should blink similarly like damage taken but this time, the shield will have to be restarted in order to change and play again.</li>
</blockquote></ol>
<br>
<br>
Unknown end tag for </ol><br>
<br>
<br>
<h2>Buttons</h2>
For this projects it’s necessary to use two buttons to control the types of emitting IRs one for healing use green button and one for attacking use red button. The buttons selected for this research where arcade push-buttons to make it game user friendly.</blockquote>

PICofCurrentButton<br>
<br>
<h2>Health Meter</h2>

<table>
<blockquote><tr>
<blockquote><td>$0.15</td>
<td>$0.15</td>
</blockquote></tr>
</table>