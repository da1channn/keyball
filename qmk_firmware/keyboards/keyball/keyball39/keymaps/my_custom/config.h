#pragma once

// ⭐ これが必須！KBキーコードを動作させるため
#include "../../config.h"

// 以下、カスタム設定
#define DYNAMIC_KEYMAP_LAYER_COUNT 4

#define COMBO_COUNT 16
#define COMBO_TERM 40
#define COMBO_MUST_TAP_PER_COMBO
#define COMBO_STRICT_TIMER

#define TAPPING_TERM 1000
#define TAPPING_TERM_PER_KEY
#define QUICK_TAP_TERM 100
// #define PERMISSIVE_HOLD  // 無効のまま

#define AUTO_MOUSE_DEFAULT_LAYER 1
#define AUTO_MOUSE_ENABLE
#define AUTO_MOUSE_LAYER_KEEP_TIME 30000
#define AML_ACTIVATE_THRESHOLD 70

#define POINTING_DEVICE_TASK_THROTTLE_MS 8
