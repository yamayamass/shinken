#define SWITCH 2
#define OFF 0
#define ON 1


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(SWITCH), condition, RISING);
  while(digitalRead(SWITCH)==0);
}

volatile int toggle = OFF;
void(* resetFunc) (void) = 0;

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("loop中です");
}

void condition() {
  if (toggle == ON) {
    Serial.print("リセットされます");
    resetFunc();
    delay(1000);
  } else if (toggle == OFF) {
    toggle = ON;
    delay(1000);
  }
}
