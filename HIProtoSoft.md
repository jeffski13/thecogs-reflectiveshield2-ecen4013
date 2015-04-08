<h1>Human Interface Software Prototyping</h1>

<img src='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Software/HumanInterface/Proto_Software_HumanInterface_headerimg.png' height='300px' />


<h2>Table of Contents</h2>




---


## Public Function List ##

The flow chart for the transmit code can be located on the <a href='https://code.google.com/p/thecogs-reflectiveshield2-ecen4013/wiki/IRCommunication#Flowchart'>IR research</a> page.

_void updateHP(void)_
decrements the damage meter LED's on the back of the shield

_`void __attribute__((interrupt,no_auto_psv)) _CNInterrupt(void)`_
The ISR (interrupt service routine) for the Heal and Attack Button presses