/**
   Hardware Connections:
    Arduino | RPR-220
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

void setup() {
  // put your setup code here, to run once:
  // put your setup code here, to run once:
  Serial.begin(9600);

  //割り込み関数の例(今回は使用していない)
  //attachInterrupt(digitalPinToInterrupt(SWITCH), condition, RISING);

  //スイッチが押されるまで待機
  while(digitalRead(SWITCH)==0);
}

void loop() {
  // put your main code here, to run repeatedly:

}
