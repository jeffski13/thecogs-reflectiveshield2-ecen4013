<h1>Infrared Software Prototyping</h1>

<img src='https://thecogs-reflectiveshield2-ecen4013.googlecode.com/hg/wiki/Proto/Software/IR/Proto_Software_IR_headerimg.png' height='300px' />


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
<blockquote><td>char choice</td>
<td>iRTX: Send damage or healing packet</td>
<td>'h' or 'd'</td>
</blockquote></tr>
</table></blockquote>

## Public Function List ##

The flow chart for the transmit code can be located on the <a href='https://code.google.com/p/thecogs-reflectiveshield2-ecen4013/wiki/IRCommunication#Flowchart'>IR research</a> page.

_void iRTX(char choice)_
Send damage or healing packet via infrared. If _choice_ is 'd', a damage packet will be sent. If _choice_ is 'h', a healing packet will be sent.

## Source Code ##

> IR>??