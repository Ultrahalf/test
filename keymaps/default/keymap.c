#include QMK_KEYBOARD_H
#include "features/caps_word.h"

enum layers {
    BASE,
    NUM,
    SYM,
    FUN,
    MEDIA,
    NAV,
    MOUSE,
    QWERTY,
};

// Left-hand home row mods
#define MT_A LALT_T(KC_A)
#define MT_R LGUI_T(KC_R)
#define MT_S LCTL_T(KC_S)
#define MT_T LSFT_T(KC_T)

// Right-hand home row mods
#define MT_N RSFT_T(KC_N)
#define MT_E RCTL_T(KC_E)
#define MT_I RGUI_T(KC_I)
#define MT_O LALT_T(KC_O)

// Left-hand home row mods qwerty
#define QMT_A LALT_T(KC_A)
#define QMT_S LGUI_T(KC_S)
#define QMT_D LCTL_T(KC_D)
#define QMT_F LSFT_T(KC_F)

// Right-hand home row mods qwerty
#define QMT_J RSFT_T(KC_J)
#define QMT_K RCTL_T(KC_K)
#define QMT_L RGUI_T(KC_L)
#define QMT_SCLN LALT_T(KC_SCLN)

// thumbs
#define LT_MD LT(MEDIA, KC_ESC)
#define LT_NV LT(NAV, KC_SPC)
#define LT_MS LT(MOUSE, KC_TAB)
#define LT_SM LT(SYM, KC_ENT)
#define LT_NM LT(NUM, KC_BSPC)
#define LT_FN LT(FUN, KC_DEL)

// shortcuts
#define RDO KC_AGIN
#define PST S(KC_INS)
#define CPY C(KC_INS)
#define CUT S(KC_DEL)
#define UND KC_UNDO

#define BBACK A(KC_LEFT)
#define BFORW A(KC_RGHT)

enum custom_keycodes {
    UPDIR = SAFE_RANGE,
    EQ3X,
    DEQ,
    GTEQ,
    LTEQ,
    QUOT3X,
    BTK3X,
    AFUNC,
    ARROW,
    SCOPE,
    COLEQ,
    // frequently typed
    MAIL,
    // unicode
    U_GR,
    U_TB,
    U_HR,
    U_SM,
    U_SB,
    U_FP,
    U_TH,
    U_AW,
    U_EY,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [BASE] = LAYOUT_split_3x5_3(
    // KC_Q, KC_W, KC_F, KC_P, KC_B,       KC_J, KC_L, KC_U, KC_Y, KC_QUOT,
    QK_BOOTLOADER, KC_W, KC_F, KC_P, KC_B,       KC_J, KC_L, KC_U, KC_Y, KC_QUOT,
    MT_A, MT_R, MT_S, MT_T, KC_G,       KC_M, MT_N, MT_E, MT_I, MT_O, 
    KC_Z, KC_X, KC_C, KC_D, KC_V,       KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, 
    LT_MD, LT_NV, LT_MS,                LT_SM, LT_NM, LT_FN
    ),

    [NUM] = LAYOUT_split_3x5_3(
    KC_LBRC, KC_7, KC_8, KC_9, KC_RBRC,       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_SCLN, KC_4, KC_5, KC_6, KC_EQL,        KC_NO, MAIL, KC_NO, KC_NO, KC_NO,
    KC_GRV, KC_1, KC_2, KC_3, KC_NUBS,        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
    KC_DOT,  KC_0,    KC_MINS,                KC_NO, KC_NO, KC_NO
    ),

    [SYM] = LAYOUT_split_3x5_3(
    KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,       GTEQ, DEQ, UPDIR, KC_NO, KC_NO,
    KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,       ARROW, AFUNC, EQ3X, SCOPE, KC_NO,
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE,       LTEQ, BTK3X, QUOT3X, KC_NO, KC_NO, 
    KC_LPRN, KC_RPRN, KC_UNDS,                         KC_NO, KC_NO, KC_NO
    ),

    [FUN] = LAYOUT_split_3x5_3(
    KC_F12, KC_F7, KC_F8, KC_F9, KC_PSCR,       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_F11, KC_F4, KC_F5, KC_F6, KC_SLCK,       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_F10, KC_F1, KC_F2, KC_F3, KC_PAUS,       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
    KC_NO,  KC_NO, KC_NO,                       KC_NO, KC_NO, KC_NO
    ),

    [MEDIA] = LAYOUT_split_3x5_3(
    KC_NO, KC_NO, KC_NO, KC_NO, U_EY,         KC_NO, KC_BRID, KC_BRIU, KC_NO, KC_NO,
    KC_NO, U_AW, U_TH, U_FP, U_SB,             KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,       U_SM, U_TB, U_HR, U_GR, KC_NO,
    KC_NO,  KC_NO, KC_NO,                    KC_MSTP, KC_MPLY, KC_MUTE
    ),

    [NAV] = LAYOUT_split_3x5_3(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,       KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_INS, 
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,       KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_CAPS,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,       RDO, PST, CPY, CUT, UND, 
    KC_NO,  KC_NO, KC_NO,                    BBACK, BFORW,TG(QWERTY)
    ),

    [MOUSE] = LAYOUT_split_3x5_3(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,       KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,       KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_NO,
    KC_NO,  KC_NO, KC_NO,                    KC_BTN1, KC_BTN3, KC_BTN2
    ),

    [QWERTY] = LAYOUT_split_3x5_3(
    KC_Q, KC_W, KC_E, KC_R, KC_T,       KC_Y, KC_U, KC_I, KC_O, KC_P,
    QMT_A, QMT_S, QMT_D, QMT_F, KC_G,       KC_H, QMT_J, QMT_K, QMT_L, QMT_SCLN, 
    KC_Z, KC_X, KC_C, KC_V, KC_B,       KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, 
    LT_MD,  LT_NV, LT_MS,               LT_SM, LT_NM, LT_FN
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_caps_word(keycode, record)) { return false; }
    switch (keycode) {
        case UPDIR:  // Types ../ to go up a directory on the shell.
            if (record->event.pressed) {
                SEND_STRING("../");
            }
            return false;

        case EQ3X:  // Types triple equal ===
            if (record->event.pressed) {
                SEND_STRING("===");
            }
            return false;

        case AFUNC:
            if (record->event.pressed) {
                SEND_STRING("=>");
            }
            return false;

        case MAIL:
            if (record->event.pressed) {
                SEND_STRING("muhammadalthafrahman@gmail.com");
            }
            return false;

        case DEQ:
            if (record->event.pressed) {
                SEND_STRING("==");
            }
            return false;

        case QUOT3X:
            if (record->event.pressed) {
                SEND_STRING("'''");
            }
            return false;

        case BTK3X:
            if (record->event.pressed) {
                SEND_STRING("```");
            }
            return false;


        case ARROW:
            if (record->event.pressed) {
                SEND_STRING("->");
            }
            return false;

        case SCOPE:
            if (record->event.pressed) {
                SEND_STRING("::");
            }
            return false;

        case COLEQ:
            if (record->event.pressed) {
                SEND_STRING(":=");
            }
            return false;


        case U_GR:
            if (record->event.pressed) {
                send_unicode_string("1f605");
            }
            return false;

        case U_TB:
            if (record->event.pressed) {
                send_unicode_string("1f44d");
            }
            return false;

        case U_HR:
            if (record->event.pressed) {
                send_unicode_string("1f5a4");
            }
            return false;

        case U_SM:
            if (record->event.pressed) {
                send_unicode_string("1f602");
            }
            return false;

        case U_SB:
            if (record->event.pressed) {
                send_unicode_string("1f62d");
            }
            return false;

        case U_AW:
            if (record->event.pressed) {
                send_unicode_string("1f44c");
            }
            return false;

        case U_FP:
            if (record->event.pressed) {
                send_unicode_string("1f926");
            }
            return false;

        case U_EY:
            if (record->event.pressed) {
                send_unicode_string("1f440");
            }
            return false;

        case U_TH:
            if (record->event.pressed) {
                send_unicode_string("1f928");
            }
            return false;

    }
    return true;
}
