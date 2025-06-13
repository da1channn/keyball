/* Keyball39 カスタムキーマップ config.h - ベスト版 */
#pragma once

// 親の設定を継承（最重要）
#include "../../config.h"

// VIA/REMAP設定
#define DYNAMIC_KEYMAP_LAYER_COUNT 4

// コンボ設定
#define COMBO_COUNT 16
#define COMBO_TERM 40
#define COMBO_MUST_TAP_PER_COMBO
#define COMBO_STRICT_TIMER

// MOD-TAP設定
#define TAPPING_TERM 1000
#define TAPPING_TERM_PER_KEY
#define QUICK_TAP_TERM 100
// #define PERMISSIVE_HOLD  // 無効化（コンボ優先）

// オートマウスレイヤー設定（念のため明示）
#ifdef POINTING_DEVICE_ENABLE
    #define POINTING_DEVICE_AUTO_MOUSE_ENABLE
    #define AUTO_MOUSE_DEFAULT_LAYER 1
    #define AUTO_MOUSE_TIME 450
#endif
