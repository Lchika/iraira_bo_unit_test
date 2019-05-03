/**
 * @file iraira_unit_test_m.ino
 * @brief イライラ棒モジュール単体テスト用プログラム(マスター側)
 * @date 2019.05.03
 * @details 以下の機能について動作確認する
 * - DIPスイッチ読み取り
 * - I2C通信(マスタ側)
 * - フォトインタラプタ読み取り
 */

#include <Wire.h>
#include <Arduino.h>

#define PIN_10DIP_1               6         //  DIPロータリースイッチ入力1
#define PIN_10DIP_2               7         //  DIPロータリースイッチ入力2
#define PIN_10DIP_4               8         //  DIPロータリースイッチ入力4
#define PIN_10DIP_8               9         //  DIPロータリースイッチ入力8
#define PIN_PHOTO_INT             5         //  フォトインタラプタ入力

/**
 * @brief セットアップ処理
 * @param None
 * @return None
 * @details arduino起動時のセットアップ処理を行う
 */
void setup(){
  Serial.begin(9600);
  Serial.println("iraira_unit_test_m.ino start");
  pinMode(PIN_10DIP_1, INPUT);
  pinMode(PIN_10DIP_2, INPUT);
  pinMode(PIN_10DIP_4, INPUT);
  pinMode(PIN_10DIP_8, INPUT);
  pinMode(PIN_PHOTO_INT, INPUT);
  Wire.begin();
  return;
}

/**
 * @brief メインループ処理
 * @param None
 * @return None
 * @details
 */
void loop(){
  static int count = 0;
  Serial.println("$ count = " + String(count++));
  
  int dip = get_slave_address();
  Serial.println("# dip_value = " + String(dip));
  
  String photo_state = digitalRead(PIN_PHOTO_INT) == HIGH ? "HIGH" : "LOW";
  Serial.println("# photo_state = " + photo_state);
  
  Wire.requestFrom(8, 1); // request 1 bytes from Slave ID #8
  while (Wire.available()) {
    byte b = Wire.read();
    Serial.print("# Wire.read = ");
    Serial.println(b);
  }
  delay(1000);
  return;
}

/**
 * @brief I2Cスレーブアドレス取得処理
 * @param　None
 * @return int スレーブアドレス値
 */
int get_slave_address(void){
  int adress = digitalRead(PIN_10DIP_1) | (digitalRead(PIN_10DIP_2) << 1) |
              (digitalRead(PIN_10DIP_4) << 2) | (digitalRead(PIN_10DIP_8) << 3);
  return adress;
}