// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "analog.h"

// ## JOYSTICK STATE
static bool up_held    = false;
static bool down_held  = false;
static bool left_held  = false;
static bool right_held = false;

// Joystick Config END

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┐
     * │ A │
     * └───┘
     */
    [0] = LAYOUT_ortho_1x1(
        KC_A
    )
};

void matrix_scan_user(void) {


    //------------------------
    //  X AXIS               -
    //------------------------
    int16_t x_pos = analogReadPin(JOYSTICK_X_PIN);

    if (!right_held && x_pos >= DOWN_THRESHOLD) {
        register_code(KC_RIGHT);
        right_held = true;
    } else if (right_held && x_pos < DOWN_THRESHOLD) {
        unregister_code(KC_RIGHT);
        right_held = false;
    }

    if (!left_held && x_pos <= UP_THRESHOLD) {
        register_code(KC_LEFT);
        left_held = true;
    } else if (left_held && x_pos > UP_THRESHOLD) {
        unregister_code(KC_LEFT);
        left_held = false;
    }

    //------------------------
    //  Y AXIS               -
    //------------------------
    int16_t y_pos = analogReadPin(JOYSTICK_Y_PIN);

    if (!down_held && y_pos >= DOWN_THRESHOLD) {
        register_code(KC_DOWN);
        down_held = true;
    } else if (down_held && y_pos < DOWN_THRESHOLD) {
        unregister_code(KC_DOWN);
        down_held = false;
    }

    if (!up_held && y_pos <=UP_THRESHOLD) {
        register_code(KC_UP);
        up_held = true;
    } else if (up_held && y_pos > UP_THRESHOLD) {
        unregister_code(KC_UP);
        up_held = false;
    }
}