#include <Stepper.h>

// There are 400 steps when half-stepping
const int stepsPerRevolution = 400;

// Make 5 revolutions
const int numberOfRevolutions = 5;

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

void setup()
{
  // set the speed at 60 rpm:
  myStepper.setSpeed(60);
  // initialize the serial port:
  Serial.begin(9600);
}

void loop()
{
  // step one revolution  in clockwise direction:
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution * numberOfRevolutions);
  delay(500);
}
