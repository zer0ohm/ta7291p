/*
 * Motor driver TA7291P Control Library Header
 *
 * Copyright (C) 2019 zer0ohm <16779650+zer0ohm@users.noreply.github.com>
 *
 * This file is part of libta7291p, and released under the MIT License.
 * More detail of license is see "LICENSE.md".
 */

#ifndef __TA7291P_H__
#define __TA7291P_H__

#include <Arduino.h>
#include <stdint.h>
#include <stdlib.h>

class TA7291P {
public:
    TA7291P(void);

public:
    /* メンバ関数のプロトタイプ宣言 */
    void begin(void);
    void changeInputMode(uint8_t IN1_pin, uint8_t IN2_pin, uint8_t VREF_pin);

    void cw (uint8_t IN1_pin, uint8_t IN2_pin, uint8_t VREF_pin, uint8_t analogWriteVal);
    void ccw(uint8_t IN1_pin, uint8_t IN2_pin, uint8_t VREF_pin, uint8_t analogWriteVal);
    void brake(uint8_t IN1_pin, uint8_t IN2_pin, uint8_t VREF_pin, uint8_t analogWriteVal);
    void stop(uint8_t IN1_pin, uint8_t IN2_pin, uint8_t VREF_pin);

private:
    /* 定数 */
    const uint8_t MOT_STOP = 0;
};

#endif
