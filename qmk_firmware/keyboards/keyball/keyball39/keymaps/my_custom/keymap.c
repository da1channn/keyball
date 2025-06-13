/* Keyball39 カスタムキーマップ - ベスト版
 * 
 * 特徴：
 * - JIS配列対応
 * - MOD-TAP（中指・人差し指）
 * - コンボ機能（16個）
 * - KBキーコード対応
 * - オートマウスレイヤー
 */

#include QMK_KEYBOARD_H

// カスタムキーコード
enum custom_keycodes {
    SELECT_ALL = SAFE_RANGE
};

// MOD-TAP定義（中指・人差し指のみ）
#define MT_D LCTL_T(KC_D)
#define MT_F LSFT_T(KC_F)
#define MT_C LGUI_T(KC_C)
#define MT_V LALT_T(KC_V)
#define MT_J RSFT_T(KC_J)
#define MT_K RCTL_T(KC_K)
#define MT_M RALT_T(KC_M)
#define MT_COMM RGUI_T(KC_COMM)

// レイヤー名（可読性向上）
enum layers {
    _BASE = 0,
    _MOUSE = 1,
    _NUMBER = 2,
    _SYMBOL = 3
};

#ifdef COMBO_ENABLE
// コンボ定義
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

// 左手コンボ
const uint16_t PROGMEM combo_tab[]    = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_copy[]   = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM combo_paste[]  = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM combo_esc[]    = {KC_A, KC_Q, COMBO_END};
const uint16_t PROGMEM combo_selall[] = {KC_R, KC_W, COMBO_END};
const uint16_t PROGMEM combo_prtscr[] = {KC_T, KC_G, COMBO_END};
const uint16_t PROGMEM combo_winscr[] = {KC_G, KC_B, COMBO_END};

// 右手コンボ（MOD-TAPキー対応）
const uint16_t PROGMEM combo_lbrc[]  = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM combo_rbrc[]  = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM combo_at[]    = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM combo_quot[]  = {MT_J, MT_K, COMBO_END};
const uint16_t PROGMEM combo_dquo[]  = {MT_K, KC_L, COMBO_END};
const uint16_t PROGMEM combo_lprn[]  = {MT_M, MT_COMM, COMBO_END};
const uint16_t PROGMEM combo_rprn[]  = {MT_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_coln[]  = {KC_Y, KC_H, COMBO_END};
const uint16_t PROGMEM combo_eql[]   = {KC_H, KC_N, COMBO_END};

// コンボ出力（JIS配列）
combo_t key_combos[] = {
    // 左手
    [COMBO_TAB]    = COMBO(combo_tab, KC_TAB),
    [COMBO_COPY]   = COMBO(combo_copy, LCTL(KC_C)),
    [COMBO_PASTE]  = COMBO(combo_paste, LCTL(KC_V)),
    [COMBO_SELALL] = COMBO(combo_selall, SELECT_ALL),
    [COMBO_ESC]    = COMBO(combo_esc, KC_ESC),
    [COMBO_PRTSCR] = COMBO(combo_prtscr, LALT(KC_PSCR)),
    [COMBO_WINSCR] = COMBO(combo_winscr, LWIN(LSFT(KC_S))),
    // 右手
    [COMBO_LBRC]  = COMBO(combo_lbrc, KC_RBRC),     // [
    [COMBO_RBRC]  = COMBO(combo_rbrc, KC_NUHS),     // ]
    [COMBO_AT]    = COMBO(combo_at, KC_LBRC),       // @
    [COMBO_QUOT]  = COMBO(combo_quot, S(KC_7)),     // '
    [COMBO_DQUO]  = COMBO(combo_dquo, S(KC_2)),     // "
    [COMBO_LPRN]  = COMBO(combo_lprn, S(KC_8)),     // (
    [COMBO_RPRN]  = COMBO(combo_rprn, S(KC_9)),     // )
    [COMBO_COLN]  = COMBO(combo_coln, KC_QUOT),     // :
    [COMBO_EQL]   = COMBO(combo_eql, S(KC_MINS))    // =
};
#endif

// レイヤー定義
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Layer 0 - ベース（JIS配列）
    [_BASE] = LAYOUT_universal(
        KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    ,                            KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    ,
        KC_A    , KC_S    , MT_D    , MT_F    , KC_G    ,                            KC_H    , MT_J    , MT_K    , KC_L    , KC_MINS ,
        KC_Z    , KC_X    , MT_C    , MT_V    , KC_B    ,                            KC_N    , MT_M    , MT_COMM , KC_DOT  , KC_SLSH ,
        KC_LCTL , KC_LGUI , KC_LALT , LSFT_T(KC_LNG2), LT(_MOUSE,KC_SPC), LT(_SYMBOL,KC_LNG1),
        KC_BSPC , LT(_NUMBER,KC_ENT), RSFT_T(KC_LNG2), KC_RALT, KC_RGUI, KC_RSFT
    ),

    // Layer 1 - マウス/ナビゲーション + KBキーコード
    [_MOUSE] = LAYOUT_universal(
        KC_INS  , KC_HOME , KC_UP   , KC_END  , KC_DEL  ,                            _______ , KC_ACL0 , KC_ACL1 , KC_ACL2 , KB_15   ,
        C(S(KC_LEFT)), KC_LEFT, KC_DOWN, KC_RGHT, C(S(KC_RGHT)),                     _______ , KC_BTN1 , KC_WH_U , KC_BTN2 , KB_14   ,
        C(S(KC_TAB)), C(KC_TAB), G(KC_TAB), A(KC_TAB), C(KC_T),                      _______ , KC_BTN4 , KC_WH_D , KC_BTN5 , KB_13   ,
        _______ , _______ , _______ , _______ , _______ , _______,
        KC_BSPC , _______ , _______ , KB_3    , KB_2    , _______
    ),

    // Layer 2 - 数字/ファンクション
    [_NUMBER] = LAYOUT_universal(
        KC_TAB  , KC_7    , KC_8    , KC_9    , KC_MINS ,                            _______ , KC_F1   , KC_F2   , KC_F3   , KC_F4   ,
        S(KC_QUOT), KC_4  , KC_5    , KC_6    , S(KC_SCLN),                          _______ , KC_F5   , KC_F6   , KC_F7   , KC_F8   ,
        KC_SLSH , KC_1    , KC_2    , KC_3    , S(KC_MINS),                          _______ , KC_F9   , KC_F10  , KC_F11  , KC_F12  ,
        KC_0    , KC_0    , KC_DOT  , _______ , _______ , _______,
        _______ , _______ , _______ , _______ , _______ , _______
    ),

    // Layer 3 - 記号
    [_SYMBOL] = LAYOUT_universal(
        KC_RBRC , KC_NUHS , S(KC_INT1), KC_INT3, _______,                            _______ , _______ , _______ , _______ , _______,
        S(KC_RBRC), S(KC_NUHS), KC_QUOT, KC_LBRC, _______,                           _______ , _______ , _______ , _______ , _______,
        S(KC_3) , S(KC_MINS), KC_MINS, _______ , _______,                            _______ , _______ , _______ , _______ , _______,
        _______ , _______ , _______ , _______ , _______ , _______,
        _______ , QK_BOOT , _______ , _______ , _______ , QK_BOOT
    )
};

// Keyballキーコード定義（REMAPで使用）
#define KB_2  0x7E02  // CPI +100
#define KB_3  0x7E03  // CPI -100  
#define KB_13 0x7E0D  // 垂直スクロール
#define KB_14 0x7E0E  // 水平スクロール
#define KB_15 0x7E0F  // 自由スクロール

// カスタムキー処理
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
    // その他のキーコードはKeyball本体で処理
    return true;
}

// Tapping Term調整
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // MOD-TAPキー
        case LSFT_T(KC_F):
        case LALT_T(KC_V):
        case RSFT_T(KC_J):
        case RALT_T(KC_M):
        case LCTL_T(KC_D):
        case LGUI_T(KC_C):
        case RCTL_T(KC_K):
        case RGUI_T(KC_COMM):
            return 1000;
            
        // レイヤータップ
        case LSFT_T(KC_LNG2):
        case LT(_MOUSE, KC_SPC):
        case LT(_NUMBER, KC_ENT):
        case LT(_SYMBOL, KC_LNG1):
            return 200;
            
        default:
            return TAPPING_TERM;
    }
}

// コンボ有効レイヤー
bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    return layer_state_is(_BASE) || layer_state_is(_MOUSE);
}

// OLED表示
#ifdef OLED_ENABLE
#include "lib/oledkit/oledkit.h"
void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif
