/**
 * @file iraira_unit_test_s.ino
 * @brief イライラ棒モジュール単体テスト用プログラム(スレーブ側)
 * @date 2019.05.03
 * @details 以下の機能について動作確認する
 * - I2C通信(スレーブ側)
 */

#include <Wire.h>
#include <Arduino.h>

/**
 * @brief セットアップ処理
 * @param None
 * @return None
 * @details arduino起動時のセットアップ処理を行う
 */
void setup(){
  Serial.begin(9600);
  Serial.println("iraira_unit_test_s.ino start");
  Wire.begin(8);// Slave ID #8
  Wire.onRequest(requestEvent);
  return;
}

/**
 * @brief メインループ処理
 * @param None
 * @return None
 * @details
 */
void loop(){
  return;
}

/**
 * @brief I2Cイベント要求対応処理
 * @param None
 * @return None
 * @details
 */
void requestEvent() {
  static byte b = 0;
  Wire.write(b++);
}