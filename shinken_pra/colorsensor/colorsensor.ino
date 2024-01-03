/**
  https://spiceman.jp/arduino-s11059-program/#index_id3
  参照
   Hardware Connections:
    Arduino | module  | sensor
    -------------------
      3.3V  |   VREF1 |  +V
      5V    |   VREF2 |
            |   SCL1  |  SCL
      SCL   |   SCL2  |
            |   SDA1  |  SDA
      SDA   |   SDA2  |
            |   VPU   |
      GND   |   GND   |  GND
*/

#define SWITCH 4
#define OFF 0
#define ON 1
#include <Wire.h>
//アドレス指定
#define S11059_ADDR 0x2A
#define CONTROL_MSB 0x00
#define CONTROL_1_LSB 0x84
#define CONTROL_2_LSB 0x04
#define SENSOR_REGISTER 0x03

void setup()
{
  Serial.begin(9600);//シリアル通信を9600bpsで初期化
  while(digitalRead(SWITCH)==0);
  Wire.begin();//I2Cを初期化

  Wire.beginTransmission(S11059_ADDR);//I2Cスレーブ「Arduino Uno」のデータ送信開始
  Wire.write(CONTROL_MSB);//コントロールバイトを指定
  Wire.write(CONTROL_1_LSB);//ADCリセット、スリープ解除
  Wire.endTransmission();//I2Cスレーブ「Arduino Uno」のデータ送信終了
  
  Wire.beginTransmission(S11059_ADDR);//I2Cスレーブ「Arduino Uno」のデータ送信開始
  Wire.write(CONTROL_MSB);//コントロールバイトを指定
  Wire.write(CONTROL_2_LSB);//ADCリセット解除、バスリリース
  Wire.endTransmission();//I2Cスレーブ「Arduino Uno」のデータ送信終了
}

void getvalue_from_colorsensor() {
  //変数宣言
  int high_byte, low_byte, red, green, blue, IR;

  delay(2500);//2500msec待機(2.5秒待機)

  Wire.beginTransmission(S11059_ADDR);//I2Cスレーブ「Arduino Uno」のデータ送信開始
  Wire.write(SENSOR_REGISTER);//出力データバイトを指定
  Wire.endTransmission();//I2Cスレーブ「Arduino Uno」のデータ送信終了

  Wire.requestFrom(S11059_ADDR, 8);//I2Cデバイス「S11059_ADDR」に8Byteのデータ要求
  if(Wire.available()){
    high_byte = Wire.read();//high_byteに「赤(上位バイト)」のデータ読み込み
    low_byte = Wire.read();//high_byteに「赤(下位バイト)」のデータ読み込み
    red = high_byte << 8|low_byte;//1Byte目のデータを8bit左にシフト、OR演算子で2Byte目のデータを結合して、redに代入

    high_byte = Wire.read();//high_byteに「緑(上位バイト)」のデータ読み込み
    low_byte = Wire.read();//high_byteに「緑(下位バイト)」のデータ読み込み
    green = high_byte << 8|low_byte;//1Byte目のデータを8bit左にシフト、OR演算子で2Byte目のデータを結合して、greenに代入

    high_byte = Wire.read();//high_byteに「青(上位バイト)」のデータ読み込み
    low_byte = Wire.read();//high_byteに「青(下位バイト)」のデータ読み込み
    blue = high_byte << 8|low_byte;//1Byte目のデータを8bit左にシフト、OR演算子で2Byte目のデータを結合して、blueに代入

    high_byte = Wire.read();//high_byteに「赤外(上位バイト)」のデータ読み込み
    low_byte = Wire.read();//high_byteに「赤外(下位バイト)」のデータ読み込み
    IR = high_byte << 8|low_byte;//1Byte目のデータを8bit左にシフト、OR演算子で2Byte目のデータを結合して、IRに代入
  }
  Wire.endTransmission();//I2Cスレーブ「Arduino Uno」のデータ送信終了

  Serial.print(blue);//「blue」をシリアルモニタに送信
  Serial.print(",");//文字列「,」をシリアルモニタに送信
  Serial.print(red);//「red」をシリアルモニタに送信
  Serial.print(",");//文字列「,」をシリアルモニタに送信
  Serial.print(green);//「green」をシリアルモニタに送信
  Serial.print(",");//文字列「,」をシリアルモニタに送信
  Serial.print(IR);//「IR」をシリアルモニタに送信
  Serial.println("");//改行
}

void loop() {
  getvalue_from_colorsensor();
  delay(1000);
}