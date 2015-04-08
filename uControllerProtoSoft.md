<h1>Main Software Prototyping</h1>

<img src='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Software/MainCode/Proto_Software_MainCode_headerimg.png' height='300px' />


<h2>Table of Contents</h2>




---


## Function List ##

The flowchart for the main code is in the <a href='https://code.google.com/p/thecogs-reflectiveshield2-ecen4013/wiki/uController#Main_Code'>uController research</a>. The modified function headers is as follows:

_`void __attribute__((__interrupt__, __shadow__,no_auto_psv)) _T4Interrupt(void);`_
-	update the lights and audio every 553 interrupts (equal to 1 second). If the 5th second has been reached, reset timer counter, turn off timer (will break while loop in main.c), and disable buttons.

_void startCDTimer(void);_
-	Clears the timer register, loads the desired period (1 second), starts the timer, and enables the pushbuttons.

_void canBusTX(void);_
-	<a href=''>CAN bus Software</a>

_void lightTransmit(char light);_
-	<a href=''>Front Lighting Software</a>

_void iRTX(char iRChoice);_
-	<a href=''>Front Lighting Software</a>

_void init(void);_
-	This function will initialize everything that has to do with the µController and the inputs/outputs of the peripherals. Sets up the internal oscillator, sets pins to digital, sets audio pins high and output, turns on the HP LED’s, sets up the SPI communication, maps CAN to RP pins, sets up the input captures and the corresponding RP pins, enables the CN interrupts and pins, and finally sets up the countdown timer.

void audioTransmit( char soundChoice )
-	<a href=''>Front Lighting Software</a>

_void allHigh( void );_
-	<a href=''>Front Lighting Software</a>