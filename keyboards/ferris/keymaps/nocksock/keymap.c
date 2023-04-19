#include QMK_KEYBOARD_H
#include "./oneshot.h"

// format macro: Vjjga*€kr,^f5f,kkA		^
// keycodes overview: https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md

enum layers {
  BASE,
  SYM,
  EXT,
  NUM,
  SYS,
  FKEY
};

#define KC_LTZ LT(NUM, KC_Z) 

#define LA_SYM MO(SYM)
#define LA_EXT MO(EXT)
#define LA_NUM OSL(NUM)
#define LA_FKEY OSL(FKEY)
#define LA_SYS OSL(SYS)
#define OSM_HYPR OSM(MOD_HYPR)

enum keycodes {
	OS_SHFT = SAFE_RANGE,
	OS_CTRL,
	OS_ALT,
	OS_CMD,
};

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state  = os_up_unqueued;
oneshot_state os_cmd_state  = os_up_unqueued;

const uint16_t PROGMEM comb_fr[] = {KC_F, KC_R, COMBO_END};
const uint16_t PROGMEM comb_de[] = {KC_E, KC_D, COMBO_END};
const uint16_t PROGMEM comb_sw[] = {KC_S, KC_W, COMBO_END};
const uint16_t PROGMEM comb_aq[] = {KC_A, KC_Q, COMBO_END};

const uint16_t PROGMEM comb_ju[] = {KC_J, KC_U, COMBO_END};
const uint16_t PROGMEM comb_ki[] = {KC_K, KC_I, COMBO_END};
const uint16_t PROGMEM comb_lo[] = {KC_L, KC_O, COMBO_END};
const uint16_t PROGMEM comb_scln[] = {KC_SCLN, KC_P, COMBO_END};

const uint16_t PROGMEM comb_hj[] = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM comb_fg[] = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM comb_leftthumb[] = {LA_EXT, KC_SPC, COMBO_END};

const uint16_t PROGMEM comb_comdot[] = {KC_COMM, KC_DOT, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(comb_fr, KC_LCMD),
    COMBO(comb_de, KC_LCTL),
    COMBO(comb_sw, KC_LALT),
    COMBO(comb_aq, KC_LSFT),
    
    COMBO(comb_fg, KC_TAB),
    COMBO(comb_hj, KC_BSPC),

    COMBO(comb_ju, KC_RCMD),
    COMBO(comb_ki, KC_RCTL),
    COMBO(comb_lo, KC_RALT),
    COMBO(comb_scln, KC_RSFT),
    COMBO(comb_leftthumb, OSM_HYPR),

    COMBO(comb_comdot, KC_ENT)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT( 
        KC_Q   , KC_W , KC_E , KC_R , KC_T ,     KC_Y , KC_U , KC_I    , KC_O   , KC_P    ,
        KC_A   , KC_S , KC_D , KC_F , KC_G ,     KC_H , KC_J , KC_K    , KC_L   , KC_SCLN ,
        KC_LTZ , KC_X , KC_C , KC_V , KC_B ,     KC_N , KC_M , KC_COMM , KC_DOT , KC_SLSH ,
        LA_EXT , KC_SPC , KC_RSFT , LA_SYM
  ),

  [SYM] = LAYOUT( 
        KC_EXLM  , KC_AT   , KC_HASH , KC_DLR  , KC_PERC ,     KC_CIRC  , KC_AMPR , KC_ASTR , KC_DQUO , KC_MINUS ,
        KC_EQUAL , KC_LCBR , KC_LPRN , KC_RPRN , KC_RCBR ,     KC_QUOTE , OS_SHFT , OS_CTRL , OS_ALT  , OS_CMD   ,
        KC_GRV   , XXXXXXX , KC_LBRC , KC_RBRC , KC_BSLS ,     XXXXXXX  , KC_UNDS , KC_LABK , KC_RABK , KC_SLSH  ,
        MO(FKEY), _______  , _______, _______
  ),
          
  [EXT] = LAYOUT( 
        KC_ESC , XXXXXXX , XXXXXXX , KC_TAB , XXXXXXX  ,    KC_HOME , KC_PGDN , KC_PGUP , KC_END   , CAPSWRD ,
        OS_CMD , OS_ALT  , OS_CTRL , OS_SHFT , OSM_HYPR ,    KC_LEFT , KC_DOWN , KC_UP   , KC_RIGHT , KC_TAB ,
        XXXXXXX , XXXXXXX , KC_BSPC , KC_ENT  , KC_MPLY  ,    KC_BSPC , XXXXXXX , XXXXXXX , KC_DEL   , XXXXXXX ,
        _______  , _______ , _______,  MO(FKEY)
  ),


  [NUM] = LAYOUT( 
        KC_1    , KC_2    , KC_3    , KC_4    , KC_5     ,     KC_6    , KC_7 , KC_8 , KC_9 , KC_0    ,
        OS_CMD  , OS_ALT  , OS_CTRL , OS_SHFT , OSM_HYPR ,     XXXXXXX , KC_4 , KC_5 , KC_6 , OS_CMD  ,
        XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX  ,     KC_0    , KC_1 , KC_2 , KC_3 , XXXXXXX ,
        _______ , _______ , _______ , _______
  ),

  [FKEY] = LAYOUT( 
        KC_F13 , KC_F14 , KC_F15 , KC_F16 , KC_F17  ,     KC_F13 , KC_F7 , KC_F8 , KC_F9 , XXXXXXX ,
        OS_CMD  , OS_ALT  , OS_CTRL , OS_SHFT , OSM_HYPR ,     KC_F11 , KC_F4 , KC_F5 , KC_F6 , LA_SYS ,
        XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX  ,     KC_F10 , KC_F1 , KC_F2 , KC_F3 , XXXXXXX ,
        _______ , _______ , _______ , _______
  ),

  // system layer
  [SYS] = LAYOUT( 
        XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,    QK_BOOT , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
        XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
        XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
        _______, _______, _______, _______
  ),
};


bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case LA_SYM:
    case LA_EXT:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case LA_SYM:
    case LA_EXT:
    case OS_SHFT:
    case OS_CTRL:
    case OS_ALT:
    case OS_CMD:
        return true;
    default:
        return false;
    }
}

bool process_record_user( uint16_t keycode, keyrecord_t *record ) {
	#ifdef CONSOLE_ENABLE
		uprintf(
			"keycode: %u, layer_state: %u, pressed: %u, shift: %u, ctrl: %u, alt: %u, cmd: %u \n",
			keycode,
			layer_state,
			record->event.pressed,
			os_shft_state,
			os_ctrl_state,
			os_alt_state,
			os_cmd_state
		);
	#endif

	// Turn one-shot mods on/off.
	update_oneshot( &os_shft_state, KC_LSFT, OS_SHFT, keycode, record );
	update_oneshot( &os_ctrl_state, KC_LCTL, OS_CTRL, keycode, record );
	update_oneshot(	&os_alt_state,  KC_LALT, OS_ALT,  keycode, record );
	update_oneshot( &os_cmd_state,  KC_LCMD, OS_CMD,  keycode, record );

	return true; // Continue processing the key event
}

// vi: nowrap
