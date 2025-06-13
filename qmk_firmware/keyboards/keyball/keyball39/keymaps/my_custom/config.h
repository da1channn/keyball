/*
This is the c configuration file for the keymap

Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

// RGB効果（容量削減のため最小限）
#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_EFFECT_STATIC_GRADIENT
// 必要に応じて以下を有効化
// #    define RGBLIGHT_EFFECT_BREATHING
// #    define RGBLIGHT_EFFECT_RAINBOW_MOOD
#endif

#define TAP_CODE_DELAY 5

// オートマウス設定
#define POINTING_DEVICE_AUTO_MOUSE_ENABLE
#define AUTO_MOUSE_DEFAULT_LAYER 1

// VIA用の動的レイヤー数
#define DYNAMIC_KEYMAP_LAYER_COUNT 4

// コンボ設定
#define COMBO_COUNT 16
#define COMBO_TERM 40
#define COMBO_MUST_TAP_PER_COMBO
#define COMBO_STRICT_TIMER

// タッピング設定
#define TAPPING_TERM 1000
#define TAPPING_TERM_PER_KEY
#define QUICK_TAP_TERM 100

// ポーリング間隔を短くして滑らかに（デフォルト8ms→1ms）
#define POINTING_DEVICE_TASK_THROTTLE_MS 1

// マウスレポートレートを上げる（より滑らかな動き）
#define USB_POLLING_INTERVAL_MS 1
