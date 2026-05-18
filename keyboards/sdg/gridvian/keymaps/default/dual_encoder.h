#include QMK_KEYBOARD_H

// ENCODER BEHAVIOR
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // UPPER ENCODER
        if (clockwise) {
            tap_code16(LALT(KC_RIGHT));
        } else {
            tap_code16(LALT(KC_LEFT));
        }
    } else {
        // LOWER ENCODER
        if (clockwise) {
            tap_code16(LCTL(KC_PGDN));
        } else {
            tap_code16(LCTL(KC_PGUP));
        }
    }

    return false;
}