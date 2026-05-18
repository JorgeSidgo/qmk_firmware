#include QMK_KEYBOARD_H

// CUSTOM KEYCODES - for Macros
enum custom_keycodes {
    ZEN_MODE = SAFE_RANGE,
    SPLIT_DOWN
};

// MACRO BEHAVIOR
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case ZEN_MODE:
            SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_K) SS_UP(X_LCTL) SS_TAP(X_Z));
            return false; break;

            case SPLIT_DOWN:
            SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_K) SS_TAP(X_BACKSLASH) SS_UP(X_LCTL));
            return false; break;
        }
    }
    return true;
}