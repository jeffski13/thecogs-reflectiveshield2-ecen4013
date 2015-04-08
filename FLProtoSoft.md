<h1>Front Lighting Software Prototyping</h1>

<img src='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Software/FrontLighting/Proto_Software_FrontLighting_headerimg.png' height='300px' />


<h2>Table of Contents</h2>




---


## Software Inputs ##

<table border='2px'>
<blockquote><tr>
<blockquote><th>Input Name</th>
<th>Description of Signal</th>
<th>Expected Range</th>
</blockquote></tr>
<tr>
<blockquote><td>char light</td>
<td>Char value depending of the light routine to run</td>
<td>1 to 8</td>
</blockquote></tr>
</table></blockquote>

## Public Function List ##

The flowchart for the front lighting code is in the <a href='https://code.google.com/p/thecogs-reflectiveshield2-ecen4013/wiki/FrontLighting#Lighting_Code'>front lighting research</a>. The modified function headers is as follows:

_void lightTransmit(char light);_
-	Case statement to determine which lighting routine to run


## Source Code ##

> lighting.h