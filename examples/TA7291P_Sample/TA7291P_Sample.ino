/*
 * Motor driver TA7291P Control Library Sample sketch
 *
 * Copyright (C) 2019 zer0ohm <16779650+zer0ohm@users.noreply.github.com>
 *
 * This file is part of libta7291p, and released under the MIT License.
 * More detail of license is see "LICENSE.md".
 */

#include <TA7291P.h>

// 左側モータ用
const uint8_t IN1_1 = 4;  // IN1制御ピン その1
const uint8_t IN2_1 = 5;  // IN2制御ピン その1
const uint8_t VREF_1 = 6; // VREF制御ピン その1

// 右側モータ用
const uint8_t IN1_2 = 7;  // IN1制御ピン その2
const uint8_t IN2_2 = 8;  // IN2制御ピン その2
const uint8_t VREF_2 = 9; // VREF制御ピン その2

TA7291P motordriver;

void setup () {
    pinMode(IN1_1, OUTPUT);
    pinMode(IN2_1, OUTPUT);
    pinMode(VREF_1, OUTPUT);

    pinMode(IN1_2, OUTPUT);
    pinMode(IN2_2, OUTPUT);
    pinMode(VREF_2, OUTPUT);

    Serial.begin(9600); // シリアルポートを9600bpsで開く
}

void loop () {
    /* 5秒間左折 */
    motordriver.cw(IN1_1, IN2_1, VREF_1, 128);
    motordriver.ccw(IN1_2, IN2_2, VREF_2, 128);

    delay(5000);

    /* 5秒間右折 */
    motordriver.ccw(IN1_1, IN2_1, VREF_1, 128);
    motordriver.cw(IN1_2, IN2_2, VREF_2, 128);

    delay(5000);

    /* 5秒間直進 */
    motordriver.cw(IN1_1, IN2_1, VREF_1, 128);
    motordriver.cw(IN1_2, IN2_2, VREF_2, 128);

    delay(5000);

    /* 5秒間バック */
    motordriver.ccw(IN1_1, IN2_1, VREF_1, 128);
    motordriver.ccw(IN1_2, IN2_2, VREF_2, 128);

    delay(5000);

    /* 5秒間ブレーキ */
    motordriver.brake(IN1_1, IN2_1, VREF_1, 64);
    motordriver.brake(IN1_2, IN2_2, VREF_2, 64);

    delay(5000);

    /* 5秒間停止 */
    motordriver.stop(IN1_1, IN2_1, VREF_1);
    motordriver.stop(IN1_2, IN2_2, VREF_2);

    delay(5000);
}
