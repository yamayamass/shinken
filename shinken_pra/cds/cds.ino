#define CdS_PIN A0
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(CdS_PIN, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int CdS_val = analogRead(CdS_PIN);
  Serial.println(CdS_val);
  delay(1000);
}
