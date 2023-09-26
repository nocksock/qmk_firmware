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
        KC_LCTL , KC_A    , KC_S    , KC_D    , KC_F    , KC_G    , XXXXXXX , XXXXXXX , KC_H    , KC_J    , KC_K    , KC_L    , KC_SCLN , KC_CQOT ,
        KC_LSFT , KC_LTZ  , KC_X    , KC_C    , KC_V    , KC_B    ,                     KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , KC_ENT ,
        XXXXXXX , XXXXXXX , XXXXXXX , KC_LOPT , KC_LCMD ,           XXXXXXX , XXXXXXX ,           KC_RCMD , KC_ROPT , XXXXXXX , XXXXXXX , TG(COLOR) ,
                                      KC_SPC  , LA_NAV  , XXXXXXX ,                     XXXXXXX , LA_SYM  , KC_RSFT
    ),

    [SYM] = LAYOUT_moonlander(
        _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , KC_ESC  , KC_AT   , KC_HASH , KC_DLR  , KC_PERC , _______ , _______ , KC_CIRC , KC_AMPR , KC_ASTR , KC_LCBR , KC_RCBR , _______ ,
        _______ , KC_MINS , KC_QUOT , KC_LPRN , KC_RPRN , KC_EQL  , _______ , _______ , XXXXXXX , OS_SHFT , OS_CTRL , OS_ALT  , OS_CMD  , _______ ,
        _______ , KC_GRV  , KC_BSLS , KC_LBRC , KC_RBRC , KC_UNDS ,                     KC_PIPE , KC_EXLM , KC_LABK , KC_RABK , KC_QUES , _______ ,
        _______ , _______ , _______ , _______ , _______ ,           _______ , _______ ,           _______ , _______ , _______ , _______ , _______ ,
                                      _______ , _______ , _______ ,                     _______ , _______ , _______
    ),

    [NAV] = LAYOUT_moonlander(
        _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , KC_TAB  , SW_WIN  , TAB_L   , TAB_R   , XXXXXXX , _______ , _______ , QK_BOOT , XXXXXXX , XXXXXXX , XXXXXXX , KC_DEL  , _______ ,
        _______ , OS_CMD  , OS_ALT  , OS_CTRL , OS_SHFT , KC_MNXT , _______ , _______ , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT , KC_BSPC , _______ ,
        _______ , SPACE_L , SPACE_R , BACK    , FWD     , KC_MPLY ,                     XXXXXXX , CW_TOGG , XXXXXXX , SW_LANG , KC_ENT  , _______ ,
        _______ , _______ , _______ , _______ , _______ ,           _______ , _______ ,           _______ , _______ , _______ , _______ , _______ ,
                                      _______ , _______ , _______ ,                     _______ , _______ , _______
    ),

    [NUM] = LAYOUT_moonlander(
        _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , _______ , _______ , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , _______ ,
        _______ , OS_CMD  , OS_ALT  , OS_CTRL , OS_SHFT , KC_F11  , _______ , _______ , KC_F12  , OS_SHFT , OS_CTRL , OS_ALT  , OS_CMD  , _______ ,
        _______ , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   ,                     KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , _______ ,
        _______ , _______ , _______ , _______ , _______ ,           _______ , _______ ,           _______ , _______ , _______ , _______ , _______ ,
                                      _______ , _______ , _______ ,                     _______ , _______ , _______
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
                                      _______ , _______ , _______ ,                      _______ , _______ , _______
    ),

};

