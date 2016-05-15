/*
 _Wink

 This example code is in the public domain.

 Originally Mega analogWrite() test

 This sketch fades LEDs up and down one at a time on digital pins 2 through 13.
 This sketch was written for the Arduino Mega, and will not work on previous boards.

 The circuit and sketch were written by Tom Igoe for the Arduino Mega, but I changed it 
 to an Arduino Uno as a single Laser.

 created 8 Feb 2009
 by Tom Igoe
 modified 15 Aug 2015
 by Jim Grina
*/

int laserPin = 11;// a pmw pin connected to the S pin
                   // the 3 pin Laser board has - connected to Arduino ground
                   // and 5V power to the "middle" pin

// the setup function runs once when you press reset or power the board
void setup() 
{
 // initialize digital pin 11 as an output.
 pinMode(laserPin, OUTPUT);
}

// the loop function runs over and over again forever
void loop() 
{ 

  for (int brightness = 0; brightness < 255; brightness++) 
  {
    analogWrite(laserPin, brightness);
    delay(2);
  }
  for (int brightness = 255; brightness >= 0; brightness--) {
     analogWrite(laserPin, brightness);
     delay(2);
   }
   // pause off between cycles of Laser:
   delay(200);
}
