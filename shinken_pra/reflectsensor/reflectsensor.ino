/**

  https://deviceplus.jp/arduino/entry015/
  センサーの足の1~4の番号の割り振りはこれに従う
   Hardware Connections:
    Arduino | RPR-220_1
    -------------------
      5V,A1 |   1
      GND   |   2
      GND   |   3
      5V    |   4

    Arduino | RPR-220_2
    -------------------
      5V,A2 |   1
      GND   |   2
      GND   |   3
      5V    |   4
*/

#define SWITCH 4
#define OFF 0
#define ON 1
#define R_sen1 1
#define R_sen2 2

//センサーの抵抗値を読み取って保存する変数
int val_1;
int val_2;

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
  val_1 = analogRead(R_sen1);
  val_2 = analogRead(R_sen2);
  Serial.println(val_1);
  Serial.println(val_2);
  delay(1000);
}
