// Copyright 2012 Jun Wako <wakojun@gmail.com>
// Copyright 2021 Dmitriy Kuminov (@dmik)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _EXTRA,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define EXTRA MO(_EXTRA)

/* Keymap 0: Base
 * ,-------------------------------------------.           ,-------------------------------------------.
 * |   F1   |  F2  |  F3  |  F4  |  F5  |  F6  |           |   F7 |   F8 |  F9 |  F10 |  F11  |   F12  |
 * |--------+------+------+------+------+------|           |------+------+------+------+------+--------|
 * |   V1   |   1  |   2  |   3  |   4  |   5  |           |   6  |   7  |   8  |   9  |   0  |  DEL   |
 * |--------+------+------+------+------+------|           |------+------+------+------+------+--------|
 * |   V2   |   Q  | W    |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |  PUp   |
 * |--------+------+------+------+------+------|           |------+------+------+------+------+--------|
 * |   V3   |   A  |   S  |   D  |   F  |   G  |           |   H  | J    | K    |   L  |   ;  |  PDown |
 * |--------+------+------+------+------+------|           |------+------+------+------+------+--------|
 * |   V4   |G +  Z|A + X|C + C  |S + V |   B  |           |   N  |S + M | C + ,|A + . |G +  /|        |
 * `--------+------+------+------+------+------'           `------+------+------+------+------+--------'
 *  | C_C | C_V | CS_C | CS_V |                                           |  Left | Down | Up | Right |
 *  `----------------------------------'                        `------------------------------------'
 *
 *                                .--------------------.         .---------------.------.
 *                                |L1+ESC|      |      |         |        |      | BSpc |
 *                                |------| SPC  |  BS  |         | C.Lock |C.BSpc|------|
 *                                | SPC  |      |      |         |        |      | Enter|
 *                                '------|-------------|         |---------------'------'
 *                                       | LEFT | RGHT |         |  Ctrl.B| Tab  |
 *                                       '------'------'         '--------'------'
 *
 *
 */


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // [_QWERTY] = LAYOUT_6x6_4(
    //     KC_F1  , KC_F2 , KC_F3 , KC_F4 , KC_F5 , KC_F6 ,                         KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,KC_F12 ,
    //     KC_ESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_BSPC,
    //     KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                         KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_MINS,
    //     KC_LSFT, KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                         KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_QUOT,
    //     KC_LCTL, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,KC_BSLS,
    //     _______,_______, KC_LBRC,KC_RBRC,                                                       KC_PLUS, KC_EQL,_______,_______,
    //                                      RAISE,KC_SPC,                        KC_ENT, LOWER,
    //                                      KC_TAB,KC_HOME,                         KC_END,  KC_DEL,
    //                                      KC_BSPC, KC_GRV,                        KC_LGUI, KC_LALT
    // ),


    [_QWERTY] = LAYOUT_6x6_4(
        KC_F1  , KC_F2 , KC_F3 , KC_F4 , KC_F5 , KC_F6 ,                                KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,KC_F12 ,
        LALT(KC_1) , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                            KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_DEL,
        LALT(KC_2) , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                            KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_PGUP,
        LALT(KC_3), KC_A  , KC_S  , LT(RAISE, KC_D) , KC_F  , KC_G  ,                   KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_PGDN,
        LALT(KC_4), LGUI_T(KC_Z), LALT_T(KC_X), LCTL_T(KC_C), LSFT_T(KC_V), KC_B,       KC_N  , LSFT_T(KC_M)  , LCTL_T(KC_COMM) , LALT_T(KC_DOT) ,LGUI(KC_SLSH),KC_CAPS,
        LCTL(KC_C),LCTL(KC_V), LCTL(LSFT(KC_C)),LCTL(LSFT(KC_V)),                       KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,
                                    LT(LOWER,KC_ESC),KC_SPC,                                   KC_ENT, LT(EXTRA, KC_BSPC),
                                         KC_TAB,LCTL(KC_B),                                 LCTL(KC_T),  LCTL(KC_BSPC),
                                         _______, _______,                                             _______,_______
    ),

/* Keymap 1: LOWER
 * ,-------------------------------------------.           ,-------------------------------------------.
 * |   F1   |  F2  |  F3  |  F4  |  F5  |  F6  |           |   F7 |   F8 |  F9 |  F10 |  F11  |   F12  |
 * |--------+------+------+------+------+------|           |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |           |      |   -  |   _  |      |      |        |
 * |--------+------+------+------+------+------|           |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |           |      |   {  |   }  |      |      |        |
 * |--------+------+------+------+------+------|           |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |           |      |   (  |   )  |      |      |        |
 * |--------+------+------+------+------+------|           |------+------+------+------+------+--------|
 * |        |      |     |       |      |      |           |      |   [  |   ]  |             |        |
 * `--------+------+------+------+------+------'           `------+------+------+------+------+--------'
 *  |     |     |      |      |                                           |       |      |    |       |
 *  `----------------------------------'                        `------------------------------------'
 *
 *                                .--------------------.         .---------------.------.
 *                                |L1+ESC|      |      |         |        |      | BSpc |
 *                                |------| SPC  |  BS  |         | C.Lock |C.BSpc|------|
 *                                | SPC  |      |      |         |        |      | Enter|
 *                                '------|-------------|         |---------------'------'
 *                                       | LEFT | RGHT |         |  Ctrl.B| Tab  |
 *                                       '------'------'         '--------'------'
 *
 *
 */

    [_LOWER] = LAYOUT_6x6_4(
        _______,_______,_______,_______,_______,_______,                        _______, _______ , _______ ,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                        _______, KC_LABK , KC_RABK ,_______,_______,_______,
        _______,_______,KC_DQUO,KC_PERC,KC_EQUAL,_______,                       KC_PIPE, KC_LCBR , KC_RCBR ,KC_MINUS,_______,_______,
        _______,_______,KC_QUOT,KC_ASTR,KC_PLUS,_______,                        KC_BSLS, KC_LPRN , KC_LPRN ,KC_UNDS,_______,_______,
        _______,_______,_______,_______,_______,_______,                        KC_HASH, KC_LBRC , KC_RBRC ,KC_TILD,_______,_______,
                                _______,_______,_______,_______,            _______, _______,_______,_______,
                                                _______,_______,            _______,_______,
                                                _______,_______,            _______,_______,
                                                _______,_______,            _______,_______
    ),
    [_RAISE] = LAYOUT_6x6_4(
        _______,_______,_______,_______,_______,QK_BOOT,                        _______,  _______ , _______ ,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                        _______,  _______ ,  _______ ,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                        _______,  LALT(KC_7) ,  LALT(KC_8) , LALT(KC_9),_______,_______,
        _______,_______,KC_LSFT,_______,_______,_______,                        _______,  LALT(KC_4) ,  LALT(KC_5) , LALT(KC_6),_______,_______,
        _______,_______,_______,_______,_______,_______,                        _______,  LALT(KC_1) ,  LALT(KC_2) , LALT(KC_3),_______,_______,
                                _______,_______,_______,_______,            _______, _______,_______,_______,
                                                _______,_______,            _______,_______,
                                                _______,_______,            _______,_______,
                                                _______,_______,            _______,_______
    ),

    [_EXTRA] = LAYOUT_6x6_4(
        _______,_______,_______,_______,_______,_______,                        _______,  _______ , _______ ,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                        _______,  _______ ,  _______ ,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                        _______,  _______ ,  _______ , _______,_______,_______,
        _______,_______,_______,_______,_______,_______,                        _______,  KC_KB_VOLUME_DOWN ,  KC_KB_VOLUME_UP , _______,_______,_______,
        _______,_______,_______,_______,_______,_______,                        _______,  KC_BRIGHTNESS_DOWN ,  KC_BRIGHTNESS_UP , _______,_______,_______,
                                _______,_______,_______,_______,            _______, _______,_______,_______,
                                                _______,_______,            _______,_______,
                                                _______,_______,            _______,_______,
                                                _______,_______,            _______,_______
    ),
    // [_RAISE] = LAYOUT_6x6_4(
    //     KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                        KC_F6  , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,
    //     _______,_______,_______,_______,_______,KC_LBRC,                        KC_RBRC,_______,KC_NUM ,KC_INS ,KC_SCRL,KC_MUTE,
    //     _______,KC_LEFT,KC_UP  ,KC_DOWN,KC_RGHT,KC_LPRN,                        KC_RPRN,KC_MPRV,KC_MPLY,KC_MNXT,_______,KC_VOLU,
    //     _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,KC_VOLD,
    //     _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
    //                             _______,_______,_______,_______,            KC_EQL ,_______,_______,_______,
    //                                             _______,_______,            _______,_______,
    //                                            _______,_______,            _______,_______,
    //                                            _______,_______,            _______,_______
    // )
};
