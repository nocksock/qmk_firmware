#include <stdint.h>/*{{{*/
#include "config.h"
#include "version.h"
#include "nocksock.h"/*}}}*/

#include QMK_KEYBOARD_H

#define LAYOUT LAYOUT_split_3x6_3

const uint16_t PROGMEM commdot_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM left_altctrl_combo[] = {KC_LEFT_ALT, KC_LEFT_CTRL, COMBO_END};
const uint16_t PROGMEM right_altctrl_combo[] = {KC_RIGHT_ALT, KC_RIGHT_CTRL, COMBO_END};
const uint16_t PROGMEM os_altctrl_combo[] = {OS_ALT, OS_CTRL, COMBO_END};

combo_t key_combos[] = {
    COMBO(commdot_combo, KC_ENT),
    COMBO(jk_combo, KC_ESC),
    COMBO(left_altctrl_combo, OSM_HYPR),
    COMBO(right_altctrl_combo, OSM_HYPR),
    COMBO(os_altctrl_combo, OSM_HYPR),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
        KC_TAB  , KC_Q   , KC_W   , KC_E   , KC_R    , KC_T , KC_Y , KC_U , KC_I    , KC_O   , KC_P    , XXXXXXX ,
        KC_LCTL , KC_A   , KC_S   , KC_D   , KC_F    , KC_G , KC_H , KC_J , KC_K    , KC_L   , KC_SCLN , KC_CQOT ,
        KC_LSFT , KC_Z , KC_X   , KC_C   , KC_V    , KC_B , KC_N , KC_M , KC_COMM , KC_DOT , KC_SLSH , KC_SRET ,
        KC_LGUI , KC_SPC , LA_NAV , LA_SYM , KC_RSFT , KC_ROPT
    ),

    [SYM] = LAYOUT(
        _______  , KC_ESC  , KC_AT   , KC_HASH , KC_DLR  , KC_PERC , KC_CIRC , KC_AMPR        , KC_ASTR       , KC_LCBR      , KC_RCBR      , _______  ,
        OSM_HYPR , KC_MINS , KC_EQL  , KC_LPRN , KC_RPRN , KC_QUOT , KC_PIPE , KC_RIGHT_SHIFT , KC_RIGHT_CTRL , KC_RIGHT_ALT , KC_RIGHT_GUI , OSM_HYPR ,
        _______  , KC_GRV  , KC_BSLS , KC_LBRC , KC_RBRC , KC_UNDS , XXXXXXX , KC_EXLM        , KC_LABK       , KC_RABK      , KC_QUES      , _______  ,
        _______  , _______ , _______ , _______ , _______ , _______
    ),

    [NAV] = LAYOUT(
        _______  , KC_HTAB , SW_WIN  , TAB_L   , TAB_R   , XXXXXXX , KC_HOME , KC_PAGE_DOWN , KC_PAGE_UP , KC_END  , KC_DEL  , QK_BOOT   ,
        OSM_HYPR , KC_LEFT_GUI  , KC_LEFT_ALT  , KC_LEFT_CTRL , KC_LEFT_SHIFT , KC_MNXT , KC_LEFT , KC_DOWN      , KC_UP      , KC_RGHT , KC_BSPC , OSM_HYPR   ,
        _______  , SPACE_L , SPACE_R , BACK    , FWD     , KC_MPLY , XXXXXXX , CW_TOGG      , KC_TAB    , SW_LANG , KC_ENT  , TO(COLOR) ,
        _______ , _______ , _______ , _______ , _______ , _______
    ),


    [NUM] = LAYOUT(
        _______ , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    ,  KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , _______ ,
        OSM_HYPR , OS_CMD  , OS_ALT  , OS_CTRL , OS_SHFT , KC_F11  ,  KC_F12  , OS_SHFT , OS_CTRL , OS_ALT  , OS_CMD  , OSM_HYPR ,
        _______ , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   ,  KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , _______ ,
        _______ , _______ , _______ ,  _______ , _______ , _______
    ),

    [COLOR] = LAYOUT(
        RGB_RMOD , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , DB_TOGG ,
        RGB_TOG  , RGB_HUI , RGB_SAI , RGB_VAI , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
        RGB_MOD  , RGB_HUD , RGB_SAD , RGB_VAD , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , TO(BASE) ,
        _______ , _______ , _______ , _______ , _______ , _______
  )
};

#ifdef OLED_ENABLE
// this is work in progress
bool oled_task_user(void) {
    // Host Keyboard Layer Status
    switch (get_highest_layer(layer_state)) {
        case BASE:
            oled_write_P(PSTR("BASE\n"), false);
            break;
        case SYM:
            oled_write_P(PSTR("SMBL\n"), false);
            break;
        case NAV:
            oled_write_P(PSTR("NAVI\n"), false);
            break;
        case NUM:
            oled_write_P(PSTR("FNUM\n"), false);
            break;
        case COLOR:
            oled_write_P(PSTR("COLR\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("NKWN"), false);
    }

    return false;
}
#endif
