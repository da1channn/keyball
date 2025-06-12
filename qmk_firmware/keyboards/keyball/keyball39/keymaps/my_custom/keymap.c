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

// カスタムキーコードを定義
enum custom_keycodes {
    SELECT_ALL = SAFE_RANGE
};

// JIS配列用のキーコード定義
#define JIS_MINS KC_BSLS        // -
#define JIS_EQL  KC_MINS        // =
#define JIS_LBRC KC_RBRC        // [
#define JIS_RBRC KC_NUHS        // ]
#define JIS_SCLN KC_QUOT        // ;
#define JIS_QUOT KC_2           // '
#define JIS_GRV  KC_ZKHK        // `
#define JIS_BSLS KC_INT3        // \（￥）
#define JIS_LCBR LSFT(KC_RBRC)  // {
#define JIS_RCBR LSFT(KC_NUHS)  // }
#define JIS_COLN LSFT(KC_QUOT)  // :
#define JIS_DQUO LSFT(KC_2)     // "
#define JIS_TILD LSFT(KC_EQL)   // ~
#define JIS_UNDS LSFT(KC_BSLS)  // _
#define JIS_PIPE LSFT(KC_INT3)  // |
#define JIS_AT   KC_LBRC        // @
#define JIS_CIRC KC_EQL         // ^
#define JIS_HASH LSFT(KC_3)     // #
#define JIS_DLR  LSFT(KC_4)     // $
#define JIS_PERC LSFT(KC_5)     // %
#define JIS_AMPR LSFT(KC_6)     // &
#define JIS_ASTR LSFT(KC_8)     // *
#define JIS_LPRN LSFT(KC_8)     // (
#define JIS_RPRN LSFT(KC_9)     // )
#define JIS_PLUS LSFT(KC_SCLN)  // +
#define JIS_LT   LSFT(KC_COMM)  // 
#define JIS_GT   LSFT(KC_DOT)   // >
#define JIS_QUES LSFT(KC_SLSH)  // ?
#define JIS_EXLM LSFT(KC_1)     // !

// MOD-TAPの定義（中指・人差し指のみ）
#define MT_D LCTL_T(KC_D)
#define MT_F LSFT_T(KC_F)
#define MT_C LGUI_T(KC_C)
#define MT_V LALT_T(KC_V)
#define MT_J RSFT_T(KC_J)
#define MT_K RCTL_T(KC_K)
#define MT_M RALT_T(KC_M)
#define MT_COMM RGUI_T(KC_COMM)

// コンボの定義
#ifdef COMBO_ENABLE
enum combos {
    // 左手
    COMBO_TAB,
    COMBO_COPY,
    COMBO_PASTE,
    COMBO_SELALL,
    COMBO_ESC,
    COMBO_PRTSCR,
    COMBO_WINSCR,
    // 右手
    COMBO_LBRC,
    COMBO_RBRC,
    COMBO_AT,
    COMBO_QUOT,
    COMBO_DQUO,
    COMBO_LPRN,
    COMBO_RPRN,
    COMBO_COLN,
    COMBO_EQL
};

// 左手コンボ（順序変更済み）
const uint16_t PROGMEM combo_tab[]    = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_copy[]   = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM combo_paste[]  = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM combo_esc[]    = {KC_A, KC_Q, COMBO_END};    // 順序をA+Qに変更
const uint16_t PROGMEM combo_selall[] = {KC_R, KC_W, COMBO_END};    // 順序をR+Wに変更
const uint16_t PROGMEM combo_prtscr[] = {KC_T, KC_G, COMBO_END};
const uint16_t PROGMEM combo_winscr[] = {KC_G, KC_B, COMBO_END};

// 右手コンボ（MT_定義を使用）
const uint16_t PROGMEM combo_lbrc[]  = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM combo_rbrc[]  = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM combo_at[]    = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM combo_quot[]  = {MT_J, MT_K, COMBO_END};     // KC_J → MT_Jに変更
const uint16_t PROGMEM combo_dquo[]  = {MT_K, KC_L, COMBO_END};     // KC_K → MT_Kに変更
const uint16_t PROGMEM combo_lprn[]  = {MT_M, MT_COMM, COMBO_END};  // KC_M → MT_M、KC_COMM → MT_COMMに変更
const uint16_t PROGMEM combo_rprn[]  = {MT_COMM, KC_DOT, COMBO_END}; // KC_COMM → MT_COMMに変更
const uint16_t PROGMEM combo_coln[]  = {KC_Y, KC_H, COMBO_END};
const uint16_t PROGMEM combo_eql[]   = {KC_H, KC_N, COMBO_END};

combo_t key_combos[] = {
    // 左手
    [COMBO_TAB]    = COMBO(combo_tab, KC_TAB),
    [COMBO_COPY]   = COMBO(combo_copy, LCTL(KC_C)),
    [COMBO_PASTE]  = COMBO(combo_paste, LCTL(KC_V)), 
    [COMBO_SELALL] = COMBO(combo_selall, SELECT_ALL),    // カスタムキーコードを使用
    [COMBO_ESC]    = COMBO(combo_esc, KC_ESC),           // A+Q = Esc
    [COMBO_PRTSCR] = COMBO(combo_prtscr, LALT(KC_PSCR)), // Alt+PrtScr（ウィンドウのスクショ）
    [COMBO_WINSCR] = COMBO(combo_winscr, LWIN(LSFT(KC_S))),
    
    // 右手（JIS配列対応 - 再修正版）
    [COMBO_LBRC]  = COMBO(combo_lbrc, JIS_LBRC),        // [ → KC_RBRC
    [COMBO_RBRC]  = COMBO(combo_rbrc, JIS_RBRC),        // ] → KC_NUHS
    [COMBO_AT]    = COMBO(combo_at, JIS_AT),            // @ → KC_LBRC
    [COMBO_QUOT]  = COMBO(combo_quot, LSFT(KC_7)),      // ' → Shift+7
    [COMBO_DQUO]  = COMBO(combo_dquo, LSFT(KC_2)),      // " → Shift+2
    [COMBO_LPRN]  = COMBO(combo_lprn, LSFT(KC_8)),      // ( → Shift+8
    [COMBO_RPRN]  = COMBO(combo_rprn, LSFT(KC_9)),      // ) → Shift+9
    [COMBO_COLN]  = COMBO(combo_coln, KC_QUOT),         // : → KC_QUOT
    [COMBO_EQL]   = COMBO(combo_eql, LSFT(KC_BSLS))     // = → Shift+BSLS（修正）
};
#endif

// カスタムキーコードの処理
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SELECT_ALL:
            if (record->event.pressed) {
                // Ctrl+Aを送信
                register_code(KC_LCTL);
                tap_code(KC_A);
                unregister_code(KC_LCTL);
            }
            return false;  // このキーの処理を終了
    }
    return true;  // その他のキーは通常通り処理
}

// レイヤー定義
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Layer 0 - Base（JIS対応、Mod-Tapは中指・人差し指のみ）
  [0] = LAYOUT_universal(
    KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                            KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     ,
    KC_A     , KC_S     , MT_D     , MT_F     , KC_G     ,                            KC_H     , MT_J     , MT_K     , KC_L     , KC_BSLS  , // 右端をKC_BSLSに修正
    KC_Z     , KC_X     , MT_C     , MT_V     , KC_B     ,                            KC_N     , MT_M     , MT_COMM  , KC_DOT   , KC_SLSH  ,
    KC_LCTL  , KC_LGUI  , KC_LALT  ,LSFT_T(KC_LNG2),LT(1,KC_SPC),LT(3,KC_LNG1),KC_BSPC,LT(2,KC_ENT),LSFT_T(KC_LNG2),KC_RALT,KC_RGUI, KC_RSFT
  ),
  
  [1] = LAYOUT_universal(
    KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_RBRC  ,                            KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   ,
    KC_F5    , KC_EXLM  , S(KC_6)  ,S(KC_INT3), S(KC_8)  ,                           S(KC_INT1), KC_BTN1  , KC_PGUP  , KC_BTN2  , KC_SCLN  ,
    S(KC_EQL),S(KC_LBRC),S(KC_7)   , S(KC_2)  ,S(KC_RBRC),                            KC_LBRC  , KC_DLR   , KC_PGDN  , KC_BTN3  , KC_F11   ,
    KC_INT1  , KC_EQL   , S(KC_3)  , _______  , _______  , _______  ,      TO(2)    , TO(0)    , _______  , KC_RALT  , KC_RGUI  , KC_F12
  ),

  [2] = LAYOUT_universal(
    KC_TAB   , KC_7     , KC_8     , KC_9     , KC_MINS  ,                            KC_NUHS  , _______  , KC_BTN3  , _______  , KC_BSPC  ,
   S(KC_QUOT), KC_4     , KC_5     , KC_6     ,S(KC_SCLN),                            S(KC_9)  , KC_BTN1  , KC_UP    , KC_BTN2  , KC_QUOT  ,
    KC_SLSH  , KC_1     , KC_2     , KC_3     ,S(KC_MINS),                           S(KC_NUHS), KC_LEFT  , KC_DOWN  , KC_RGHT  , _______  ,
    KC_ESC   , KC_0     , KC_DOT   , KC_DEL   , KC_ENT   , KC_BSPC  ,      _______  , _______  , _______  , _______  , _______  , _______
  ),

  [3] = LAYOUT_universal(
    RGB_TOG  , AML_TO   , AML_I50  , AML_D50  , _______  ,                            _______  , _______  , SSNP_HOR , SSNP_VRT , SSNP_FRE ,
    RGB_MOD  , RGB_HUI  , RGB_SAI  , RGB_VAI  , SCRL_DVI ,                            _______  , _______  , _______  , _______  , _______  ,
    RGB_RMOD , RGB_HUD  , RGB_SAD  , RGB_VAD  , SCRL_DVD ,                            CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , KBC_SAVE ,
    QK_BOOT  , KBC_RST  , _______  , _______  , _______  , _______  ,      _______  , _______  , _______  , _______  , KBC_RST  , QK_BOOT
  ),
};

// Tapping Termのキーごと調整（ユーザーの要望により長め）
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // 人差し指（Shift/Alt）
        case LSFT_T(KC_F):
        case LALT_T(KC_V):
        case RSFT_T(KC_J):
        case RALT_T(KC_M):
            return 1000;  // ユーザーの要望により長め
            
        // 中指（Ctrl/GUI）
        case LCTL_T(KC_D):
        case LGUI_T(KC_C):
        case RCTL_T(KC_K):
        case RGUI_T(KC_COMM):
            return 1000;  // ユーザーの要望により長め
            
        default:
            return TAPPING_TERM;
    }
}

// コンボをレイヤー0と1のみで有効化
bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    uint8_t layer = get_highest_layer(layer_state);
    return (layer == 0 || layer == 1);
}

#ifdef OLED_ENABLE
#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif
