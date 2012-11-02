/*
 DuinOS MoreComplexBlinkingAndSound
 
 Blinks two LEDs and play sound.
 
 The circuit:
 * 1 LED connected from digital pin 14 (8)
 * 2 LED connected from digital pin 15 (9)
 * Speaker connected from digital pin 16 (10)

 Created 2010.06.30 (yyyy.mm.dd)
 by Michael Grigorev aka CHERTS
 
 */

int ledPinRed =  8;
int ledPinGreen =  9;
int SoundPin = 10;

unsigned int greenDelay = 200;
unsigned int redDelay = 400;

declareTaskLoop(redLED);
declareTaskLoop(greenLED);
declareTaskLoop(PlaySound);

taskLoop(redLED)
{
  digitalWrite(ledPinRed, HIGH);
  delay(redDelay);
  digitalWrite(ledPinRed, LOW);
  delay(redDelay);
}


taskLoop(greenLED)
{
  digitalWrite(ledPinGreen, HIGH);
  delay(greenDelay);
  digitalWrite(ledPinGreen, LOW);
  delay(greenDelay);
}

taskLoop(PlaySound)
{
  tone(SoundPin, 1245, 480);
  delay(480);
  tone(SoundPin, 932, 240);
  delay(240);
  tone(SoundPin, 1245, 960);
  delay(120);
  tone(SoundPin, 831, 240);
  delay(240);
  tone(SoundPin, 932, 480);
  delay(480);
  tone(SoundPin, 622, 720);
  delay(240);
  tone(SoundPin, 784, 120);
  delay(120);
  tone(SoundPin, 932, 120);
  delay(120);
  tone(SoundPin, 1245, 240);
  delay(240);
  tone(SoundPin, 932, 240);
  delay(240);
  tone(SoundPin, 1397, 240);
  delay(240);
  tone(SoundPin, 1245, 960);
  delay(120);
  tone(SoundPin, 1109, 360);
  delay(360);
  tone(SoundPin, 1047, 120);
  delay(120);
  tone(SoundPin, 932, 120);
  delay(120);
  tone(SoundPin, 831, 360);
  delay(360);
  tone(SoundPin, 932, 960);
  suspend();
}

// The setup() method runs once, when the sketch starts
void setup()   
{                
  // Initialize the digital pins as outputs:
  pinMode(ledPinRed, OUTPUT);
  pinMode(ledPinGreen, OUTPUT);
  
  createTaskLoop(redLED, NORMAL_PRIORITY);
  createTaskLoop(greenLED, NORMAL_PRIORITY);
  createTaskLoop(PlaySound, NORMAL_PRIORITY);

  //This initializes the main loop's with a different priority (default is LOW_PRIORITY):
  //initMainLoopPriority(NORMAL_PRIORITY);
}


// This is the main loop() method, wich runs over and over again,
// as long as the Arduino has power. Is a LOW_PRIORITY taskLoop:
void loop()                     
{
  // Stop the task of redLED in 10 seconds
  delay(10000);
  suspendTask(redLED);
  // Start the task of redLED in 10 seconds
  delay(10000);
  resumeTask(redLED);
}
