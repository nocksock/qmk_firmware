#include <stdint.h>

#include QMK_KEYBOARD_H
#include "nocksock.h"
#include "oneshot.h"
#include "swapper.h"

// format macro: Vjjga*kr,^f5f,kkA		^

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
          KC_Q,   KC_W, KC_E, KC_R, KC_T,        KC_Y, KC_U, KC_I,    KC_O,   KC_P,
          KC_A,   KC_S, KC_D, KC_F, KC_G,        KC_H, KC_J, KC_K,    KC_L,   KC_SCLN,
          KC_LTZ, KC_X, KC_C, KC_V, KC_B,        KC_N, KC_M, KC_COMM, KC_DOT, KC_QUOT,
          LA_NAV , KC_SPC , RSFT_T(KC_ESC), LA_SYM
    ),

    [SYM] = LAYOUT(
        KC_ESC  , KC_LBRC , KC_LPRN , KC_LCBR , KC_TILD , KC_CIRC , KC_RCBR , KC_RPRN , KC_RBRC , KC_GRV  ,
        KC_MINS , KC_ASTR , KC_EQL  , KC_UNDS , KC_DLR  , KC_HASH , OS_SHFT , OS_CTRL , OS_ALT  , OS_CMD  ,
        KC_PLUS , KC_PIPE , KC_AT   , KC_SLSH , KC_PERC , XXXXXXX , KC_BSLS , KC_AMPR , KC_EXLM , KC_QUES ,
        _______ , _______ , _______ , _______
    ),

    [NAV] = LAYOUT(
        KC_TAB,  SW_WIN,  TAB_L,   TAB_R,   KC_VOLU,         QK_BOOT, HOME,    KC_CAPS, END,     KC_DEL,
        OS_CMD,  OS_ALT,  OS_CTRL, OS_SHFT, KC_VOLD,         KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BSPC,
        SPACE_L, SPACE_R, BACK,    FWD,     KC_MPLY,         CW_TOGG, KC_PGDN, KC_PGUP, SW_LANG, KC_ENT,
                                   _______, _______, _______, _______
    ),

    [NUM] = LAYOUT(
        KC_7,    KC_5,    KC_3,   KC_1,   KC_9,           KC_8,   KC_0,   KC_2,   KC_4,    KC_6,
        OS_SHFT, OS_CTRL, OS_ALT, OS_CMD, KC_F11,         KC_F12, OS_CMD, OS_ALT, OS_CTRL, OS_SHFT,
        KC_F7,   KC_F5,   KC_F3,  KC_F1,  KC_F9,          KC_F8,  KC_F10, KC_F2,  KC_F4,   KC_F6,
                                   _______, _______, _______, _______
    ),

    [NUMPAD] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, KC_7, KC_8, KC_9, KC_0,
        XXXXXXX, OS_ALT,  OS_CTRL, OS_SHFT, OSM_HYPR,         XXXXXXX, KC_4, KC_5, KC_6, OS_CMD,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, KC_1, KC_2, KC_3, XXXXXXX,
        _______ , OS_CMD , _______ , _______
    ),
};

// vi: nowrap
