********************************
 DuinOS v0.2 Alpha
********************************

Copyright (C) 2009 Multiplo
http://multiplo.org
http://robotgroup.com.ar
Created by Julián U. da Silva Gillig.

Based on the FreeRTOS v6.0.5 kernel (www.freertos.org). Please see the License section below.
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

2010.06.30 (Michael Grigorev aka CHERTS <sleuthhound@gmail.com>):
	- Arduino updated to version 0018
	- FreeRTOS updated to version 6.0.5
	- Add new example MoreComplexBlinkingAndSound (Blinks two LEDs and play sound)

2009.11.02:
	- First version released (DuinOS v0.1 Alpha).
