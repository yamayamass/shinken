#define CdS_PIN A0
#define LED 12
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(CdS_PIN, INPUT_PULLUP);
  pinMode(LED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED,HIGH);
  int CdS_val = analogRead(CdS_PIN);
  Serial.println(CdS_val);
  delay(100);
}
