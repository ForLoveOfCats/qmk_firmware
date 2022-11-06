#include QMK_KEYBOARD_H

#define XXXXXXX KC_NO

enum encoder_names {
  LEFT_HALF_ENC = 0,
  RIGHT_HALF_ENC1 = 2,
  RIGHT_HALF_ENC2,
};

#define NAV 1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ansi(
    KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,            KC_F7,   KC_F8,            KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_SLCK, KC_PAUS,
    KC_MPLY, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,             KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_DEL,  KC_BSPC, KC_INS,  KC_PGUP,
    KC_VOLU, KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,  KC_PGDN,
    KC_VOLD, KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_HOME, KC_END,
    XXXXXXX, KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,          KC_UP,
    MO(NAV), KC_LCTL, KC_LGUI, KC_LALT, XXXXXXX,   KC_SPC,  KC_SPC,                  XXXXXXX, MO(NAV), KC_RALT, KC_RGUI,                   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
  ),

  [NAV] = LAYOUT_ansi(
    _______,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX,
    _______, _______,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          _______,          _______,
    _______, _______, _______, _______, XXXXXXX, _______, _______,                   XXXXXXX, _______, XXXXXXX, XXXXXXX,                   _______, _______, _______, _______
  )
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == LEFT_HALF_ENC) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    } else if (index == RIGHT_HALF_ENC1) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == RIGHT_HALF_ENC2) {
        if (clockwise) {
            tap_code(KC_DOWN);
        } else {
            tap_code(KC_UP);
        }
    }
    return false;
}
