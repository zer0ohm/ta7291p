/*
 * Motor driver TA7291P Control Library
 *
 * Copyright (C) 2019 zer0ohm <16779650+zer0ohm@users.noreply.github.com>
 *
 * This file is part of libta7291p, and released under the MIT License.
 * More detail of license is see "LICENSE.md".
 */

#include <Arduino.h>
#include <stdint.h>
#include <stdlib.h>

#include "TA7291P.h"

TA7291P::TA7291P (void) {
}

void TA7291P::begin (void) { // 開始時に実行される関数
    stop(13, 13, 0); // ダミー用
}

/*
 * changeInputMode関数　(ライブラリ内で主に使う関数なので明示的に使うことはほぼないかも？)
 * 目的: TA7291Pの機能切り替え時にストップを100μs入れる
 * 引数: TA7291PにつなぐArduinoのピンとanalogWriteの値(変数型は全てuint8_t型)
 * 返り値: なし(void型)
 *
 * 使い方: TA7291P_Sample.inoを参照
 */
void TA7291P::changeInputMode (uint8_t IN1_pin, uint8_t IN2_pin, uint8_t VREF_pin) {
    digitalWrite(IN1_pin, LOW);
    digitalWrite(IN2_pin, LOW);
    analogWrite(VREF_pin, MOT_STOP);

    delayMicroseconds(100); /* TA7291Pデータシート 10頁より引用:
                             * 「入力を切り替えたときに貫通電流が流れます。
                             * 入力切り替え時(正転⇔逆転、正転/逆転⇔ブレーキ)に
                             * STOPモード(約100µs)を入れてください。」
                             */
}

/*
 * CW(ClockWise)関数
 * 目的: 正転
 * 引数: TA7291PにつなぐArduinoのピンとanalogWriteの値(変数型は全てuint8_t型)
 * 返り値: なし(void型)
 *
 * 使い方: TA7291P_Sample.inoを参照
 */
void TA7291P::cw (uint8_t IN1_pin, uint8_t IN2_pin, uint8_t VREF_pin, uint8_t analogWriteVal) {
    changeInputMode(IN1_pin, IN2_pin, VREF_pin);

    digitalWrite(IN1_pin, HIGH);
    digitalWrite(IN2_pin, LOW);
    analogWrite(VREF_pin, analogWriteVal);
}

/*
 * CCW(Counter ClockWise)関数
 * 目的: 反転
 * 引数: TA7291PにつなぐArduinoのピンとanalogWriteの値(変数型は全てuint8_t型)
 * 返り値: なし(void型)
 *
 * 使い方: TA7291P_Sample.inoを参照
 */
void TA7291P::ccw(uint8_t IN1_pin, uint8_t IN2_pin, uint8_t VREF_pin, uint8_t analogWriteVal) {
    changeInputMode(IN1_pin, IN2_pin, VREF_pin);

    digitalWrite(IN1_pin, LOW);
    digitalWrite(IN2_pin, HIGH);
    analogWrite(VREF_pin, analogWriteVal);
}

/*
 * brake関数
 * 目的: ショートブレーキ
 * 引数: TA7291PにつなぐArduinoのピンとanalogWriteの値(変数型は全てuint8_t型)
 * 返り値: なし(void型)
 *
 * 使い方: TA7291P_Sample.inoを参照
 */
void TA7291P::brake (uint8_t IN1_pin, uint8_t IN2_pin, uint8_t VREF_pin, uint8_t analogWriteVal) {
    changeInputMode(IN1_pin, IN2_pin, VREF_pin);

    digitalWrite(IN1_pin, HIGH);
    digitalWrite(IN2_pin, HIGH);
    analogWrite(VREF_pin, analogWriteVal);
}

/*
 * stop関数
 * 目的: 停止
 * 引数: TA7291PにつなぐArduinoのピン(変数型は全てuint8_t型)
 * 返り値: なし(void型)
 *
 * 使い方: TA7291P_Sample.inoを参照
 */
void TA7291P::stop (uint8_t IN1_pin, uint8_t IN2_pin, uint8_t VREF_pin) {
    digitalWrite(IN1_pin, LOW);
    digitalWrite(IN2_pin, LOW);
    analogWrite(VREF_pin, MOT_STOP);
}
