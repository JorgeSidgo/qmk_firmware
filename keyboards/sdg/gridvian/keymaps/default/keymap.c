// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "dual_encoder.h"
#include "joystick.h"
#include "macros.h"

// LAYERS
enum layer_names {
    _BASE,
    _FUNC
};

// GRID + ENCODERS KEYMAP
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*   
     * ┌───┬───┬───┬───┐
     * │ X │ X │ X │ O │
     * ├───┼───┼───┼───┘
     * │ X │ X │ X │
     * ├───┼───┼───┼───┐
     * │ X │ X │ X │ O │
     * └───┴───┴───┴───┘
     */
    [_BASE] = LAYOUT(
        ZEN_MODE,         LCTL(KC_G),   SPLIT_DOWN,      LCTL(KC_F5),
        LCTL(KC_P),       LCS(KC_O),    LCA(KC_RIGHT),
        LT(_FUNC, KC_F8), LCTL(KC_DOT), LCA(KC_LEFT),    LCTL(KC_W)
    ),

    [_FUNC] = LAYOUT(
        KC_NO, KC_NO, QK_BOOT, KC_NO,
        KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO,   KC_NO
    )
};
