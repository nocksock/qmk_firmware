#include QMK_KEYBOARD_H

// keycodes overview: https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md

#define KC_LTZ LT(3, KC_Z) 

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // base layer
  [0] = LAYOUT( 
      KC_Q         , KC_W         , KC_E         , KC_R         , KC_T , KC_Y , KC_U         , KC_I         , KC_O         , KC_P            ,
      LGUI_T(KC_A) , LALT_T(KC_S) , LCTL_T(KC_D) , LSFT_T(KC_F) , KC_G , KC_H , RSFT_T(KC_J) , RCTL_T(KC_K) , RALT_T(KC_L) , RGUI_T(KC_SCLN) ,
      KC_LTZ       , KC_X         , KC_C         , KC_V         , KC_B , KC_N , KC_M         , KC_COMM      , KC_DOT       , KC_SLSH         ,
         LT(2, KC_SPC), HYPR_T(KC_BSPC), HYPR_T(KC_ESC), LT(1, KC_ENT)
  ),
  
  // symbol layer
  [1] = LAYOUT( 
      KC_EXCLAIM , KC_AT    , KC_HASH         , KC_DOLLAR        , KC_PERCENT   , KC_CIRCUMFLEX , KC_AMPR       , KC_ASTERISK   , KC_DOUBLE_QUOTE , KC_MINUS      ,
      KC_EQUAL   , KC_LCBR  , KC_LEFT_PAREN   , KC_RIGHT_PAREN   , KC_RCBR      , KC_QUOTE      , OSM(MOD_RSFT) , OSM(MOD_RCTL) , OSM(MOD_RALT)   , OSM(MOD_RGUI) ,
      KC_GRAVE   , KC_TILDE , KC_LEFT_BRACKET , KC_RIGHT_BRACKET , KC_BACKSLASH , KC_PIPE       , KC_UNDERSCORE , KC_LABK       , KC_RABK         , KC_QUESTION   ,
              LT(4, KC_SPC), LALT(KC_BACKSPACE), _______, _______
  ),

  // extension layer (navigation)
  [2] = LAYOUT( 
      XXXXXXX       , XXXXXXX       , KC_MEDIA_PREV_TRACK , KC_MEDIA_NEXT_TRACK , XXXXXXX             , KC_HOME , KC_PAGE_DOWN , KC_PAGE_UP , KC_END   , CAPS_WORD ,
      OSM(MOD_LGUI) , OSM(MOD_LCTL) , OSM(MOD_LALT)       , OSM(MOD_LSFT)       , KC_MEDIA_PLAY_PAUSE , KC_LEFT , KC_DOWN      , KC_UP      , KC_RIGHT , KC_DELETE ,
      XXXXXXX       , XXXXXXX       , XXXXXXX             , XXXXXXX             , XXXXXXX             , KC_UNDS , KC_TAB       , XXXXXXX    , XXXXXXX  , QK_BOOT   ,
                        _______, _______, _______,MO(4)
  ),

  // num layer
  [3] = LAYOUT( 
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_7 , KC_8 , KC_9 , XXXXXXX ,
      _______ , _______ , _______ , _______ , XXXXXXX , XXXXXXX , KC_4 , KC_5 , KC_6 , _______ ,
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_0    , KC_1 , KC_2 , KC_3 , XXXXXXX ,
                       _______, _______, _______, _______
  ),

  // fkey-layer
  [4] = LAYOUT( 
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_F12 , KC_F7 , KC_F8 , KC_F9 , XXXXXXX ,
      _______ , _______ , _______ , _______ , XXXXXXX , KC_F11 , KC_F4 , KC_F5 , KC_F6 , XXXXXXX ,
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_F10 , KC_F1 , KC_F2 , KC_F3 , XXXXXXX ,
                       _______, _______, _______, _______
  )

};
