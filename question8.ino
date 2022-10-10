#include <Stepper.h>
#include <stdlib.h>

// change this to the number of steps on your motor
#define STEPS 200

// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to
Stepper stepper(STEPS, 8, 9, 10, 11);

// the previous reading from the analog input
int previous = 0;
int serialData = 0;

void setup()
{
  // set the speed of the motor to 30 RPMs
  stepper.setSpeed(5);
  Serial.begin(9600);
}

void loop()
{
  // look for when data is available for read from the serial monitor console
  if (Serial.available() > 0)
  {
    serialData = Serial.readString().toInt();  // read in the the serial data to a variable
    Serial.println(serialData);  // also print out serial data entered
  }
  steps_hitorque(serialData);
  delay(10);
}

void steps_hitorque(int x)
{
  // If the number is positive, move the motor clockwise
  if (x > 0)
  {
    delay(5);
    int cw[4] = {10, 9, 11, 8}; //3241
    for (int i = 0 ; i < 4 ; i++)
    {
      digitalWrite(cw[i], HIGH);
      delayMicroseconds(6000);
      digitalWrite(cw[i], LOW);
      digitalWrite(cw[i], HIGH);
      delayMicroseconds(6000);
      digitalWrite(cw[i], LOW);
    }
  }
  
  // If the number is negative, move the motor counterclockwise
  else
  {
    delay(5);
    int ccw[4] = {8, 11, 9, 10}; // 1423
    for (int i = 0 ; i < 4 ; i++)
    {
      digitalWrite(ccw[i], HIGH);
      delayMicroseconds(6000);
      digitalWrite(ccw[i], LOW);
      digitalWrite(ccw[i], HIGH);
      delayMicroseconds(6000);
      digitalWrite(ccw[i], LOW);
    }
  }
}

