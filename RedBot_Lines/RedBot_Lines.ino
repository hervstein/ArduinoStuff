/***********************************************************************
 * Exp6_LineFollowing_IRSensors -- RedBot Experiment 6
 *
 * This code reads the three line following sensors on A3, A6, and A7
 * and prints them out to the Serial Monitor. Upload this example to your
 * RedBot and open up the Serial Monitor by clicking the magnifying glass
 * in the upper-right hand corner.
 *
 * This sketch was written by SparkFun Electronics,with lots of help from
 * the Arduino community. This code is completely free for any use.
 *
 * 8 Oct 2013 M. Hord
 * Revised, 31 Oct 2014 B. Huang
 ***********************************************************************/

#include <RedBot.h>
RedBotSensor IRSensor1 = RedBotSensor(A3); // initialize a sensor object on A3
RedBotSensor IRSensor2 = RedBotSensor(A6); // initialize a sensor object on A6
RedBotSensor IRSensor3 = RedBotSensor(A7); // initialize a sensor object on A7
RedBotMotor motors;
boolean s1=true;
boolean s2=true;
boolean s3=true;

void setup()
{
  Serial.begin(9600);
  Serial.println("Welcome to experiment 6!");
  Serial.println("------------------------");
}

void loop()
{
  while (s1 | s2 | s3) {
    motors.drive(100);
    boolean s1 = IRSensor1.read() < 1000;
    boolean s2 = IRSensor1.read() < 1000;
    boolean s3 = IRSensor1.read() < 1000;
  }
  motors.brake();
  motors.pivot(255);
  delay(100);
}
