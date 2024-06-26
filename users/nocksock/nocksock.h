#pragma once

#include QMK_KEYBOARD_H

enum layers {
    BASE,
    WIN_BASE,
    SYM,
    NAV,
    NUM,
    FKEY,
    FPAD,
    NUMPAD,
    COLOR,
};

enum keycodes {
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_CMD,
    SW_WIN,  // Switch to next window         (cmd-tab)
    SW_LANG, // Switch to next input language (ctl-spc)
};

// Layer macros
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
#define LA_FPAD MO(FPAD)
#define KC_LTZ LT(NUMPAD, KC_Z)
#define KC_SESC RSFT_T(KC_ESC)
#define KC_SRET RSFT_T(KC_ENT)
#define KC_RTNC RCTL_T(KC_ENT)
#define KC_HTAB HYPR_T(KC_TAB)
#define KC_SESC RSFT_T(KC_ESC)
#define KC_CQOT RCTL_T(KC_QUOT)
#define KC_CCNT C(G(KC_ENT))
#define KC_CCSM C(G(KC_COLN))

// Function prototypes
bool process_record_user(uint16_t keycode, keyrecord_t *record);
layer_state_t layer_state_set_user(layer_state_t state);
