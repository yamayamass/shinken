int APHASE  = 4;
int AENBL   = 5;
int BPHASE  = 6;
int BENBL   = 7;
int VR_PIN  = A0;
unsigned long VR_VALUE = 0;

void setup() 
{
  pinMode(APHASE,OUTPUT);
  pinMode(AENBL,OUTPUT);
  pinMode(BPHASE,OUTPUT);
  pinMode(BENBL,OUTPUT);
  digitalWrite(AENBL,HIGH);
  digitalWrite(BENBL,HIGH);
}
void READ_VR(void)
{
  VR_VALUE = analogRead(VR_PIN);
}
void DELAY_WAIT(void)
{
  for (int i = 0; i < (VR_VALUE /10 + 7) ; i++) delayMicroseconds(100);
}
void loop() 
{
  READ_VR();
  digitalWrite(APHASE,HIGH);
  DELAY_WAIT();
  digitalWrite(BPHASE,HIGH);
  DELAY_WAIT();
  digitalWrite(APHASE,LOW);
  DELAY_WAIT();
  digitalWrite(BPHASE,LOW);
  DELAY_WAIT();
}
