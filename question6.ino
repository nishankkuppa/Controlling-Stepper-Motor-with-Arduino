/*
   MotorKnob

   A stepper motor follows the turns of a potentiometer
   (or other sensor) on analog input 0.

   http://www.arduino.cc/en/Reference/Stepper
   This example code is in the public domain.
*/

#include <Stepper.h>

// change this to the number of steps on your motor
#define STEPS 200

// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to
Stepper stepper(STEPS, 8, 9, 10, 11);

// the previous reading from the analog input
int previous = 0;

void setup() {
  // set the speed of the motor to 30 RPMs
  stepper.setSpeed(5);
}

void loop()
{
  steps_wave();
}

void steps_wave()
{
  int cw[4] = {10,9,11,8}; //3241
  for (int i = 0 ; i < 4 ; i++)
  {
    digitalWrite(cw[i], HIGH);
    delayMicroseconds(6000);
    digitalWrite(cw[i], LOW);
  }
}

