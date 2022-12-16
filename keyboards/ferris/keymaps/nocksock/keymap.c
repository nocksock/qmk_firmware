#include QMK_KEYBOARD_H

// keycodes overview: https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md

#define KC_LTZ LT(3, KC_Z) 
#define KC_LTSLSH LT(3, KC_SLSH) 

const uint16_t PROGMEM comb_we[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM comb_xc[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM comb_io[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM comb_comdot[] = {KC_COMM, KC_DOT, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(comb_we, KC_ESC),
    COMBO(comb_xc, KC_TAB),
    COMBO(comb_io, KC_BSPC),
    COMBO(comb_comdot, KC_ENT)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // base layer
  [0] = LAYOUT( 
      KC_Q         , KC_W         , KC_E         , KC_R         , KC_T , KC_Y , KC_U         , KC_I         , KC_O         , KC_P            ,
      LGUI_T(KC_A) , LALT_T(KC_S) , LCTL_T(KC_D) , LSFT_T(KC_F) , KC_G , KC_H , RSFT_T(KC_J) , RCTL_T(KC_K) , RALT_T(KC_L) , RGUI_T(KC_SCLN) ,
      KC_LTZ       , KC_X         , KC_C         , KC_V         , KC_B , KC_N , KC_M         , KC_COMM      , KC_DOT       , KC_LTSLSH       ,
         LT(2, KC_SPC), HYPR_T(KC_BSPC), HYPR_T(KC_ESC), LT(1, KC_ENT)
  ),
  
  // symbol layer
  [1] = LAYOUT( 
      KC_EXLM  , KC_AT   , KC_HASH , KC_DLR  , KC_PERC , KC_CIRC  , KC_AMPR       , KC_ASTR       , KC_DQUO       , KC_MINUS      ,
      KC_EQUAL , KC_LCBR , KC_LPRN , KC_RPRN , KC_RCBR , KC_QUOTE , MOD_RSFT , MOD_RCTL , MOD_RALT , MOD_RGUI ,
      KC_GRV   , XXXXXXX , KC_LBRC , KC_RBRC , KC_BSLS , XXXXXXX  , KC_UNDS       , KC_LABK       , KC_RABK       , KC_SLSH       ,
              LT(4, KC_SPC), LALT(KC_BACKSPACE), _______, _______
  ),

  // extension layer (navigation)
  [2] = LAYOUT( 
      KC_TAB   ,  XXXXXXX , KC_MPRV  ,  KC_MNXT , XXXXXXX , KC_HOME , KC_PGDN , KC_PGUP , KC_END   , CAPSWRD ,
      MOD_LGUI , MOD_LALT , MOD_LCTL , MOD_LSFT , XXXXXXX , KC_LEFT , KC_DOWN ,   KC_UP , KC_RIGHT ,  KC_DEL ,
      XXXXXXX  ,  XXXXXXX , XXXXXXX  ,  KC_MPLY , XXXXXXX ,  KC_TAB , KC_ENT  , XXXXXXX , XXXXXXX  , XXXXXXX ,
                        _______ , _______ , _______ , MO(4)
  ),

  // num layer
  [3] = LAYOUT( 
      KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_6    , KC_7 , KC_8 , KC_9 , KC_0    ,
      _______ , _______ , _______ , _______ , XXXXXXX , XXXXXXX , KC_4 , KC_5 , KC_6 , _______ ,
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_0    , KC_1 , KC_2 , KC_3 , XXXXXXX ,
                                    _______ , _______ , _______ , _______
  ),

  // fkey-layer
  [4] = LAYOUT( 
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_F12 , KC_F7 , KC_F8 , KC_F9 , QK_BOOT ,
      _______ , _______ , _______ , _______ , XXXXXXX , KC_F11 , KC_F4 , KC_F5 , KC_F6 , XXXXXXX ,
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_F10 , KC_F1 , KC_F2 , KC_F3 , XXXXXXX ,
                       _______, _______, _______, _______
  )
};

// vi: nowrap
