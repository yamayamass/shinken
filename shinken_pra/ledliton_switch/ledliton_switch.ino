//このプログラムはタイミングにより誤動作をよく起こします
#define LED 12
#define SWITCH 2
#define OFF 0
#define ON 1

void setup() {
  // put your setup code here, to run once:
  pinMode(LED,OUTPUT);
  pinMode(SWITCH,INPUT_PULLUP);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(SWITCH), condition_change, RISING);
  //while(digitalRead(SWITCH)==0);
}

//void(* resetFunc) (void) = 0;

volatile int toggle = OFF;
volatile int interrupted = 0;

void loop() {
  //while(digitalRead(SWITCH)==1); //押している間は光らない
  // put your main code here, to run repeatedly:
  interrupted = 0;
  //ボタンを押されたらトグルを有効にする
  if ((digitalRead(SWITCH) == HIGH && toggle == OFF) || toggle == ON) {
    toggle = ON;
    //ボタンが押され続けている場合の処理
    while (digitalRead(SWITCH) == HIGH) {
      led_flash();
      Serial.print("1 \n");
    }
    //トグル有効中の通常ループ
    led_flash();
    Serial.print("2ON \n");
  }

  //トグル動作中にボタンONでフラグを消す
  if (digitalRead(SWITCH) == HIGH && toggle == ON) {
    toggle = OFF;
    Serial.print("3OFF \n");

    //ボタンが押され続けている場合の処理
    while (digitalRead(SWITCH) == HIGH) {
      led_flash();
      Serial.print("4OFF \n");
    }
  }
}

void led_flash() {
  digitalWrite(LED,HIGH);
  delay(500);
  digitalWrite(LED,LOW);
  delay(500);
}

void condition_change() {
  if (toggle == ON) {
    toggle = OFF;
    Serial.print("TOFF \n");
    interrupted = 1;
    delay(1000);
  } else if (toggle == OFF) {
    toggle = ON;
    Serial.print("TON \n");
    interrupted = 1;
    delay(1000);
  }
  //resetFunc();
  //loop();
}

/*
void condition_change() {
  toggle = !toggle;
  interrupted = 1;
  delay(1000);
}
*/