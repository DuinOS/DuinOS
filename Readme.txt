********************************
 DuinOS v0.3 Alpha
********************************

Copyright (C) 2009 Multiplo
http://multiplo.org
http://robotgroup.com.ar
Created by Julián U. da Silva Gillig.

Based on the FreeRTOS v6.1.0 kernel (www.freertos.org). Please see the License section below.
This is our only distribution of DuinOS, which includes the complete source code. The last version is always available
from http://robotgroup.com.ar


********************************
 License
********************************
The DuinOS kernel (cores\arduino.DuinOS) is under the same license as the FreeRTOS operating system (www.freertos.org)
Please see the included FreeRTOS.license.txt file.

We have used too, some files belonging to the AVR port of the FreeRTOS operating system, made by Micropendous 
(www.micropendous.org). As these files are modified FreeRTOS files, we understand they are under the same license as
the FreeRTOS kernel. We are grateful to Opendous Inc. for their valuable contribution to the open source community.
If there are some other files belonging to the Micropendous project, these may be under the following license:

Copyright Under the Creative Commons Attribution License
http://creativecommons.org/licenses/by/3.0/
By Opendous Inc.
www.Micropendous.org
October 04, 2009

Please visit www.micropendous.org if there is any doubt.

NOTE: We strongly believe in peace, so we would not like to see our work in any non-civil or military project. But, due
to the FreeRTOS's modified GPL license which we do have to maintain, this is only a recommendation and an expression of
our wishes.

	
********************************
 Installing DuinOS
********************************

0. Close the Arduino IDE (all instances).
1. Copy the arduino.DuinOS folder to the \hardware\cores folder.
2. Rename your current \hardware\boards.txt file.
3. Copy the boards.txt deployed with DuinOS to the \hardware folder.
4. Rename your current \lib\keywords.txt file.
5. Copy the keywords.txt deployed with DuinOS to the \lib folder.
6. Start the Arduino IDE.
7. Please select any DuinOS board from the Tools->Board menu, like the "Arduino Duemilanove or Nano w/ ATmega328 + DuinOS".
8. Now, you can compile any standard project, but we suggest the \examples\MoreComplexBlinking deployed with DuinOS.

********************************
 Uninstall 
********************************

0. Close the Arduino IDE (all instances).
1. If you have renamed the original boards.txt file, delete the current boards.txt file and rename the previous one (so it will be now your new boards.txt).
2. If you have renamed the original keywords.txt file, delete the current keywords.txt file and rename the previous one (so it will be now your new keywords.txt).
3. Delete the arduino.DuinOS folder from the \cores folder.
4. Now you can restart the Arduino IDE and keep working without DuinOS. 

********************************
 DISCLAIMER
********************************

THE SOFTWARE (AND ANY OTHER CONTENT) IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT 
LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT 
OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE MATERIALS ON THIS WEBSITE OR THE USE OR OTHER DEALINGS IN 
MATERIALS ON THIS WEBSITE.


********************************
 History / Change log
********************************

* 0.1.0 Alpha / 2009.11.02 (Julián U. da Silva Gillig. - http://robotgroup.com.ar )
- First version released DuinOS v0.1 Alpha.
- Arduino IDE updated to version 0017 ref
- FreeRTOS updated to version 5.4.2
- Add example MoreComplexBlinking (Blinks two LEDs)

* 0.2.0 Alpha / 2010.06.30 (Michael Grigorev aka CHERTS <sleuthhound@gmail.com>):
- Arduino IDE updated to version 0018
- FreeRTOS updated to version 6.0.5
- Add new example MoreComplexBlinkingAndSound (Blinks two LEDs and play sound)

* 0.3.0 Alpha / 2010.12.19 (Yannick LE NY <yleny@nospam@laposte.net>):
- Arduino IDE updated to version 0021
- FreeRTOS updated to version 6.1.0
- add mprintf library - a thread safe printf called mprintf
  (Developped by Paula Keezer http://www.out--there.com/blog/mprintf-a-thread-safe-printf-mprintf-library/ )
- add cserial library - two c functions are required so that stdout can be initialized for the stdio library - This binds the printf function to the hardware serial port
  (Developped by Paula Keezer http://www.out--there.com/blog/mprintf-thread-safe-freertos-printf-part/ )  
- add CPPLib library - add the new() and delete() operators, (with very common and well known iplementations) and the function that allows to have virtual pure destructors.
  (Developped by Julián U. da Silva Gillig. - http://robotgroup.com.ar )
- Because Serial Outpout doesn't work with DuinOS and AtMega 88, 88P, 168 and 168P, decrease TOTAL_HEAP_SIZE from 800 to 500
  Reported by Chumbud
  Test Code : http://www.arduino.cc/cgi-bin/yabb2/YaBB.pl?num=1256745982/39#39
  Workaround : http://www.arduino.cc/cgi-bin/yabb2/YaBB.pl?num=1256745982/46#46
- Add patched Servo lib (from Arduino IDE 0021) with Timer1 disabled because DuinOS uses the timer 1 for its kernel.
  Now should works only with AtMega 128, 1280, 1281, 2560, 2561, 32U4, AT90USB646, AT90USB1286
  Need testing
- add ServoTimer2 lib to replace Servo for AtMega 88,168,328,644 - use the 8 bits Timer2 to manage up to 8 servos
  ServoTimer2 lib website : http://code.google.com/p/tricopter/source/browse/trunk/arduino/#arduino%2Flibraries%2FServoTimer2
  Need testing
 
 
