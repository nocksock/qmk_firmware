#include <stdint.h>
#include QMK_KEYBOARD_H
#include "version.h"
#include "nocksock.h"
#include "oneshot.h"
#include "swapper.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [BASE] = LAYOUT_moonlander(
        KC_ESC  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , XXXXXXX , XXXXXXX , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_MINS ,
        KC_HTAB , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    , XXXXXXX , XXXXXXX , KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    , KC_BSLS ,
        KC_LCTL , KC_A    , KC_S    , KC_D    , KC_F    , KC_G    , XXXXXXX , XXXXXXX , KC_H    , KC_J    , KC_K    , KC_L    , KC_SCLN , KC_QUOT ,
        KC_LSFT , KC_LTZ  , KC_X    , KC_C    , KC_V    , KC_B    ,                     KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , KC_RSFT ,
        XXXXXXX , XXXXXXX , XXXXXXX , KC_LOPT , KC_LCMD ,           XXXXXXX , XXXXXXX ,           KC_RCMD , KC_ROPT , XXXXXXX , XXXXXXX , TG(COLOR) ,
                                      KC_SPC  , LA_NAV  , XXXXXXX ,                     XXXXXXX , LA_SYM  , KC_SESC
    ),

    [SYM] = LAYOUT_moonlander(
        _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , KC_ESC  , KC_LBRC , KC_LCBR , KC_LPRN , KC_TILD , _______ , _______ , KC_CIRC , KC_RPRN , KC_RCBR , KC_RBRC , KC_GRV  , _______ ,
        _______ , KC_MINS , KC_ASTR , KC_EQL  , KC_UNDS , KC_DLR  , _______ , _______ , KC_HASH , OS_SHFT , OS_CTRL , OS_ALT  , OS_CMD  , _______ ,
        _______ , KC_PLUS , KC_PIPE , KC_AT   , KC_SLSH , KC_PERC ,                     XXXXXXX , KC_BSLS , KC_AMPR , KC_EXLM , KC_QUES , _______ ,
        _______ , _______ , _______ , _______ , _______ ,           _______ , _______ ,           _______ , _______ , _______ , _______ , _______ ,
                                      _______ , _______ , _______,                      _______ , _______  , _______
    ),

    [NAV] = LAYOUT_moonlander(
        _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , KC_TAB,  SW_WIN,  TAB_L,   TAB_R,   KC_VOLU ,     _______ , _______ , QK_BOOT, HOME,    KC_CAPS, END,     KC_DEL,  _______ ,
        _______ , OS_CMD,  OS_ALT,  OS_CTRL, OS_SHFT, KC_VOLD ,     _______ , _______ , KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BSPC, _______ ,
        _______ , SPACE_L, SPACE_R, BACK,    FWD,     KC_MPLY ,                         CW_TOGG, KC_PGDN, KC_PGUP, SW_LANG, KC_ENT,  _______ ,
        _______ , _______ , _______ , _______ , _______ ,           _______ , _______ ,           _______ , _______ , _______ , _______ , _______ ,
                                      _______ , _______ , _______,                      _______ , _______  , _______
    ),

    [NUM] = LAYOUT_moonlander(
        _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , KC_7    , KC_5    , KC_3    , KC_1    , KC_9    , _______ , _______ , KC_8    , KC_0    , KC_2    , KC_4    , KC_6    , _______ ,
        _______ , OS_SHFT , OS_CTRL , OS_ALT  , OS_CMD  , KC_F11  , _______ , _______ , KC_F12  , OS_CMD  , OS_ALT  , OS_CTRL , OS_SHFT , _______ ,
        _______ , KC_F7   , KC_F5   , KC_F3   , KC_F1   , KC_F9   ,                     KC_F8   , KC_F10  , KC_F2   , KC_F4   , KC_F6   , _______ ,
        _______ , _______ , _______ , _______ , _______ ,           _______ , _______ ,           _______ , _______ , _______ , _______ , _______ ,
                                      _______ , _______ , _______,                      _______ , _______  , _______
    ),

    [NUMPAD] = LAYOUT_moonlander(
        _______ , _______ , _______ , _______ , _______ , _______  , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX  , _______ , _______ , XXXXXXX , KC_7    , KC_8    , KC_9    , XXXXXXX , _______ ,
        _______ , XXXXXXX , OS_ALT  , OS_CTRL , OS_SHFT , OSM_HYPR , _______ , _______ , XXXXXXX , KC_4    , KC_5    , KC_6    , OS_CMD  , _______ ,
        _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX  ,                     KC_0    , KC_1    , KC_2    , KC_3    , XXXXXXX , _______ ,
        _______ , _______ , _______ , _______ , _______ ,           _______ , _______ ,            _______ , _______ , _______ , _______ , _______ ,
                                      _______ , _______ , _______ ,                      _______ , _______ , _______
    ),

    [COLOR] = LAYOUT_moonlander(
        _______ , KC_BRID  , KC_BRIU , _______ , _______ , RGB_VAD , RGB_VAI , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
        RGB_TOG , RGB_MOD  , RGB_VAI , RGB_HUI , RGB_SAI , RGB_SPI , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , RGB_RMOD , RGB_VAD , RGB_HUD , RGB_SAD , RGB_SPD , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , _______ , _______ , _______ , _______ , _______ ,                      _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , _______ , _______ , _______ , _______ ,            _______ , _______ ,           _______ , _______ , _______ , _______ , _______ ,
                                     _______ , _______ , _______ ,                       _______ , _______ , _______
    ),

};

