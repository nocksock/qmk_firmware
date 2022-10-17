#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // base layer
  [0] = LAYOUT( 
    KC_Q         , KC_W         , KC_E         , KC_R         , KC_T , KC_Y , KC_U         , KC_I         , KC_O         , KC_P            ,
    LGUI_T(KC_A) , LALT_T(KC_S) , LCTL_T(KC_D) , LSFT_T(KC_F) , KC_G , KC_H , RSFT_T(KC_J) , RCTL_T(KC_K) , RALT_T(KC_L) , RGUI_T(KC_SCLN) ,
    LT(3         , KC_Z)        , KC_X         , KC_C         , KC_V , KC_B , KC_N         , KC_M         , KC_COMM      , KC_DOT          , LT(3 , KC_SLSH) ,
          LT(1, KC_SPC), HYPR_T(KC_BSPC), HYPR_T(KC_ESC), LT(2, KC_ENT)
  ),

  // symbol layer
  [1] = LAYOUT( 
    KC_EXCLAIM, KC_AT,    KC_HASH,         KC_DOLLAR,        KC_PERCENT,   KC_CIRCUMFLEX, KC_AMPR,        KC_ASTERISK,   KC_DOUBLE_QUOTE, KC_MINUS,
    KC_EQUAL,   KC_LCBR,  KC_LEFT_PAREN,   KC_RIGHT_PAREN,  KC_RCBR,      KC_QUOTE,      KC_RIGHT_SHIFT, KC_RIGHT_CTRL, KC_RIGHT_ALT,    KC_RIGHT_GUI,
    KC_GRAVE,   KC_TILDE, KC_LEFT_BRACKET, KC_RIGHT_BRACKET, KC_BACKSLASH, KC_PIPE,       KC_UNDERSCORE,  KC_LABK,       KC_RABK,         KC_QUESTION,
                                    KC_NO, KC_TRNS, KC_TRNS, MO(4)  
  ),

  // extension layer (navigation)
  [2] = LAYOUT( 
    KC_NO,       KC_NO,       KC_NO,        KC_NO,         KC_NO,               KC_HOME, KC_PAGE_DOWN, KC_PAGE_UP, KC_END,   CAPS_WORD,
    KC_LEFT_GUI, KC_LEFT_ALT, KC_LEFT_CTRL, KC_LEFT_SHIFT, KC_MEDIA_PLAY_PAUSE, KC_LEFT, KC_DOWN,      KC_UP,      KC_RIGHT, KC_DELETE,
    KC_TRNS,     KC_TRNS,     KC_TRNS,      KC_TRNS,       KC_TRNS,             KC_UNDS, KC_PLUS,      KC_TRNS,    KC_TRNS,  QK_BOOT,
                                    MO(4), KC_TRNS, KC_TRNS, KC_NO
  ),

  // num layer
  [3] = LAYOUT( 
    KC_NO,       KC_NO,       KC_NO,        KC_NO,         KC_NO,     KC_NO, KC_7, KC_8, KC_9, KC_NO,
    KC_LEFT_GUI, KC_LEFT_ALT, KC_LEFT_CTRL, KC_LEFT_SHIFT, KC_NO,     KC_NO, KC_4, KC_5, KC_6, KC_RIGHT_GUI,
    KC_NO,       KC_NO,       KC_NO,        KC_NO,         KC_NO,     KC_0,  KC_1, KC_2, KC_3, KC_NO,
                                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  // fkey-layer
  [4] = LAYOUT( 
    KC_NO,       KC_NO,       KC_NO,        KC_NO,         KC_NO,     KC_F12, KC_F7, KC_F8, KC_F9, KC_NO,
    KC_LEFT_GUI, KC_LEFT_ALT, KC_LEFT_CTRL, KC_LEFT_SHIFT, KC_NO,     KC_F11, KC_F4, KC_F5, KC_F6, KC_NO,
    KC_NO,       KC_NO,       KC_NO,        KC_NO,         KC_NO,     KC_F10, KC_F1, KC_F2, KC_F3, KC_NO,
                                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  )

  // [_TEMPLATE] = LAYOUT( 
  //   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  //   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  //   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  //                                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  // )
};
