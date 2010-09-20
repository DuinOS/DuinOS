/*
 DuinOS MoreComplexBlinking
 
 Blinks two LEDs. One LED shows two combined waves.
 
 The circuit: ##Pins:
 * LED connected from digital pin 14 to Vcc.
 * LED connected from digital pin 15 to Vcc.

 ##Pins:
 * Note: On most Comm.ProgUSB boards, there are already two LEDs on the board
 connected to pins 14 and 15, so you don't need any extra components for this example.
 
 Created 2009.10.26 (yyyy.mm.dd)
 by Julián da Silva Gillig
 
 http://multiplo.org
 http://robotgroup.com.ar
 
 Based on the original Blink code by David Cuartielles
 
 */

#define INITIAL_GREEN_DELAY  200
#define NEW_GREEN_DELAY  20

int ledPinRed =  8;
int ledPinGreen =  9;

unsigned int greenDelay = INITIAL_GREEN_DELAY;
boolean redLED_isOn = false;
boolean greenLED_isOn = false;

//Forward declaration, to let redLED call to resumeTask(greenLED). It's not necessary if we put the greenLED 
//itself here, but declareLoopTask may be usefull in more complex situations:
declareTaskLoop(greenLED);

taskLoop(redLED)
{
  static unsigned char counter = 0;
  
  if (!greenLED_isOn)
  {
     if (counter >2)
       resumeTask(greenLED);
     counter++;
  }
  
  redLED_isOn = false;
  delay(1000);
  redLED_isOn = true; 
  delay(1000);
}


taskLoop(greenLED)
{
  static unsigned char counter = 1;

  digitalWrite(ledPinGreen, HIGH);  // set the LED on
  delay(greenDelay);
  digitalWrite(ledPinGreen, LOW);  // set the LED off
  delay(greenDelay);

  if ( (counter >= 9) && (greenDelay != NEW_GREEN_DELAY) )
    greenDelay = NEW_GREEN_DELAY; //now, after 10 blinks, accelerates
  if (counter >= 99)
  {
    //Reset vars, so next time, if the task is resumed, it executes all again:
    counter = 0;
    greenDelay = INITIAL_GREEN_DELAY;
    greenLED_isOn = false;
    suspend();      //After a while, the tasks suspends itself (forever)
  }
  counter++;
}


// The setup() method runs once, when the sketch starts

void setup()   
{                
  // Initialize the digital pins as outputs:
  pinMode(ledPinRed, OUTPUT);
  pinMode(ledPinGreen, OUTPUT);
  
  createTaskLoop(redLED, NORMAL_PRIORITY);
  createTaskLoop(greenLED, LOW_PRIORITY);

  //This initializes the main loop's with a different priority (default is LOW_PRIORITY):
  //initMainLoopPriority(NORMAL_PRIORITY);

  //Try this and see what happends:
  //suspendTask(redLED);
}


// This is the main loop() method, wich runs over and over again,
// as long as the Arduino has power. Is a LOW_PRIORITY taskLoop:

void loop()                     
{
  if (redLED_isOn)
  {
    digitalWrite(ledPinRed, LOW);  // set the LED off
    delay(25);                      // The OS can be tested reducing these delays, and seeing how both LEDs work together...
    digitalWrite(ledPinRed, HIGH);   // set the LED on
    delay(25);    
  }
  else
  {
    digitalWrite(ledPinRed, LOW);  //  LED is off
    //If nextTask is not called, the application will not hang, because the OS is preemptive. BUT, the current task
    //will consume a lot of computational resources (due to it's lack of a delay() in this branch), the application will 
    //turn slower, and the other tasks may be affected by this, loossing precision in their timing:
    nextTask();
  }
}

