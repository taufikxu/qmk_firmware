#include QMK_KEYBOARD_H


enum layers{
    MAC_BASE=0,
    WIN_BASE,


    MAC_FN_MAIN,
    WIN_FOR_REMOTE,
    MAC_FN_CAPLOCK,

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



#define MAC_FN_LCAP_HOLD MAC_FN_CAPLOCK
#define MAC_FN_LCAP_TAP -1

#define MAC_FN_LCMD_HOLD MAC_FN_MAIN
#define MAC_FN_LCMD_TAP -1
#define MAC_FN_LSFT_TAP BOTH_FN_SPEC_CHAR

#define MAC_FN_RSFT_TAP BOTH_FN_SPEC_CHAR
#define MAC_FN_RSFT_HOLD BOTH_FN_SPEC_CHAR
#define MAC_FN_RBSL_HOLD -1

#define MAC_FN_RCMD_TAP -1
#define MAC_FN_RCMD_HOLD -1


#define WIN_FN_LCAP_HOLD WIN_FN_CAPLOCK
#define WIN_FN_LCAP_TAP -1

#define WIN_FN_LALT_HOLD WIN_FN_MAIN
#define WIN_FN_LALT_TAP -1
#define WIN_FN_LSFT_TAP BOTH_FN_SPEC_CHAR

#define WIN_FN_RSFT_TAP BOTH_FN_SPEC_CHAR
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
  [WIN_TD_RSFT]     = ACTION_TAP_DANCE_TAP_LAYER_HOLD_LAYER(WIN_FN_RSFT_TAP, WIN_FN_RSFT_HOLD),
  [WIN_TD_RBSL]     = ACTION_TAP_DANCE_TAP_KEY_HOLD_LAYER(KC_BSLS, WIN_FN_RBSL_HOLD),
  [MAC_TD_RCMD]     = ACTION_TAP_DANCE_TAP_LAYER_HOLD_LAYER(MAC_FN_RCMD_TAP, MAC_FN_RCMD_HOLD),

  [MAC_TD_LCMD]     = ACTION_TAP_DANCE_TAP_LAYER_HOLD_LAYER(MAC_FN_LCMD_TAP, MAC_FN_LCMD_HOLD),
  [MAC_TD_LSFT]     = ACTION_TAP_DANCE_TAP_LAYER_HOLD_KEY(MAC_FN_LSFT_TAP, KC_LSFT),
  [MAC_TD_LCAP]     = ACTION_TAP_DANCE_TAP_LAYER_HOLD_LAYER(MAC_FN_LCAP_TAP, MAC_FN_LCAP_HOLD),
  [MAC_TD_RSFT]     = ACTION_TAP_DANCE_TAP_LAYER_HOLD_LAYER(MAC_FN_RSFT_TAP, MAC_FN_RSFT_HOLD),
  [MAC_TD_RBSL]     = ACTION_TAP_DANCE_TAP_KEY_HOLD_LAYER(KC_BSLS, MAC_FN_RBSL_HOLD),
  [WIN_TD_RALT]     = ACTION_TAP_DANCE_TAP_LAYER_HOLD_LAYER(WIN_FN_RALT_TAP, WIN_FN_RALT_HOLD),
};





const uint16_t PROGMEM keymaps[32][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi(
        KC_ESC,             C(KC_PGUP),C(KC_PGDN),  KC_MCTL,  KC_LPAD,  G(KC_R),    G(KC_D),    C(KC_LEFT),    C(KC_RGHT),  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU, DF(WIN_BASE), KC_PSCR,  KC_SLCK,  KC_PAUS,
        KC_ESC_MOD,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,    KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_D,     KC_F,     KC_P,     KC_J,     KC_L,     KC_U,     KC_Y,     KC_SCLN,  KC_LBRC,  KC_RBRC,   TD(MAC_TD_RBSL),  KC_DEL,   KC_END,   KC_PGDN,
        TD(MAC_TD_LCAP),  KC_A,     KC_R,     KC_S,     KC_T,     KC_G,     KC_K,     KC_N,     KC_E,     KC_I,     KC_O,     KC_QUOT,             KC_ENT,
        TD(MAC_TD_LSFT),            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_H,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              TD(MAC_TD_RSFT),            KC_UP,
        KC_LCTL,  KC_LOPT, TD(MAC_TD_LCMD),                               KC_SPC,                                 TD(MAC_TD_RCMD), MO(NumberSwitchLayer), KC_RCMD,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAC_FN_MAIN] = LAYOUT_ansi(
        LCMD(KC_Q),            KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10,  KC_F11,   KC_F12,  KC_NO, KC_NO,  KC_NO,  KC_NO,
        LCMD(KC_GRV),  KC_NO, KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_BSPC,  KC_NO,  KC_NO,  KC_NO,
        LCMD(KC_TAB), LCTL(KC_Q),  LCMD(KC_W),  LCMD(KC_D),  LCMD(KC_F), LCMD(KC_P), KC_PGUP,  LCMD(KC_LEFT),  KC_UP,  LCMD(KC_RIGHT),  KC_BSPC,  KC_DEL,   KC_NO,  KC_NO,  LCTL(LALT(KC_DEL)),  KC_NO,  KC_NO,
        KC_RCTL,   LCMD(KC_A),  LCMD(KC_R),  LCMD(KC_S),  LCMD(KC_T),  KC_ENT,  KC_PGDN,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_NO,     KC_ENT,  LCMD(KC_ENT),
        KC_LSFT,            LCMD(KC_Z),  LCMD(KC_X),  LCMD(KC_C),  LCMD(KC_V),  LCMD(KC_B),  LOPT(KC_LEFT),  LOPT(KC_LEFT),  KC_NO, LOPT(KC_RGHT),  LOPT(KC_RGHT),               KC_RSFT,            KC_NO,
        KC_LCTL,  KC_LCMD,  MO(MAC_FN_MAIN),                                LCMD(KC_SPC),                                KC_NO,  MO(NumberSwitchLayer), KC_NO,  KC_NO,  KC_NO,  KC_NO),

    [MAC_FN_CAPLOCK]=LAYOUT_ansi(
        LCMD(KC_ESC),LCMD(KC_F1),LCMD(KC_F2),LCMD(KC_F3),LCMD(KC_F4),LCMD(KC_F5),LCMD(KC_F6),LCMD(KC_F7),LCMD(KC_F8),LCMD(KC_F9),LCMD(KC_F10),LCMD(KC_F11),LCMD(KC_F12),KC_NO,LCMD(KC_PSCR),LCMD(KC_SLCK),LCMD(KC_PAUS),
        LCMD(KC_GRV),LCMD(KC_1),LCMD(KC_2),LCMD(KC_3),LCMD(KC_4),LCMD(KC_5),LCMD(KC_6),LCMD(KC_7),LCMD(KC_8),LCMD(KC_9),LCMD(KC_0),LCMD(KC_MINS),LCMD(KC_EQL),LCMD(KC_BSPC),LCMD(KC_INS),LCMD(KC_HOME),LCMD(KC_PGUP),
        LCTL(KC_TAB),LCTL(KC_Q),LCMD(KC_W),LCMD(KC_D),LCMD(KC_F),LCMD(KC_P),LCMD(KC_J),LCMD(KC_L),LCMD(KC_U),LCMD(KC_Y),LCMD(KC_SCLN),LCMD(KC_LBRC),LCMD(KC_RBRC),LCMD(KC_BSLS),LCMD(KC_DEL),LCMD(KC_END),LCMD(KC_PGDN),
        MO(MAC_FN_CAPLOCK),LCMD(KC_A),LCMD(KC_R),LCMD(KC_S),LCMD(KC_T),LCMD(KC_G),LCMD(KC_K),LCMD(KC_N),LCMD(KC_E),LCMD(KC_I),LCMD(KC_O),LCMD(KC_QUOT),LCMD(KC_ENT),
        KC_LSFT,LCMD(KC_Z),LCMD(KC_X),LCMD(KC_C),LCMD(KC_V),LCMD(KC_B),LCMD(KC_H),LCMD(KC_M),LCMD(KC_COMM),LCMD(KC_DOT),LCMD(KC_SLSH),KC_RSFT,LCMD(KC_UP),
        KC_LCTL,KC_LOPT,KC_LCMD,LCMD(KC_SPC),KC_RCMD,MO(NumberSwitchLayer),KC_ROPT,LCMD(KC_LEFT),LCMD(KC_DOWN),LCMD(KC_RGHT)),

    [WIN_BASE] = LAYOUT_ansi(
        KC_ESC,             C(KC_PGUP),C(KC_PGDN),C(A(KC_TAB)),KC_LWIN,C(KC_R),G(KC_D),C(G(KC_LEFT)),C(G(KC_RGHT)),   KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU, KC_NO, KC_PSCR, KC_SLCK,  KC_PAUS,
        KC_ESC_MOD,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,    KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_D,     KC_F,     KC_P,     KC_J,     KC_L,     KC_U,     KC_Y,     KC_SCLN,  KC_LBRC,  KC_RBRC, TD(WIN_TD_RBSL),  KC_DEL,   KC_END,   KC_PGDN,
        TD(WIN_TD_LCAP),  KC_A,     KC_R,     KC_S,     KC_T,     KC_G,     KC_K,     KC_N,     KC_E,     KC_I,     KC_O,     KC_QUOT,             KC_ENT,
        TD(WIN_TD_LSFT),            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_H,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,   TD(WIN_TD_RSFT),            KC_UP,
        KC_LCTL ,KC_LWIN, TD(WIN_TD_LALT),                                KC_SPC,                    TD(WIN_TD_RALT),  MO(NumberSwitchLayer), KC_RALT,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FOR_REMOTE] = LAYOUT_ansi(
        KC_ESC,             C(KC_PGUP),C(KC_PGDN),C(A(KC_TAB)),KC_LWIN,C(KC_R),G(KC_D),C(G(KC_LEFT)),C(G(KC_RGHT)),   KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU, KC_NO, KC_PSCR, KC_SLCK,  KC_PAUS,
        KC_ESC_MOD,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,    KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_D,     KC_F,     KC_P,     KC_J,     KC_L,     KC_U,     KC_Y,     KC_SCLN,  KC_LBRC,  KC_RBRC, TD(WIN_TD_RBSL),  KC_DEL,   KC_END,   KC_PGDN,
        MO(WIN_FN_LCAP_HOLD),  KC_A,     KC_R,     KC_S,     KC_T,     KC_G,     KC_K,     KC_N,     KC_E,     KC_I,     KC_O,     KC_QUOT,             KC_ENT,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_H,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,   TD(WIN_TD_RSFT),            KC_UP,
        KC_LCTL ,KC_LWIN, TD(WIN_TD_LALT),                                KC_SPC,                    TD(WIN_TD_RALT),  MO(NumberSwitchLayer), KC_RALT,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN_MAIN] = LAYOUT_ansi(
        LALT(KC_F4),            KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10,  KC_F11,   KC_F12,  KC_NO, KC_NO,  KC_NO,  KC_NO,
        LALT(KC_GRV),  LWIN(KC_1), LWIN(KC_2),  LWIN(KC_3),  LWIN(KC_4),  LWIN(KC_5),  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_BSPC,  KC_NO,  KC_NO,  KC_NO,
        LALT(KC_TAB),LCTL(KC_Q), LCTL(KC_W),  LCTL(KC_D),  LCTL(KC_F),  LCTL(KC_P), KC_PGUP,  KC_HOME,  KC_UP,  KC_END,  KC_BSPC,  KC_DEL,  KC_NO,   KC_NO,  LCTL(LALT(KC_DEL)),  KC_NO,  KC_NO,
        KC_RCTL,  LCTL(KC_A), LCTL(KC_R),  LCTL(KC_S),  LCTL(KC_T),    KC_ENT,  KC_PGDN,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_NO, KC_ENT, LCTL(KC_ENT), 
        KC_LSFT,            LCTL(KC_Z),  LCTL(KC_X),  LCTL(KC_C),  LCTL(KC_V),  LCTL(KC_B),  LCTL(KC_LEFT),  LCTL(KC_LEFT),  KC_NO, LCTL(KC_RGHT),  LCTL(KC_RGHT),    KC_RSFT,            KC_NO,
        KC_LCTL,  KC_LALT,  MO(WIN_FN_MAIN),                                A(KC_SPC),                                KC_NO,  MO(NumberSwitchLayer), KC_NO,   KC_NO,  KC_NO,  KC_NO),

    [WIN_FN_CAPLOCK]=LAYOUT_ansi(
        LCTL(KC_ESC),LCTL(KC_F1),LCTL(KC_F2),LCTL(KC_F3),LCTL(KC_F4),LCTL(KC_F5),LCTL(KC_F6),LCTL(KC_F7),LCTL(KC_F8),LCTL(KC_F9),LCTL(KC_F10),LCTL(KC_F11),LCTL(KC_F12),KC_NO,LCTL(KC_PSCR),LCTL(KC_SLCK),LCTL(KC_PAUS),
        LCTL(KC_GRV),LCTL(KC_1),LCTL(KC_2),LCTL(KC_3),LCTL(KC_4),LCTL(KC_5),LCTL(KC_6),LCTL(KC_7),LCTL(KC_8),LCTL(KC_9),LCTL(KC_0),LCTL(KC_MINS),LCTL(KC_EQL),LCTL(KC_BSPC),LCTL(KC_INS),LCTL(KC_HOME),LCTL(KC_PGUP),
        LCTL(KC_TAB),LCTL(KC_Q),LCTL(KC_W),LCTL(KC_D),LCTL(KC_F),LCTL(KC_P),LCTL(KC_J),LCTL(KC_L),LCTL(KC_U),LCTL(KC_Y),LCTL(KC_SCLN),LCTL(KC_LBRC),LCTL(KC_RBRC),LCTL(KC_BSLS),LCTL(KC_DEL),LCTL(KC_END),LCTL(KC_PGDN),
        MO(WIN_FN_CAPLOCK),LCTL(KC_A),LCTL(KC_R),LCTL(KC_S),LCTL(KC_T),LCTL(KC_G),LCTL(KC_K),LCTL(KC_N),LCTL(KC_E),LCTL(KC_I),LCTL(KC_O),LCTL(KC_QUOT),LCTL(KC_ENT),
        KC_LSFT,LCTL(KC_Z),LCTL(KC_X),LCTL(KC_C),LCTL(KC_V),LCTL(KC_B),LCTL(KC_H),LCTL(KC_M),LCTL(KC_COMM),LCTL(KC_DOT),LCTL(KC_SLSH),KC_RSFT,LCTL(KC_UP),
        KC_LCTL,KC_LWIN,KC_LALT,LCTL(KC_SPC),KC_RALT,MO(NumberSwitchLayer),KC_RWIN,LCTL(KC_LEFT),LCTL(KC_DOWN),LCTL(KC_RGHT)),


    [BOTH_FN_SPEC_CHAR] = LAYOUT_ansi(
        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_NO,  KC_NO,  KC_NO,  KC_NO, KC_NO,
        KC_GRV,  LSFT(KC_1), LSFT(KC_2),  LSFT(KC_3),  LSFT(KC_4),  LSFT(KC_5),  LSFT(KC_6),  LSFT(KC_7),  KC_MULTEQL,  KC_MINUSEQL,  KC_PLUSEQL,  KC_NO,  KC_NO,   KC_BSPC,  KC_NO,  KC_NO,  KC_NO,
        KC_ESC_MOD,  KC_BSPC, LSFT(KC_LBRC),  KC_LBRC,  LSFT(KC_9),  LSFT(KC_6), KC_NO,  LSFT(KC_0),  KC_RBRC, LSFT(KC_RBRC),  KC_BSLS,  LSFT(KC_BSLS),  KC_SLSH,   KC_NO,  KC_NO,  KC_NO,  KC_NO,
        KC_NO,  KC_NO, KC_NO,  KC_SCLN,    LSFT(KC_SCLN), KC_NO, KC_NO,   LSFT(KC_MINUS),  KC_EQL,  KC_QUOT, LSFT(KC_QUOT), KC_NO, KC_ENT,
        KC_NO,            KC_NO,  KC_NO,  KC_SLSH,  LSFT(KC_8),  KC_NO,  LSFT(KC_EQL),  KC_MINUS,  KC_LEQ,  KC_GEQ,  KC_DIVEQL,  KC_RSFT,            KC_NO,
        KC_NO,  KC_NO,  KC_NO,                               KC_SPC,                                KC_NO,  MO(NumberSwitchLayer), KC_NO,   KC_NO,  KC_NO,  KC_NO),

    [GameLayer] = LAYOUT_ansi(
        KC_ESC,             KC_F1,   KC_F2,    KC_F3,    KC_F4,  KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,    KC_F12,  KC_NO, KC_PSCR,   KC_G,  KC_PAUS,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,    KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_D,     KC_F,     KC_P,     KC_J,     KC_L,     KC_U,     KC_Y,     KC_SCLN,     KC_LBRC,  KC_RBRC,   KC_BSLS,  KC_DEL,   KC_END,   KC_PGDN,
        KC_CAPS,  KC_A,     KC_R,     KC_S,     KC_T,     KC_G,     KC_K,     KC_N,     KC_E,     KC_I,     KC_O,  KC_QUOT,             KC_ENT,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_H,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,             KC_RSFT,            KC_UP,
        KC_LCTL,  KC_LWIN, KC_LALT,                               KC_SPC,                                 KC_RALT, MO(NumberSwitchLayer), KC_RWIN,  KC_LEFT,  KC_DOWN,  KC_RGHT),
    
    [NormalMac] = LAYOUT_ansi(
        KC_ESC,             KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,   KC_VOLU, KC_NO, KC_PSCR,  KC_M,  KC_PAUS,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,    KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,   KC_BSLS,  KC_DEL,   KC_END,   KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,             KC_ENT,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,             KC_RSFT,            KC_UP,
        KC_LCTL,  KC_LOPT, KC_LCMD,                               KC_SPC,                                 KC_RCMD, MO(NumberSwitchLayer),KC_ROPT,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [NormalWin] = LAYOUT_ansi(
        KC_ESC,             KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,    KC_F12, KC_NO,  KC_PSCR,  KC_W,  KC_PAUS,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,    KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,   KC_BSLS,  KC_DEL,   KC_END,   KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,             KC_ENT,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,             KC_RSFT,            KC_UP,
        KC_LCTL,  KC_LCMD,  KC_LALT,                                KC_SPC,                                 KC_RALT,  MO(NumberSwitchLayer), KC_RWIN,   KC_LEFT,  KC_DOWN,  KC_RGHT),

    [NormalWin_ForMacUser] = LAYOUT_ansi(
        KC_ESC,             KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,    KC_F12, KC_NO,  KC_PSCR,  KC_W,  KC_PAUS,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,    KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,   KC_BSLS,  KC_DEL,   KC_END,   KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,             KC_ENT,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,             KC_RSFT,            KC_UP,
        KC_LALT,  KC_LCMD,  KC_LCTL,                                KC_SPC,                                 KC_RALT,  MO(NumberSwitchLayer), KC_RWIN,   KC_LEFT,  KC_DOWN,  KC_RGHT),

    [NumberSwitchLayer] = LAYOUT_ansi(
        KC_ESC,          KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, KC_NO,  KC_NO,  KC_VOLD,    KC_VOLU, KC_NO, KC_NO,  KC_NO,  RGB_TOG,
        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,   DF(WIN_FOR_REMOTE),  DF(MAC_BASE),  DF(GameLayer),  DF(NormalMac),
        KC_NO,  KC_1,  KC_2,  KC_3,  KC_PLUS,  KC_MINUS,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_NO,  DF(WIN_BASE),  DF(NormalWin_ForMacUser),  DF(NormalWin),
        KC_NO,  KC_4,  KC_5,  KC_6,  KC_ASTR,  KC_SLSH,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,             KC_NO,
        KC_NO,          KC_7,  KC_8,  KC_9,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,            KC_NO,            KC_NO,
        KC_NO,  KC_NO,  KC_NO,                                KC_0,                                KC_NO,  MO(NumberSwitchLayer), KC_NO,     KC_NO,  KC_NO,  KC_NO),
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