#define LED 12
void setup() {
  // put your setup code here, to run once:
  pinMode(LED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED,HIGH);
  delay(1000);
  //Serial.print("Hello");
  digitalWrite(LED,LOW);
  delay(1000);
}
