<h1>IR Communication</h1>

![https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Research/IR/Research_IR_headerimg.jpg](https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Research/IR/Research_IR_headerimg.jpg) ACK: Thermibel S.A.

<h2>Table of Contents</h2>




---


## Design Challenges ##

The following <a href='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/ReflectiveShield2.0_MarketingReqs.pdf'> marketing requirements</a> had a significant impact in the design of the infrared communication:
<ul>
<blockquote><li>MRS 2a:The shield must be able to communicate through MIRP packets and CANbus.</li>
<li>MRS 2b:The shield must be able to receive valid MIRP packets.</li>
<li>MRS 2c:The shield must be able to absorb and reflect Magical Attack MIRP packets and healing MIRP packets.</li>
<li>MRS 3a:The shield must be able to receive MIRP packets with an angle relatively close to 180 degrees. </li>
<li>MRS 2b:The shield must be able to receive MIRP packets with an angle relatively close to 180 degrees. </li>
<ul>
<blockquote><li>i. Absorb and reflect the same magical attack packet. OR </li>
<li>ii. Absorb the attack “energy” and allow the user to change it to a healing packet to emit.</li>
</blockquote></ul>
<li>MRS 4a:The shield must be able to emit MIRP packets with at least a 90 degree spread from the shield.  </li>
<li>MRS 4b:The transmitted MIRP packets must be able to achieve at most 10% error rate at 35 ft range.</li>
</ul></blockquote>

## Transmit Design ##

For the IR transmit block, two LEDs were required to achieve the required transmission angle for the project. The use of two LEDs is actually beneficial when it comes to the transmission distance requirement. To save current draw from the battery, I designed the circuit with the two LEDs in series. The LED is rated at a forward voltage of 1.2 – 1.6 V depending on the current flow, and a continuous forward current of 100mA. Unfortunately the pic microcontroller is unable to sink enough current for the LED to operate effectively. Therefore a BJT was implemented to allow greater current flow. The resistor Rc sets the current flow for the device. The alternative for using a BJT was a mosfet transistor. This would have worked for this situation, but for what I need it to do a mosfet is overkill. Mosfets are generally used for faster applications and are more costly than a BJT.

<h3>Lumex OED-EL-1L2</h3>
The Lumex OED-EL-IL2 has the following qualities:
<ul>
<blockquote><li>Transmits a 940 nm signal</li>
<li>60 mW/SR</li>
<li>60 degree angle of transmission</li>
</ul></blockquote>

### Schematic and Calculations ###

<img src='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Research/IR/Research_IR_Send_Sch.jpg' height='300px'></img>

### Simulation ###

<img src='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Research/IR/Research_IR_SimSch.jpg' width='600'></img>

<img src='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Research/IR/Research_IR_SimResultsGraph.jpg' width='600'></img>

Note: The LEDs used in the simulation were set to a forward voltage drop of 1.6 V. This led to a reduced current flow. This can be corrected with a lower [R2](https://code.google.com/p/thecogs-reflectiveshield2-ecen4013/source/detail?r=2).


### Flowchart ###

The code is split up into 3 functions. The first function singleCycle() sets up the timer to count up to one half period of 56KHz, or (9 µS). It then sets the IR\_TX pin high for one cycle and then low for the next. This transmits one cycle through the IR emitter.
The next function burst(int length) loops the function singleCycle() length number of times. The last function is iRTransmit() this function implements the previous two functions to send out a damage/healing packet per mirp protocol.

<img src='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Research/IR/Research_IR_Flowchart_iCalls.png' height='500'></img>

## Receive Design ##

For the IR receiver block, 3 receivers will be implemented to achieve our desired requirement of 180 degree reception. The schematic for the receiver is fairly simple and came from the application notes in the datasheet.

### Vishay TSOP34456 ###
The Lumex OED-EL-IL2 has the following qualities:
<ul>
<blockquote><li>56KHz carrier frequency</li>
<li>Operates on 2.2-5V supply voltage</li>
<li>90 degree reception angle</li>
</ul></blockquote>

### Flowchart ###

<img src='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Research/IR/Research_IR_Flowchart_interrupt.png' height='500'></img>

## Sources ##

Thermibel S.A., “What is infra-red?” `[Online]` Available: http://www.thermibel.be/documents/laboratory/labo-infrared.xml?lang=en