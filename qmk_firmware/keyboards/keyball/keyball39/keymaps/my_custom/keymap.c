/* Copyright 2022 @Yowkees * Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 */
#include QMK_KEYBOARD_H

// カスタムキーコードを定義
enum custom_keycodes {
    SELECT_ALL = SAFE_RANGE
};

// MOD-TAPの定義（元の設定に復元）
#define MT_D LCTL_T(KC_D)
#define MT_F LSFT_T(KC_F)
#define MT_C LGUI_T(KC_C)
#define MT_V LALT_T(KC_V)
#define MT_J RSFT_T(KC_J)
#define MT_K RCTL_T(KC_K)
#define MT_M RALT_T(KC_M)
#define MT_COMM RGUI_T(KC_COMM)

#ifdef COMBO_ENABLE

// コンボの定義（元の設定に復元）
enum combos {
    // 左手
    COMBO_TAB, COMBO_COPY, COMBO_PASTE, COMBO_SELALL, COMBO_ESC, COMBO_PRTSCR, COMBO_WINSCR,
    // 右手
    COMBO_LBRC, COMBO_RBRC, COMBO_AT, COMBO_QUOT, COMBO_DQUO, COMBO_LPRN, COMBO_RPRN, COMBO_COLN, COMBO_EQL
};

// 左手コンボ
const uint16_t PROGMEM combo_tab[]    = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_copy[]   = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM combo_paste[]  = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM combo_esc[]    = {KC_A, KC_Q, COMBO_END};
const uint16_t PROGMEM combo_selall[] = {KC_R, KC_W, COMBO_END};
const uint16_t PROGMEM combo_prtscr[] = {KC_T, KC_G, COMBO_END};
const uint16_t PROGMEM combo_winscr[] = {KC_G, KC_B, COMBO_END};

// 右手コンボ
const uint16_t PROGMEM combo_lbrc[]  = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM combo_rbrc[]  = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM combo_at[]    = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM combo_quot[]  = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM combo_dquo[]  = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM combo_lprn[]  = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM combo_rprn[]  = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_coln[]  = {KC_Y, KC_H, COMBO_END};
const uint16_t PROGMEM combo_eql[]   = {KC_H, KC_N, COMBO_END};

// コンボの出力設定
combo_t key_combos[] = {
    // 左手
    [COMBO_TAB]    = COMBO(combo_tab, KC_TAB),
    [COMBO_COPY]   = COMBO(combo_copy, LCTL(KC_C)),
    [COMBO_PASTE]  = COMBO(combo_paste, LCTL(KC_V)),
    [COMBO_SELALL] = COMBO(combo_selall, SELECT_ALL),
    [COMBO_ESC]    = COMBO(combo_esc, KC_ESC),
    [COMBO_PRTSCR] = COMBO(combo_prtscr, LALT(KC_PSCR)),
    [COMBO_WINSCR] = COMBO(combo_winscr, LWIN(LSFT(KC_S))),

    // 右手（JIS配列での正しいキーコード）
    [COMBO_LBRC]  = COMBO(combo_lbrc, KC_RBRC),      // [
    [COMBO_RBRC]  = COMBO(combo_rbrc, KC_NUHS),      // ]
    [COMBO_AT]    = COMBO(combo_at, KC_LBRC),        // @
    [COMBO_DQUO]  = COMBO(combo_dquo, S(KC_2)),      // "
    [COMBO_LPRN]  = COMBO(combo_lprn, S(KC_8)),      // (
    [COMBO_RPRN]  = COMBO(combo_rprn, S(KC_9)),      // )
    [COMBO_COLN]  = COMBO(combo_coln, KC_QUOT),      // :
    [COMBO_EQL]   = COMBO(combo_eql, S(KC_MINS)),    // =

    // 【修正点2】JKコンボで、JIS配列での標準的な「'」の入力である S(KC_7) を設定
    [COMBO_QUOT]  = COMBO(combo_quot, S(KC_7))       // '
};
#endif

// カスタムキーコードの処理
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SELECT_ALL:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                tap_code(KC_A);
                unregister_code(KC_LCTL);
            }
            return false;
    }
    return true;
}

// レイヤー定義（元の要望＋修正点を反映）
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Layer 0: Base */
  [0] = LAYOUT_universal(
    KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                            KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     ,
    KC_A     , KC_S     , MT_D     , MT_F     , KC_G     ,                            KC_H     , MT_J     , MT_K     , KC_L     , KC_MINS  , // 【修正点1】Pの右隣で、テストで動作が確認された KC_MINS を配置し、'-'を出力
    KC_Z     , KC_X     , MT_C     , MT_V     , KC_B     ,                            KC_N     , MT_M     , MT_COMM  , KC_DOT   , KC_SLSH  ,
    KC_LCTL  , KC_LGUI  , KC_LALT  , LSFT_T(KC_LNG2), LT(1,KC_SPC),    LT(3,KC_LNG1),
    KC_BSPC  , LT(2,KC_ENT),RSFT_T(KC_LNG2), KC_RALT  , KC_RGUI,       KC_RSFT
  ),

  /* Layer 1: Nav/Mouse */
  [1] = LAYOUT_universal(
    KC_INS   , KC_HOME  , KC_UP    , KC_END   , KC_DEL   ,                            _______, KC_BTN3  , KC_MS_U  , KC_WH_U  , _______,
    KC_LCTL  , KC_LEFT  , KC_DOWN  , KC_RGHT  , KC_LALT  ,                            _______, KC_BTN1  , KC_MS_L  , KC_MS_D  , KC_MS_R  ,
    _______,   _______,   _______,   _______,   _______,                            _______, KC_BTN2  , KC_WH_L  , KC_WH_D  , KC_WH_R  ,
    _______,   _______,   _______,   _______,   _______,   _______,
    _______,   _______,   _______,   _______,   _______,   _______
  ),

  /* Layer 2: Numpad/F-Keys */
  [2] = LAYOUT_universal(
    KC_TAB   , KC_7     , KC_8     , KC_9     , KC_MINS  ,                            _______, KC_F1    , KC_F2    , KC_F3    , KC_F4    ,
    S(KC_QUOT), KC_4     , KC_5     , KC_6     ,S(KC_SCLN),                           _______, KC_F5    , KC_F6    , KC_F7    , KC_F8    ,
    KC_SLSH  , KC_1     , KC_2     , KC_3     ,S(KC_MINS),                            _______, KC_F9    , KC_F10   , KC_F11   , KC_F12   ,
    KC_0     , KC_0     , KC_DOT   , KC_DEL   , KC_ENT   , KC_BSPC  ,
    _______,   _______,   _______,   _______,   _______,   _______
  ),

  /* Layer 3: Symbols */
  [3] = LAYOUT_universal(
    KC_RBRC  , KC_NUHS  ,S(KC_INT1), KC_INT3  , _______,                            _______,   _______,   _______,   _______,   _______,
    S(KC_RBRC),S(KC_NUHS), KC_QUOT  , KC_LBRC  , _______,                            _______,   _______,   _______,   _______,   _______,
    S(KC_3)  ,S(KC_MINS), S(KC_MINS), _______,   _______,                            _______,   _______,   _______,   _______,   _______,
    QK_BOOT  , KBC_RST  , _______,   _______,   _______,   _______  ,
    _______,   _______,   _______,   _______,   _______,   QK_BOOT
  ),
};

// Tapping Termのキーごと調整（元の設定に復元）
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_F):
        case LALT_T(KC_V):
        case RSFT_T(KC_J):
        case RALT_T(KC_M):
            return 1000;
        case LCTL_T(KC_D):
        case LGUI_T(KC_C):
        case RCTL_T(KC_K):
        case RGUI_T(KC_COMM):
            return 1000;
        default:
            return TAPPING_TERM;
    }
}

// コンボをレイヤー0と1のみで有効化（元の設定に復元）
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
