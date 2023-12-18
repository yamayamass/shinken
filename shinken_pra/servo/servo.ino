#include <Servo.h>
#define SERVO_PIN 6
Servo mortor;

void setup() {
  // put your setup code here, to run once:
  mortor.attach(SERVO_PIN);
}

void loop() {
  // put your main code here, to run repeatedly:
  mortor.write(0);
  delay(1000);
  mortor.write(60);
  delay(1000);
}
