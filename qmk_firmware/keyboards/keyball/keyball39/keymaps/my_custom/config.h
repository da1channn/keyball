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

#pragma once

// Via/REMAP設定
#define DYNAMIC_KEYMAP_LAYER_COUNT 4

// コンボ設定
#define COMBO_COUNT 13
#define COMBO_TERM 60  // 50→60に変更

// タッピング設定
#define TAPPING_TERM 170
#define PERMISSIVE_HOLD
#define TAPPING_TERM_PER_KEY  // 新規追加

// Auto Mouse Layer設定（最適化済み）
#define POINTING_DEVICE_AUTO_MOUSE_ENABLE
#define AUTO_MOUSE_DEFAULT_LAYER 1
#define AUTO_MOUSE_LAYER_KEEP_TIME 30000
#define AML_ACTIVATE_THRESHOLD 70   // 50→70に変更
#define AML_TIMEOUT_MIN 150         // 100→150に変更
#define AML_TIMEOUT_MAX 1500        // 1000→1500に変更
#define AML_TIMEOUT_QU 75           // 50→75に変更

// トラックボール設定
#define POINTING_DEVICE_TASK_THROTTLE_MS 8  // 新規追加
