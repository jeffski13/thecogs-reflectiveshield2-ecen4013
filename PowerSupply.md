<h1>Power Supply</h1>

![https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Research/Power/Research_Power_headerimg.jpg](https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Research/Power/Research_Power_headerimg.jpg) ACK:Anker

<h2>Table of Contents</h2>




---


## Quick Links ##

<a href='http://www.ianker.com/download.php?file=download/781A6F4FAC454A6_79ANS1052-BA%20manual%20-1.jpg'>Astro 3E Owners Manual</a> <a href='http://www.mouser.com/ds/2/468/R-78Bxx-1.0_L-225953.pdf'> Recom R-78B3.3-1.0L Datasheet<a />

<h2>Design Challenges</h2>

The following <a href='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/ReflectiveShield2.0_MarketingReqs.pdf'> marketing requirements</a> had a significant impact in the design of the power supply:<br>
<br>
<ul>
<blockquote><li>MRS 6a: The shield must be adorned with fabulous, attractive, and animated lighting</li>
<li>MRS 7b: Should be light weight (easily carried on one arm) and durable in design.</li>
<li>MRS 7d: Dimensions: should not exceed 2 square feet in area and 1.5 inches in thickness.</li>
<li>MRS 8a: The shield must be internally powered.</li>
<li>MRS 8b: The power supply should be able to power the entire unit through at least 2 hours of game play.</li>
</ul></blockquote>

The primary design issues concerned the large amount of power necessary for the LED array needed in the <a href='https://code.google.com/p/thecogs-reflectiveshield2-ecen4013/wiki/FrontLighting'>front lighting<a /> (which includes thirty-six regular single-color LEDs as well as 12 RGB LEDs). At an estimated current consumption of 25mA each, this LED array draws an estimated max current of 1.6 amps. The marketing requirements specify that the Reflective Shield 2.0 must last a minimum of two hours. This, along with the tight spacial requirement of 1.5 inches, was a major influence on the power supply design. Included are schematics along with part numbers necessary for the prototyping stage of the design.<br>
<br>
<h2>Voltage Regulators</h2>

<p>Regardless of the power source chosen, there are usually differing voltage requirements for each function block of a design. Providing the correct consistent voltage and current necessary for the components is crucial for functionality. </p>
<p>There are two types of voltage regulators: Linear and Switching. Both regulators present different pros and cons that will be outlined in the following sections.</p>

<h3>Linear Regulators</h3>

<p>Linear regulators are simple regulators that utilize diodes. The efficiency is usually 50% or less. But they are cheap. Many regulators can be sold for under a dollar.</p>

<h3>Switching Regulators</h3>

Switching regulators are much more complex than the linear regulators. But with this complexity allows for higher efficiency and usually higher current. Because our project can draw a maximum of 2.110 Amps, efficiency is very important. With the added efficiency of the regulators (assumed to be around 80%) the maximum current drawn from the source itself would be 1.74075 A. This means that the source will actually have less current drawn from it because the input voltage (5V) is provided to give a certain power and the power will be used with less voltage and therefore more current in the output.<br>
Since our project actually does utilize a potential 2.110 A, switching regulators are preferred for our design and will allow for a lighter load on the power supply.<br>
<br>
<h2>Anker 3E Battery & Recom R-78B3.3-1.0L Regulators</h2>

<img src='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Research/Power/Research_Power_DesignSch.png' />

<h3>Benefits Analysis</h3>

The power supply chosen was the <a href='http://www.ianker.com/product/79ANS1052-BA'> Anker Astro 3E External Battery<a />. This power supply was chosen for the features outlined in the Astro 3E Datasheet (Appendix A: Datasheet 1). Notice in particular the large mAh rating. And at only $39.99, the Anker Astro 3E was the most affordable option. This battery also has a thickness of only 0.6 inches. This works well with the compact marketing requirement for the Reflective Shield 2.0 thickness (MRS 7d).<br>
<br>
The Astro 3E External Battery runs on USB power (at 5V). Most of the project requires 3.3V. To regulate the voltage a switching voltage regulator, the <a href='http://www.mouser.com/ds/2/468/R-78Bxx-1.0_L-225953.pdf'> Recom R-78B3.3-1.0L <a />, was chosen. The minimum input voltage is 4.75V. The switching regulator is more efficient with lower input voltage. Under the assumption that the regulator efficiency is linear, an efficiency of 88.94% can be assumed.<br>
<br>
<h3>Risk Analysis</h3>

The Astro 3E Extended Battery has internal smart software that controls the current output. An Anker representative has said that if the load is drawing 3A, the Astro 3E should be able to provide that current. However, there is a certain amount of uncertainty as the internals are a black box.<br>
<br>
There is also an assumption that the Astro 3E is providing a certain amount of voltage regulation, making it unnecessary to regulate the 5V bus. If this is not proven true during the testing, the option of a buck-boost filter will be entertained.<br>
<br>
<h2>Sources</h2>

Anker (2013) Anker Astro 3E 10000mAh External Battery (Black) <a href='Online.md'>Online</a> Available: <a href='http://www.ianker.com/product/79ANS1052-BA'>http://www.ianker.com/product/79ANS1052-BA</a>