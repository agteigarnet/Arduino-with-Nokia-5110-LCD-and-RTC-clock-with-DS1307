# Arduino-with-Nokia-5110-LCD-and-RTC-clock-with-DS1307
<b>Simple Arduino sketch to make  a digital clock using Nokia 5110 LCD and DS1307 RTC</b>

Inspired by Educ8s.com tutorial, that use a DS1302 RTC module. 
<br>
See <a href="https://youtu.be/pN59R0eoXUQ" target="_blank">his video</a> on Youtube.

This modified version works with DS1307 RTC.

Other changes compared to the original script:
- display the day of the week
- management of the two-digit for hours, minutes, days and months
- flashing dot between the digits of hours and minutes

Arduino Libraries needed:
 - LCD5110_Graph (http://www.rinkydinkelectronics.com/library.php?id=47)
 - Time (https://github.com/PaulStoffregen/Time)
 - Wire (https://www.arduino.cc/en/Reference/Wire)
 - DS1307RTC (https://www.pjrc.com/teensy/td_libs_DS1307RTC.html)

You must, first of all, upload the "TimeRTCSet.pde" example of the Time library (obviously to set the time on DS1307 RTC), then you can upload my sketch.
Check connections between Arduino and LCD, according to your needs. 
If unsure, see LCD5110_Graph library docs or tutorials on the Net to see how connect Arduino and Nokia LCD.

Feel free to comunicate to me every improvement to script if you think is necessary, or eventually some bug that you find.
I hope you enjoy this little script.

<div align="center">
<a href="http://wtfpl.net" target="_blank"><img src="http://www.wtfpl.net/wp-content/uploads/2012/12/wtfpl-badge-1.png"></a>
</div>
