/* Copyright 2022 @Yowkees
 * Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

// MOD-TAPの定義（わかりやすくするため）
#define MT_A MT(MOD_LCTL, KC_A)    // A: Tap=a, Hold=LCTL
#define MT_S MT(MOD_LALT, KC_S)    // S: Tap=s, Hold=LALT
#define MT_D MT(MOD_LGUI, KC_D)    // D: Tap=d, Hold=LGUI
#define MT_F MT(MOD_LSFT, KC_F)    // F: Tap=f, Hold=LSFT
#define MT_J MT(MOD_RSFT, KC_J)    // J: Tap=j, Hold=RSFT
#define MT_K MT(MOD_RGUI, KC_K)    // K: Tap=k, Hold=RGUI
#define MT_L MT(MOD_RALT, KC_L)    // L: Tap=l, Hold=RALT
#define MT_MINS MT(MOD_RCTL, KC_MINS) // -: Tap=-, Hold=RCTL

// コンボの定義
#ifdef COMBO_ENABLE
enum combos {
    COMBO_ESC,
    COMBO_TAB,
    COMBO_COPY,
    COMBO_PASTE,
    COMBO_ENTER,
    COMBO_BSPC,
    COMBO_ALTSCR,
    COMBO_WINSCR,
    COMBO_COMMA,
    COMBO_DOT,
    COMBO_SEMICOLON,
    COMBO_SAVE,
    COMBO_UNDO
};

const uint16_t PROGMEM combo_esc[]    = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_tab[]    = {MT_A, MT_S, COMBO_END};  // MOD-TAPでも動作
const uint16_t PROGMEM combo_copy[]   = {KC_T, KC_G, COMBO_END};
const uint16_t PROGMEM combo_paste[]  = {KC_G, KC_B, COMBO_END};
const uint16_t PROGMEM combo_enter[]  = {MT_MINS, MT_L, COMBO_END}; // -+L
const uint16_t PROGMEM combo_bspc[]   = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM combo_altscr[] = {KC_Y, KC_H, COMBO_END};
const uint16_t PROGMEM combo_winscr[] = {KC_H, KC_N, COMBO_END};
const uint16_t PROGMEM combo_comma[]  = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM combo_dot[]    = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_semicolon[] = {MT_L, MT_MINS, COMBO_END};
const uint16_t PROGMEM combo_save[]   = {MT_S, MT_D, COMBO_END};
const uint16_t PROGMEM combo_undo[]   = {KC_Z, KC_X, COMBO_END};

combo_t key_combos[] = {
    [COMBO_ESC]    = COMBO(combo_esc, KC_ESC),
    [COMBO_TAB]    = COMBO(combo_tab, KC_TAB),
    [COMBO_COPY]   = COMBO(combo_copy, LCTL(KC_C)),
    [COMBO_PASTE]  = COMBO(combo_paste, LCTL(KC_V)),
    [COMBO_ENTER]  = COMBO(combo_enter, KC_ENT),
    [COMBO_BSPC]   = COMBO(combo_bspc, KC_BSPC),
    [COMBO_ALTSCR] = COMBO(combo_altscr, LALT(KC_PSCR)),
    [COMBO_WINSCR] = COMBO(combo_winscr, LWIN(LSFT(KC_S))),
    [COMBO_COMMA]  = COMBO(combo_comma, KC_COMM),
    [COMBO_DOT]    = COMBO(combo_dot, KC_DOT),
    [COMBO_SEMICOLON] = COMBO(combo_semicolon, KC_SCLN),
    [COMBO_SAVE]   = COMBO(combo_save, LCTL(KC_S)),
    [COMBO_UNDO]   = COMBO(combo_undo, LCTL(KC_Z))
};
#endif

// レイヤー定義
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Layer 0 - Base（MOD-TAP適用）
  [0] = LAYOUT_universal(
    KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                            KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     ,
    MT_A     , MT_S     , MT_D     , MT_F     , KC_G     ,                            KC_H     , MT_J     , MT_K     , MT_L     , MT_MINS  ,
    KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,                            KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  ,
    KC_LCTL  , KC_LGUI  , KC_LALT  , XXXXXXX  ,LT(2,KC_MHEN),LT(1,KC_SPC),LT(3,KC_HENK),LT(3,KC_BSPC),LT(2,KC_ENT), KC_RALT, KC_RGUI, KC_RCTL
  ),
  
  // Layer 1 - Nav/Mouse
  [1] = LAYOUT_universal(
    KC_INS   , KC_HOME  , KC_UP    , KC_END   , KC_DEL   ,                            XXXXXXX  , KC_BTN3  , KC_MS_U  , KC_WH_U  , XXXXXXX  ,
    KC_LCTL  , KC_LEFT  , KC_DOWN  , KC_RGHT  , KC_LALT  ,                            XXXXXXX  , KC_BTN1  , KC_MS_L  , KC_MS_D  , KC_MS_R  ,
    XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,                            XXXXXXX  , KC_BTN2  , KC_WH_L  , KC_WH_D  , KC_WH_R  ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______
  ),
  
  // Layer 2 - Numpad/F-Keys
  [2] = LAYOUT_universal(
    KC_TAB   , KC_7     , KC_8     , KC_9     , KC_MINS  ,                            XXXXXXX  , KC_F1    , KC_F2    , KC_F3    , KC_F4    ,
    KC_ASTR  , KC_4     , KC_5     , KC_6     , KC_PLUS  ,                            XXXXXXX  , KC_F5    , KC_F6    , KC_F7    , KC_F8    ,
    KC_SLSH  , KC_1     , KC_2     , KC_3     , KC_EQL   ,                            XXXXXXX  , KC_F9    , KC_F10   , KC_F11   , KC_F12   ,
    _______ , KC_0     , KC_0     , KC_DOT   , _______ , KC_ENT  , KC_BSPC , _______ , _______ , _______ , _______ , _______
  ),
  
  // Layer 3 - Symbols
  [3] = LAYOUT_universal(
    KC_LBRC  , KC_RBRC  , KC_UNDS  , KC_BSLS  , XXXXXXX  ,                            XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,
    KC_LCBR  , KC_RCBR  , KC_COLN  , KC_AT    , XXXXXXX  ,                            XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,
    KC_HASH  , KC_TILD  , KC_CIRC  , XXXXXXX  , XXXXXXX  ,                            XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,
    QK_BOOT  , QK_BOOT  , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______
  )
};

// Mod-Tapのタイミング調整
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT_F:      // F (左Shift)
        case MT_J:      // J (右Shift)
            return 200; // Shiftは長めに
        case MT_A:      // A (左Ctrl)
        case MT_MINS:   // - (右Ctrl)
            return 150; // Ctrlは短めに
        case MT_S:      // S (左Alt)
        case MT_L:      // L (右Alt)
        case MT_D:      // D (左GUI)
        case MT_K:      // K (右GUI)
            return 170; // デフォルト値
        default:
            return TAPPING_TERM;
    }
}

#ifdef OLED_ENABLE
#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif
