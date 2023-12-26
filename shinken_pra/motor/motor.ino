#define SWITCH 2
#define OFF 0
#define ON 1
#define PIN_DC_MOTER1 5
#define PIN_DC_MOTER2 6

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //attachInterrupt(digitalPinToInterrupt(SWITCH), condition, RISING);
  while(digitalRead(SWITCH)==0);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Forward \n");
  DCM_FORWARD();
}

void DCM_COAST() {
	digitalWrite(PIN_DC_MOTER1, LOW);
	digitalWrite(PIN_DC_MOTER2, LOW);
}

void DCM_FORWARD() {
	digitalWrite(PIN_DC_MOTER1, HIGH);
	digitalWrite(PIN_DC_MOTER2, LOW);
}

void DCM_REVERSE() {
	digitalWrite(PIN_DC_MOTER1, LOW);
	digitalWrite(PIN_DC_MOTER2, HIGH);
}

void DCM_BRAKE() {
	digitalWrite(PIN_DC_MOTER1, HIGH);
	digitalWrite(PIN_DC_MOTER2, HIGH);
}