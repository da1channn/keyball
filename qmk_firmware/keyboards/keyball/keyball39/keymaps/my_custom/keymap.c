// ================ 【完全版】EEPROMリセット専用キーマップ ここから ================
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_universal(
    // Qの位置にEEPROMリセットキーを配置。他はすべて無効化。
    EEP_RST, KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_LCTL, KC_LGUI, KC_LALT, KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
  )
};

#ifdef COMBO_ENABLE
// コンパイルエラーを回避するため、空のコンボ定義を追加
combo_t key_combos[] = {};
#endif

// このテストでは不要なため、以下の関数は空にします
bool process_record_user(uint16_t keycode, keyrecord_t *record) { return true; }
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) { return TAPPING_TERM; }
bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) { return true; }
#ifdef OLED_ENABLE
#    include "lib/oledkit/oledkit.h"
void oledkit_render_info_user(void) {}
#endif
// ================ 【完全版】EEPROMリセット専用キーマップ ここまで ================
