#include <stdint.h>
#include QMK_KEYBOARD_H

#include "nocksock.h"
#include "oneshot.h"
#include "swapper.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // NOTE: there are two KC_B keys, so when copying from another layout, make
    // sure to accomodate that.

    [BASE] = LAYOUT_ansi_69(
        KC_ESC  , KC_1    , KC_2    , KC_3   , KC_4   , KC_5   , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_MINS , KC_EQL  , KC_BSPC , KC_MUTE ,
        KC_TAB  , KC_Q    , KC_W    , KC_E   , KC_R   , KC_T   , KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    , KC_LBRC , KC_RBRC , KC_BSLS , TG(COLOR) ,
        KC_LCTL , KC_A    , KC_S    , KC_D   , KC_F   , KC_G   , KC_H    , KC_J    , KC_K    , KC_L    , KC_SCLN , KC_QUOT , KC_RTNC , KC_HOME ,
        KC_LSFT , KC_LTZ    , KC_X    , KC_C   , KC_V   , KC_B   , KC_B    , KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , KC_RSFT , KC_UP   ,
        KC_MEH  , KC_LOPT , KC_LCMD , KC_SPC , LA_NAV , LA_SYM , KC_SESC , KC_RCMD , KC_LEFT , KC_DOWN , KC_RGHT
    )           ,

    [SYM] = LAYOUT_ansi_69(
        _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
        RGB_TOG , KC_ESC  , KC_LBRC , KC_LPRN , KC_LCBR , KC_TILD , KC_CIRC , KC_RCBR , KC_RPRN , KC_RBRC , KC_GRV  , _______ , _______ , _______ , _______ ,
        _______ , KC_MINS , KC_ASTR , KC_EQL  , KC_UNDS , KC_DLR  , KC_HASH , OS_SHFT , OS_CTRL , OS_ALT  , OS_CMD  , _______ , _______ , _______ ,
        _______ , KC_PLUS , KC_PIPE , KC_AT   , KC_SLSH , KC_PERC , _______ , _______ , KC_BSLS , KC_AMPR , KC_EXLM , KC_QUES , _______ , _______ ,
        _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______
    ) ,

    [NAV] = LAYOUT_ansi_69(
        _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , KC_TAB  , SW_WIN  , TAB_L   , TAB_R   , KC_VOLU , QK_BOOT , HOME    , KC_CAPS , END     , KC_DEL  , _______ , _______ , _______ , _______ ,
        _______ , OS_CMD  , OS_ALT  , OS_CTRL , OS_SHFT , KC_VOLD , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT , KC_BSPC , _______ , _______ , _______ ,
        _______ , SPACE_L , SPACE_R , BACK    , FWD     , KC_MPLY , _______ , CW_TOGG , KC_PGDN , KC_PGUP , SW_LANG , KC_ENT  , _______ , _______ ,
        _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______
    ),

    [NUM] = LAYOUT_ansi_69(
        _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , KC_7    , KC_5    , KC_3    , KC_1    , KC_9    , KC_8    , KC_0    , KC_2    , KC_4    , KC_6    , _______ , _______ , _______ , _______ ,
        _______ , OS_SHFT , OS_CTRL , OS_ALT  , OS_CMD  , KC_F11  , KC_F12  , OS_CMD  , OS_ALT  , OS_CTRL , OS_SHFT , _______ , _______ , _______ ,
        _______ , KC_F7   , KC_F5   , KC_F3   , KC_F1   , KC_F9   , _______ , KC_F8   , KC_F10  , KC_F2   , KC_F4   , KC_F6   , _______ , _______ ,
        _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______
    ),

    [NUMPAD] = LAYOUT_ansi_69(
        _______ , _______ , _______ , _______ , _______ , _______  , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX  , XXXXXXX , KC_7    , KC_8    , KC_9    , KC_0    , _______ , _______ , _______ , _______ ,
        _______ , XXXXXXX , OS_ALT  , OS_CTRL , OS_SHFT , OSM_HYPR , XXXXXXX , KC_4    , KC_5    , KC_6    , OS_CMD  , _______ , _______ , _______ ,
        _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX  , _______ , XXXXXXX , KC_1    , KC_2    , KC_3    , XXXXXXX , _______ , _______ ,
        _______ , _______ , _______ , _______ , OS_CMD  , _______  , _______ , _______ , _______ , _______ , _______
    ),

    [COLOR] = LAYOUT_ansi_69(
        _______ , KC_BRID  , KC_BRIU , _______ , _______ , RGB_VAD , RGB_VAI , KC_MPRV , KC_MPLY , KC_MNXT , KC_MUTE  , KC_VOLD , KC_VOLU , _______ , _______ ,
        RGB_TOG , RGB_MOD  , RGB_VAI , RGB_HUI , RGB_SAI , RGB_SPI , _______ , _______ , _______ , _______ , _______  , _______ , _______ , _______ , _______ ,
        _______ , RGB_RMOD , RGB_VAD , RGB_HUD , RGB_SAD , RGB_SPD , _______ , _______ , _______ , _______ , _______  , _______ , _______ , _______ ,
        _______ , _______  , _______ , _______ , _______ , _______ , _______ , NK_TOGG , _______ , _______ , _______  , _______ , _______ , _______ ,
        _______ , _______  , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______
    ) ,


    // [LAYER] = LAYOUT_ansi_69(
    //     _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    //     _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    //     _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    //     _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    //     _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______
    // ),

};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [BASE]   = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [SYM]    = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [NAV]    = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [NUM]    = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [NUMPAD] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [COLOR]  = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
};
#endif
