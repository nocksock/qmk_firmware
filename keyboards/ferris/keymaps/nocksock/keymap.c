#include QMK_KEYBOARD_H

// keycodes overview: https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md

#define KC_LTZ LT(4, KC_Z) 
#define KC_LTSLSH LT(4, KC_SLSH) 

const uint16_t PROGMEM comb_we[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM comb_xc[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM comb_io[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM comb_comdot[] = {KC_COMM, KC_DOT, COMBO_END};

#define DEFAULT_LAYER   0
#define GAMING_LAYER    1
#define SYMBOLS_LAYER   2
#define EXTENSION_LAYER 3
#define NUMBERS_LAYER   4
#define FKEY_LAYER      5
#define SYSTEM_LAYER    6

combo_t key_combos[COMBO_COUNT] = {
    COMBO(comb_we, KC_ESC),
    COMBO(comb_xc, KC_TAB),
    COMBO(comb_io, KC_BSPC),
    COMBO(comb_comdot, KC_ENT)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // base layer
  // ----------
  
  [DEFAULT_LAYER] = LAYOUT( 
      KC_Q         , KC_W         , KC_E         , KC_R         , KC_T , KC_Y , KC_U         , KC_I         , KC_O         , KC_P            ,
      LGUI_T(KC_A) , LALT_T(KC_S) , LCTL_T(KC_D) , LSFT_T(KC_F) , HYPR_T(KC_G) , HYPR_T(KC_H) , RSFT_T(KC_J) , RCTL_T(KC_K) , RALT_T(KC_L) , RGUI_T(KC_SCLN) ,
      KC_LTZ       , KC_X         , KC_C         , KC_V         , KC_B , KC_N , KC_M         , KC_COMM      , KC_DOT       , KC_LTSLSH       ,
         LT(EXTENSION_LAYER, KC_SPC), HYPR_T(KC_BSPC), HYPR_T(KC_ESC), LT(SYMBOLS_LAYER, KC_ENT)
  ),
  
  
  // qwerty no homerow layer qp
  [GAMING_LAYER] = LAYOUT( 
      KC_Q         , KC_W         , KC_E         , KC_R         , KC_T , KC_Y , KC_U         , KC_I         , KC_O         , KC_P            ,
      KC_A , KC_S , KC_D , KC_F , KC_G , KC_H , KC_J , KC_K , KC_L , KC_SCLN ,
      KC_LTZ       , KC_X         , KC_C         , KC_V         , KC_B , KC_N , KC_M         , KC_COMM      , KC_DOT       , KC_LTSLSH       ,
         KC_SPC, MO(EXTENSION_LAYER), MO(SYMBOLS_LAYER), KC_ENT
  ),

    
  // symbol layer
  [SYMBOLS_LAYER] = LAYOUT( 
      KC_EXLM  , KC_AT   , KC_HASH , KC_DLR  , KC_PERC , KC_CIRC  , KC_AMPR       , KC_ASTR       , KC_DQUO       , KC_MINUS      ,
      KC_EQUAL , KC_LCBR , KC_LPRN , KC_RPRN , KC_RCBR , KC_QUOTE , OSM( MOD_RSFT ) , OSM( MOD_RCTL ) , OSM( MOD_RALT ) , OSM( MOD_RGUI ) ,
      KC_GRV   , XXXXXXX , KC_LBRC , KC_RBRC , KC_BSLS , XXXXXXX  , KC_UNDS       , KC_LABK       , KC_RABK       , KC_SLSH       ,
              LT(FKEY_LAYER, KC_SPC), LALT(KC_BACKSPACE), _______, _______
  ),

  // extension layer (navigation)
  [EXTENSION_LAYER] = LAYOUT( 
      KC_TAB,  KC_BSPC , XXXXXXX  ,  KC_ENT , XXXXXXX , KC_HOME , KC_PGDN , KC_PGUP , KC_END   , CAPSWRD ,
      OSM( MOD_LGUI ), OSM( MOD_LALT ) , OSM( MOD_LCTL ) , OSM( MOD_LSFT ) , OSM( MOD_HYPR ) , KC_LEFT , KC_DOWN ,   KC_UP , KC_RIGHT ,  KC_DEL ,
      XXXXXXX, XXXXXXX , XXXXXXX  ,  KC_MPLY , XXXXXXX ,  XXXXXXX , XXXXXXX  , XXXXXXX , XXXXXXX  , XXXXXXX ,
                        _______ , _______ , _______ , MO(FKEY_LAYER)
  ),


  // num layer
  [NUMBERS_LAYER] = LAYOUT( 
      KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_6    , KC_7 , KC_8 , KC_9 , KC_0    ,
      _______ , _______ , _______ , _______ , _______ , XXXXXXX , KC_4 , KC_5 , KC_6 , _______ ,
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_0    , KC_1 , KC_2 , KC_3 , XXXXXXX ,
                                    _______ , _______ , _______ , _______
  ),

  // fkey-layer
  [FKEY_LAYER] = LAYOUT( 
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_F12 , KC_F7 , KC_F8 , KC_F9 , OSL(SYSTEM_LAYER) ,
      _______ , _______ , _______ , _______ , XXXXXXX , KC_F11 , KC_F4 , KC_F5 , KC_F6 , XXXXXXX ,
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_F10 , KC_F1 , KC_F2 , KC_F3 , XXXXXXX ,
                       _______, _______, _______, _______
  ),

  // system layer
  [SYSTEM_LAYER] = LAYOUT( 
      DF(GAMING_LAYER) , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , QK_BOOT , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
      XXXXXXX , XXXXXXX , XXXXXXX , DF(DEFAULT_LAYER) , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
                       _______, _______, _______, _______
  ),
};

// vi: nowrap
