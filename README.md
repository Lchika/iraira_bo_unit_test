# iraira_bo_unit_test

- 全モジュール共通機能である以下の機能の動作確認ができる
  - DIPスイッチ値読み取り
  - I2C通信
  - フォトインタラプタ値読み取り

## 使い方

- 以下の図のような構成を用意して動作確認する
<img src="https://github.com/Lchika/iraira_bo_unit_test/blob/master/pic/iraira_unit_test_pic_1.png" width="600px">

- 共通シールドを使用する場合については、より詳細な使い方を記載予定

## ログの見方
- `iraira_unit_test_m.ino`を書き込んだArduinoから以下のようなログが出力される
<img src="https://github.com/Lchika/iraira_bo_unit_test/blob/master/pic/result.PNG" width="400px">
  - `count`はloop()が呼ばれた回数
  - `dip_value`はDIPスイッチの値
  - `photo_state`はフォトインタラプタの値
  - `Wire.read`はI2C通信でスレーブ側から受け取った値
    - 値が１ずつ増えていればOK
- ログ出力中にDIPスイッチの値を切り替えたり、フォトインタラプタに指をかざしてみたりして、値が正常に変化するか確認する