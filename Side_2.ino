#define StepPerRev 100 // set steps per revolution value

#include "Stepper.h" // include stepper motor library

Stepper SM(StepPerRev, 8, 9, 10, 11); // define your stepper name(Step pet Revolution , 4 pins connected to Encoder)

int Sensor,Speed; //declre variables

void setup() 
{
	Serial.begin(9600);  
}

void loop() 
{  
  Sensor = analogRead(A0); // read value of potentiometer
  Speed = map(Sensor,0,1023,1,100); // scale value of potentiometer to value of steps per revolution
  Serial.println (Speed); // print the scaled value of potentiometer
  SM.setSpeed(100); 
  SM.step(StepPerRev / Speed); // if step = step per revolution then speed is maximum
  // at step = 1 the speed is minimum
}