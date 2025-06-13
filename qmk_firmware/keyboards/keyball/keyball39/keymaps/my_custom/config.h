
#pragma once

// ⭐ 重要：親のconfig.hを必ず継承
#include "../../config.h"

// via/remap設定
#define DYNAMIC_KEYMAP_LAYER_COUNT 4

// combo設定
#define COMBO_COUNT 16
#define COMBO_TERM 40
#define COMBO_MUST_TAP_PER_COMBO
#define COMBO_STRICT_TIMER

// Mod-Tap設定（中指・人差し指に最適化）
#define TAPPING_TERM 1000
#define TAPPING_TERM_PER_KEY
#define QUICK_TAP_TERM 100
// #define PERMISSIVE_HOLD  // コメントアウト（コンボ優先のため）

// === Keyball固有機能の明示的な有効化 ===
#define POINTING_DEVICE_AUTO_MOUSE_ENABLE

// Auto Mouse Keys設定
#define AUTO_MOUSE_DEFAULT_LAYER 1
#define AUTO_MOUSE_ENABLE
#define AUTO_MOUSE_LAYER_KEEP_TIME 30000
#define AML_ACTIVATE_THRESHOLD 70

// トラックボール設定
#define POINTING_DEVICE_TASK_THROTTLE_MS 8
