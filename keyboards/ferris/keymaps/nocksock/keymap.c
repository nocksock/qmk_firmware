#include QMK_KEYBOARD_H
#include "oneshot.h"
#include "swapper.h"

// format macro: Vjjga*€kr,^f5f,kkA		^
// keycodes overview: https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md

enum layers {
  BASE,
  SYM,
  NAV,
  NUM,
  FKEY,
  NUMPAD,
};

#define LA_SYM MO(SYM)
#define LA_FKEY OSL(FKEY)
#define OSM_HYPR OSM(MOD_HYPR)
#define HOME G(KC_LEFT)
#define END G(KC_RGHT)
#define FWD G(KC_RBRC)
#define BACK G(KC_LBRC)
#define TAB_L G(S(KC_LBRC))
#define TAB_R G(S(KC_RBRC))
#define SPACE_L A(G(KC_LEFT))
#define SPACE_R A(G(KC_RGHT))
#define LA_SYM MO(SYM)
#define LA_NAV MO(NAV)
#define LA_NUM MO(NUM)
#define KC_LTZ LT(NUMPAD, KC_Z) 

enum keycodes {
	OS_SHFT = SAFE_RANGE,
	OS_CTRL,
	OS_ALT,
	OS_CMD,

  SW_WIN,  // Switch to next window         (cmd-tab)
  SW_LANG, // Switch to next input language (ctl-spc)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT( 
          KC_Q   , KC_W , KC_E , KC_R , KC_T ,     KC_Y , KC_U , KC_I    , KC_O   , KC_P    ,
          KC_A   , KC_S , KC_D , KC_F , KC_G ,     KC_H , KC_J , KC_K    , KC_L   , KC_SCLN ,
          KC_LTZ , KC_X , KC_C , KC_V , KC_B ,     KC_N , KC_M , KC_COMM , KC_DOT , KC_QUOT ,
          LA_NAV , KC_SPC , RSFT_T(KC_ESC), LA_SYM
    ),

    [SYM] = LAYOUT(
        KC_ESC,  KC_LBRC, KC_LCBR, KC_LPRN, KC_TILD, KC_CIRC, KC_RPRN, KC_RCBR, KC_RBRC, KC_GRV,
        KC_MINS, KC_ASTR, KC_EQL,  KC_UNDS, KC_DLR,  KC_HASH, OS_SHFT, OS_CTRL, OS_ALT,  OS_CMD,  
        KC_PLUS, KC_PIPE, KC_AT,   KC_SLSH, KC_PERC, XXXXXXX, KC_BSLS, KC_AMPR, KC_EXLM ,KC_QUES,
                                   _______, _______, _______, _______
    ),

    [NAV] = LAYOUT(
        KC_TAB,  SW_WIN,  TAB_L,   TAB_R,   KC_VOLU, RESET,   HOME,    KC_CAPS, END,     KC_DEL,
        OS_CMD,  OS_ALT,  OS_CTRL, OS_SHFT, KC_VOLD, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BSPC,
        SPACE_L, SPACE_R, BACK,    FWD,     KC_MPLY, CAPSWRD, KC_PGDN, KC_PGUP, SW_LANG, KC_ENT,
                                   _______, _______, _______, _______
    ),

    [NUM] = LAYOUT(
        KC_7,    KC_5,    KC_3,    KC_1,    KC_9,    KC_8,    KC_0,    KC_2,    KC_4,    KC_6,
        OS_SHFT, OS_CTRL, OS_ALT,  OS_CMD,  KC_F11,  KC_F12,  OS_CMD,  OS_ALT,  OS_CTRL, OS_SHFT,
        KC_F7,   KC_F5,   KC_F3,   KC_F1,   KC_F9,   KC_F8,   KC_F10,  KC_F2,   KC_F4,   KC_F6,
                                   _______, _______, _______, _______
    ),

    [NUMPAD] = LAYOUT( 
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, KC_7, KC_8, KC_9, KC_0,
        OS_CMD,  OS_ALT,  OS_CTRL, OS_SHFT, OSM_HYPR, XXXXXXX, KC_4, KC_5, KC_6, OS_CMD,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, KC_1, KC_2, KC_3, XXXXXXX,
        _______ , _______ , _______ , _______
    ),


};

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case LA_SYM:
    case LA_NAV:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case LA_SYM:
    case LA_NAV:
    case KC_LSFT:
    case OS_SHFT:
    case OS_CTRL:
    case OS_ALT:
    case OS_CMD:
        return true;
    default:
        return false;
    }
}

bool sw_win_active = false;
bool sw_lang_active = false;

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_swapper(
        &sw_win_active, KC_LGUI, KC_TAB, SW_WIN,
        keycode, record
    );
    update_swapper(
        &sw_lang_active, KC_LCTL, KC_SPC, SW_LANG,
        keycode, record
    );

    update_oneshot(
        &os_shft_state, KC_LSFT, OS_SHFT,
        keycode, record
    );
    update_oneshot(
        &os_ctrl_state, KC_LCTL, OS_CTRL,
        keycode, record
    );
    update_oneshot(
        &os_alt_state, KC_LALT, OS_ALT,
        keycode, record
    );
    update_oneshot(
        &os_cmd_state, KC_LCMD, OS_CMD,
        keycode, record
    );

    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, SYM, NAV, NUM);
}

// vi: nowrap
