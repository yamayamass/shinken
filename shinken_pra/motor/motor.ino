/**
   Hardware Connections:
    Arduino | drv8835
    -------------------
      5V    |   VCC
      GND   |   MODE
      5     |   AIN1
      6     |   AIN2
      7     |   BIN1
      8     |   BIN2
      motor |   AOUT1
      motor |   AOUT2
      motor |   BOUT1
      motor |   BOUT2
      GND   |   GND
*/

#define SWITCH 4
#define OFF 0
#define ON 1
#define MOTER1_1 5
#define MOTER1_2 6
#define MOTER2_1 7
#define MOTER2_2 8

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //attachInterrupt(digitalPinToInterrupt(SWITCH), condition, RISING);
  while(digitalRead(SWITCH)==0);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Forward \n");
  DCM1_FORWARD();
  DCM2_FORWARD();
}

void DCM1_COAST() {
	digitalWrite(MOTER1_1, LOW);
	digitalWrite(MOTER1_2, LOW);
}

void DCM1_FORWARD() {
	digitalWrite(MOTER1_1, HIGH);
	digitalWrite(MOTER1_2, LOW);
}

void DCM1_REVERSE() {
	digitalWrite(MOTER1_1, LOW);
	digitalWrite(MOTER1_2, HIGH);
}

void DCM1_BRAKE() {
	digitalWrite(MOTER1_1, HIGH);
	digitalWrite(MOTER1_2, HIGH);
}

void DCM2_COAST() {
	digitalWrite(MOTER2_1, LOW);
	digitalWrite(MOTER2_2, LOW);
}

void DCM2_FORWARD() {
	digitalWrite(MOTER2_1, HIGH);
	digitalWrite(MOTER2_2, LOW);
}

void DCM2_REVERSE() {
	digitalWrite(MOTER2_1, LOW);
	digitalWrite(MOTER2_2, HIGH);
}

void DCM2_BRAKE() {
	digitalWrite(MOTER2_1, HIGH);
	digitalWrite(MOTER2_2, HIGH);
}