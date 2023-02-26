#include QMK_KEYBOARD_H
#include <keymap.h>

enum layers{
    MAC_BASE=0,
    MAC_FN_MAIN,
    MAC_FN_CAPLOCK,
    MAC_FN_APPS,

    WIN_BASE,
    WIN_FOR_REMOTE,
    WIN_FN_MAIN,
    WIN_FN_CAPLOCK,

    MAC_FN_TMP1,
    WIN_FN_TMP1,

    BOTH_FN_SPEC_CHAR,
    GameLayer,
    NormalMac,
    NormalWin,
    NormalWin_ForMacUser,
    NumberSwitchLayer,
};


// For Mac
#define MAC_FN_LCAP_TAP -1
#define MAC_FN_LCMD_TAP -1
#define MAC_FN_LCAP_HOLD MAC_FN_CAPLOCK
#define MAC_FN_LCMD_HOLD MAC_FN_MAIN

#define MAC_FN_LSFT_TAP -1

#define MAC_FN_RSFT_HOLD BOTH_FN_SPEC_CHAR
#define MAC_FN_RBSL_HOLD MAC_FN_APPS

#define MAC_FN_RCMD_TAP -1
#define MAC_FN_RCMD_HOLD -1

// For Win
#define WIN_FN_LCAP_TAP -1
#define WIN_FN_LALT_TAP -1
#define WIN_FN_LALT_HOLD WIN_FN_MAIN
#define WIN_FN_LCAP_HOLD WIN_FN_CAPLOCK

#define WIN_FN_LSFT_TAP -1

#define WIN_FN_RSFT_HOLD BOTH_FN_SPEC_CHAR
#define WIN_FN_RBSL_HOLD -1

#define WIN_FN_RALT_TAP -1
#define WIN_FN_RALT_HOLD -1

enum custom_keycodes {
    KC_MISSION_CONTROL = SAFE_RANGE,
    KC_LAUNCHPAD,
    KC_ESC_MOD,
    KC_GEQ,
    KC_LEQ,
    KC_PLUSEQL,
    KC_MINUSEQL,
    KC_MULTEQL,
    KC_DIVEQL,
};



#define KC_MCTL KC_MISSION_CONTROL
#define KC_LPAD KC_LAUNCHPAD

enum {
  WIN_TD_LALT = 0,
  WIN_TD_LSFT,
  WIN_TD_LCAP,
  WIN_TD_RSFT,
  WIN_TD_RBSL,
  MAC_TD_RCMD,

  MAC_TD_LCMD,
  MAC_TD_LSFT,
  MAC_TD_LCAP,
  MAC_TD_RSFT,
  MAC_TD_RBSL,
  WIN_TD_RALT,
};

qk_tap_dance_action_t tap_dance_actions[64] = {
  [WIN_TD_LALT]     = ACTION_TAP_DANCE_TAP_LAYER_HOLD_LAYER(WIN_FN_LALT_TAP, WIN_FN_LALT_HOLD),
  [WIN_TD_LSFT]     = ACTION_TAP_DANCE_TAP_LAYER_HOLD_KEY(WIN_FN_LSFT_TAP, KC_LSFT),
  [WIN_TD_LCAP]     = ACTION_TAP_DANCE_TAP_LAYER_HOLD_LAYER(WIN_FN_LCAP_TAP, WIN_FN_LCAP_HOLD),
  [WIN_TD_RSFT]     = ACTION_TAP_DANCE_TAP_KEY_HOLD_LAYER(KC_RSFT, WIN_FN_RSFT_HOLD),
  [WIN_TD_RBSL]     = ACTION_TAP_DANCE_TAP_KEY_HOLD_LAYER(KC_BSLS, WIN_FN_RBSL_HOLD),
  [MAC_TD_RCMD]     = ACTION_TAP_DANCE_TAP_LAYER_HOLD_LAYER(MAC_FN_RCMD_TAP, MAC_FN_RCMD_HOLD),

  [MAC_TD_LCMD]     = ACTION_TAP_DANCE_TAP_LAYER_HOLD_LAYER(MAC_FN_LCMD_TAP, MAC_FN_LCMD_HOLD),
  [MAC_TD_LSFT]     = ACTION_TAP_DANCE_TAP_LAYER_HOLD_KEY(MAC_FN_LSFT_TAP, KC_LSFT),
  [MAC_TD_LCAP]     = ACTION_TAP_DANCE_TAP_LAYER_HOLD_LAYER(MAC_FN_LCAP_TAP, MAC_FN_LCAP_HOLD),
  [MAC_TD_RSFT]     = ACTION_TAP_DANCE_TAP_KEY_HOLD_LAYER(KC_RSFT, MAC_FN_RSFT_HOLD),
  [MAC_TD_RBSL]     = ACTION_TAP_DANCE_TAP_KEY_HOLD_LAYER(KC_BSLS, MAC_FN_RBSL_HOLD),
  [WIN_TD_RALT]     = ACTION_TAP_DANCE_TAP_LAYER_HOLD_LAYER(WIN_FN_RALT_TAP, WIN_FN_RALT_HOLD),
};





const uint16_t PROGMEM keymaps[32][MATRIX_ROWS][MATRIX_COLS] = {

    [MAC_BASE] = FULLLAYOUT_WITH_FUNCTIONKEY(
        KC_ESC,  C(KC_F1),  C(KC_F2),  C(KC_F3),  C(KC_F4),  G(KC_R),C(KC_DOWN),KC_MISSION_CONTROL,KC_LAUNCHPAD,  KC_VOLD,KC_VOLU,C(KC_LEFT),C(KC_RIGHT), LCTL(KC_Y), KC_PSCR,KC_SLCK,KC_PAUS, 
        MAC_BASE_KEYS),
    [WIN_BASE] = FULLLAYOUT_WITH_FUNCTIONKEY(
        KC_ESC,  C(S(KC_TAB)),C(KC_TAB),C(A(KC_TAB)),KC_LWIN,  C(KC_R),G(KC_D),KC_MNXT,KC_MUTE, KC_VOLD,KC_VOLU,C(G(KC_LEFT)),C(G(KC_RGHT)), KC_NO, KC_PSCR,KC_SLCK,KC_PAUS,
        WIN_BASE_KEYS),
    [WIN_FOR_REMOTE] = FULLLAYOUT_WITH_FUNCTIONKEY(
        KC_ESC,  C(S(KC_TAB)),C(KC_TAB),C(A(KC_TAB)),KC_LWIN,  C(KC_R),G(KC_D),KC_MNXT,KC_MUTE, KC_VOLD,KC_VOLU,C(G(KC_LEFT)),C(G(KC_RGHT)), KC_NO, KC_PSCR,KC_SLCK,KC_PAUS,
        WIN_BASE_REMOTE_KEYS),


    [MAC_FN_MAIN] = LAYOUT_ansi(
        LCMD(KC_Q),   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10,  KC_F11,   KC_F12,  KC_NO, KC_NO,  KC_NO,  KC_NO,
        KC_NO, LCMD(KC_1), LCMD(KC_2),  LCMD(KC_3), LCMD(KC_4), LCMD(KC_5),  KC_NO,  KC_NO,  KC_NO,  KC_BSPC,  KC_DEL,  KC_NO,  KC_NO,   KC_BSPC,  KC_NO,  KC_NO,  KC_NO,
        LCMD(KC_GRV), LCTL(KC_Y),  LCMD(KC_W),  LCMD(KC_D),  LCMD(KC_F), LCMD(KC_P), KC_NO,  KC_HOME,  KC_UP,  KC_END,  KC_PGUP,  KC_NO,   KC_NO,  KC_NO,  LCTL(LALT(KC_DEL)),  KC_NO,  KC_NO,
        LCMD(LSFT(KC_GRV)),   LCMD(KC_A),  LCMD(KC_R),  LCMD(KC_S),  LCMD(KC_T),  LCMD(KC_G),  KC_ENT,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_PGDN,     KC_ENT,  LCMD(KC_ENT),
        KC_LSFT,            LCMD(KC_Z),  LCMD(KC_X),  LCMD(KC_C),  LCMD(KC_V),  LCMD(KC_B),  LOPT(KC_LEFT),  LOPT(KC_LEFT),  KC_NO, LOPT(KC_RGHT),  LOPT(KC_RGHT),               KC_RSFT,            KC_NO,
        KC_LCTL,  KC_LCMD,  MO(MAC_FN_MAIN),                                LCMD(KC_SPC),                                KC_NO,  MO(NumberSwitchLayer), KC_NO,  KC_NO,  KC_NO,  KC_NO),

    [MAC_FN_APPS] = LAYOUT_ansi(
        KC_ESC,          KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, KC_NO,  KC_NO,  KC_VOLD,    KC_VOLU, KC_NO,         KC_NO,  KC_NO,  KC_NO,
        KC_NO,  C(KC_LEFT), C(KC_RIGHT),  KC_NO,  KC_NO, KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  C(KC_F3),  C(KC_F4),   KC_NO,                     KC_NO,  KC_NO,  KC_NO,
        KC_NO,  KC_NO, C(S(KC_TAB)),  KC_UP,  C(KC_TAB), KC_NO,  KC_NO,  KC_NO,  KC_NO,  C(KC_F1),  C(KC_F2),  C(KC_F3),  C(KC_F4),   MO(MAC_FN_APPS),         KC_NO,  KC_NO,  KC_NO,
        KC_ENT,  KC_NO, KC_LEFT,  KC_DOWN,  KC_RIGHT,  KC_ENT,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,             KC_NO,
        KC_NO,          C(KC_F4),  C(KC_F3),  C(KC_F2),  C(KC_F1),  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,            KC_NO,            KC_NO,
        KC_NO,  KC_NO,  KC_NO,                                KC_0,                                KC_NO,  MO(NumberSwitchLayer), KC_NO,     KC_NO,  KC_NO,  KC_NO),

    [WIN_FN_MAIN] = LAYOUT_ansi(
        LALT(KC_F4),            KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10,  KC_F11,   KC_F12,  KC_NO, KC_NO,  KC_NO,  KC_NO,
        LALT(KC_GRV),  LWIN(KC_1), LWIN(KC_2),  LWIN(KC_3),  LWIN(KC_4),  LWIN(KC_5),  KC_NO,  KC_NO,  KC_NO,  KC_BSPC,  KC_DEL,  KC_NO,  KC_NO,   KC_BSPC,  KC_NO,  KC_NO,  KC_NO,
        LALT(KC_TAB),LCTL(KC_Q), LCTL(KC_W),  LCTL(KC_D),  LCTL(KC_F),  LCTL(KC_P), KC_NO,  KC_HOME,  KC_UP,  KC_END,  KC_PGUP,  KC_DEL,  KC_NO,   KC_NO,  LCTL(LALT(KC_DEL)),  KC_NO,  KC_NO,
        KC_RCTL,  LCTL(KC_A), LCTL(KC_R),  LCTL(KC_S),  LCTL(KC_T),    LCTL(KC_G),  KC_ENT,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_PGDN, KC_ENT, LCTL(KC_ENT), 
        KC_LSFT,            LCTL(KC_Z),  LCTL(KC_X),  LCTL(KC_C),  LCTL(KC_V),  LCTL(KC_B),  LCTL(KC_LEFT),  LCTL(KC_LEFT),  KC_NO, LCTL(KC_RGHT),  LCTL(KC_RGHT),    KC_RSFT,            KC_NO,
        KC_LCTL,  KC_LALT,  MO(WIN_FN_MAIN),                                A(KC_SPC),                                KC_NO,  MO(NumberSwitchLayer), KC_NO,   KC_NO,  KC_NO,  KC_NO),

    [BOTH_FN_SPEC_CHAR] = LAYOUT_ansi(
        KC_GRV,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
        KC_GRV,LSFT(KC_1),LSFT(KC_2),LSFT(KC_3),LSFT(KC_4),LSFT(KC_5),LSFT(KC_6),LSFT(KC_7),KC_MULTEQL,KC_MINUSEQL,KC_PLUSEQL,KC_NO,KC_NO,KC_BSPC,KC_NO,KC_NO,KC_NO,
        KC_NO,KC_BSPC,LSFT(KC_LBRC),KC_LBRC,LSFT(KC_9),LSFT(KC_6),KC_NO,LSFT(KC_0),KC_RBRC,LSFT(KC_RBRC),KC_SLSH,LSFT(KC_BSLS),LSFT(KC_BSLS),KC_BSLS,KC_NO,KC_NO,KC_NO,
        KC_NO,LSFT(KC_BSLS),KC_BSLS,KC_SCLN,LSFT(KC_SCLN),KC_NO,KC_NO,LSFT(KC_MINUS),KC_EQL,KC_QUOT,LSFT(KC_QUOT),KC_NO,KC_ENT,
        KC_NO,KC_NO,KC_NO,KC_SLSH,LSFT(KC_8),KC_NO,LSFT(KC_EQL),KC_MINUS,KC_LEQ,KC_GEQ,KC_DIVEQL,KC_RSFT,KC_NO,
        KC_NO,KC_NO,KC_NO,KC_SPC,KC_NO,MO(NumberSwitchLayer),KC_NO,KC_NO,KC_NO,KC_NO),


    [MAC_FN_CAPLOCK]=MAP_LAYOUT_TO_MAC_CAP(COLEMAK_MAC_BASE_KEYS),
    [WIN_FN_CAPLOCK]=MAP_LAYOUT_TO_WIN_CAP(COLEMAK_WIN_BASE_KEYS),

    [GameLayer] = MAP_KEYS_TO_VALID_LAYOUT(GAME_TOTAL_KEYS),
    [NormalMac] = MAP_KEYS_TO_VALID_LAYOUT(NORMAL_MAC_TOTAL_KEYS),
    [NormalWin] = MAP_KEYS_TO_VALID_LAYOUT(NORMAL_WIN_TOTAL_KEYS),
    [NormalWin_ForMacUser] = MAP_KEYS_TO_VALID_LAYOUT(NORMAL_WIN_FOR_MAC_TOTAL_KEYS),
    [NumberSwitchLayer] = MAP_KEYS_TO_VALID_LAYOUT(SWITCH_LAYER_TOTAL_KEYS),
};


#define MOD_MASK_ALT_SHFT_CTRL (MOD_MASK_SHIFT | MOD_MASK_ALT | MOD_MASK_CTRL)
bool grv_or_esc = false;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_MISSION_CONTROL:
            if (record->event.pressed) {
                host_consumer_send(0x29F);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        case KC_LAUNCHPAD:
            if (record->event.pressed) {
                host_consumer_send(0x2A0);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        case KC_ESC_MOD:
            if (record->event.pressed){
                uint8_t mod = get_mods();
                if(mod & MOD_MASK_ALT_SHFT_CTRL){
                    grv_or_esc = true;
                    register_code(KC_GRV);
                } else {
                    grv_or_esc = false;
                    register_code(KC_ESC);
                }
            }
            else{
                if (grv_or_esc){
                    unregister_code(KC_GRV);
                } else {
                    unregister_code(KC_ESC);
                }
            }
            return false;
        case KC_GEQ:
            if (record->event.pressed){
                send_string(">=");
            }
            return false;
        case KC_LEQ:
            if (record->event.pressed){
                send_string("<=");
            }
            return false;
        case KC_PLUSEQL:
            if (record->event.pressed){
                send_string("+=");
            }
            return false;
        case KC_MINUSEQL:
            if (record->event.pressed){
                send_string("-=");
            }
            return false;
        case KC_MULTEQL:
            if (record->event.pressed){
                send_string("*=");
            }
            return false;
        case KC_DIVEQL:
            if (record->event.pressed){
                send_string("/=");
            }
            return false;
        default:
            return true;
    }
}