#include <stdint.h>
#include QMK_KEYBOARD_H
#include "version.h"
#include "nocksock.h"
#include "oneshot.h"
#include "swapper.h"

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_split_3x6_3(
      KC_TAB  , KC_Q   , KC_W   , KC_E   , KC_R    , KC_T , KC_Y , KC_U , KC_I    , KC_O   , KC_P    , KC_BSPC ,
      KC_LCTL , KC_A   , KC_S   , KC_D   , KC_F    , KC_G , KC_H , KC_J , KC_K    , KC_L   , KC_SCLN , KC_QUOT ,
      KC_LSFT , KC_LTZ , KC_X   , KC_C   , KC_V    , KC_B , KC_N , KC_M , KC_COMM , KC_DOT , KC_SLSH , KC_SRET  ,
      KC_LGUI , KC_SPC , LA_NAV , LA_SYM , KC_RSFT , KC_ROPT
  ),

    [SYM] = LAYOUT_split_3x6_3(
        _______ , KC_ESC  , KC_LBRC , KC_LCBR , KC_LPRN , KC_TILD ,  KC_CIRC , KC_RPRN , KC_RCBR , KC_RBRC , KC_GRV  , _______ ,
        _______ , KC_MINS , KC_ASTR , KC_EQL  , KC_UNDS , KC_DLR  ,  KC_HASH , OS_SHFT , OS_CTRL , OS_ALT  , OS_CMD  , _______ ,
        _______ , KC_PLUS , KC_PIPE , KC_AT   , KC_SLSH , KC_PERC ,  XXXXXXX , KC_BSLS , KC_AMPR , KC_EXLM , KC_QUES , _______ ,
        _______ , _______ , _______ ,  _______ , _______ , _______
  ),

    [NAV] = LAYOUT_split_3x6_3(
        _______ , KC_TAB  , SW_WIN  , TAB_L   , TAB_R   , KC_VOLU , QK_BOOT , HOME    , KC_CAPS , END     , KC_DEL  , _______ ,
        _______ , OS_CMD  , OS_ALT  , OS_CTRL , OS_SHFT , KC_VOLD , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT , KC_BSPC , _______ ,
        _______ , SPACE_L , SPACE_R , BACK    , FWD     , KC_MPLY , CW_TOGG , KC_PGDN , KC_PGUP , SW_LANG , KC_ENT  , TO(COLOR) ,
        _______ , _______ , _______ , _______ , _______ , _______
    ),

    [NUM] = LAYOUT_split_3x6_3(
        _______ , KC_7    , KC_5    , KC_3    , KC_1    , KC_9    ,  KC_8    , KC_0    , KC_2    , KC_4    , KC_6    , _______ ,
        _______ , OS_SHFT , OS_CTRL , OS_ALT  , OS_CMD  , KC_F11  ,  KC_F12  , OS_CMD  , OS_ALT  , OS_CTRL , OS_SHFT , _______ ,
        _______ , KC_F7   , KC_F5   , KC_F3   , KC_F1   , KC_F9   ,  KC_F8   , KC_F10  , KC_F2   , KC_F4   , KC_F6   , _______ ,
        _______ , _______ , _______ ,  _______ , _______ , _______
    ),

    [NUMPAD] = LAYOUT_split_3x6_3(
        _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX  , XXXXXXX , KC_7 , KC_8 , KC_9 , XXXXXXX , _______ ,
        _______ , XXXXXXX , OS_ALT  , OS_CTRL , OS_SHFT , OSM_HYPR , XXXXXXX , KC_4 , KC_5 , KC_6 , OS_CMD  , _______ ,
        _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX  , KC_0    , KC_1 , KC_2 , KC_3 , XXXXXXX , _______ ,
        _______ , _______ , _______ , _______ , _______ , _______
    ),

    [COLOR] = LAYOUT_split_3x6_3(
        RGB_RMOD , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
        RGB_TOG  , RGB_HUI , RGB_SAI , RGB_VAI , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
        RGB_MOD  , RGB_HUD , RGB_SAD , RGB_VAD , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , TO(BASE) ,
        _______ , _______ , _______ , _______ , _______ , _______
  )
};

// this is work in progress
bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case BASE:
            oled_write_P(PSTR("BASE\n"), false);
            break;
        case SYM:
            oled_write_P(PSTR("SYMBOLS\n"), false);
            break;
        case NAV:
            oled_write_P(PSTR("NAV\n"), false);
            break;
        case NUM:
            oled_write_P(PSTR("NUMs and FKeys\n"), false);
            break;
        case NUMPAD:
            oled_write_P(PSTR("NUMPAD\n"), false);
            break;
        case COLOR:
            oled_write_P(PSTR("COLOR\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("UNKNOWN"), false);
    }

    return false;
}

