/* Copyright 2025 Bolin Huang
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

// Dvorak layout for WT65-H2
#include QMK_KEYBOARD_H

enum custom_layers {
    _DVORAK,
    _QWERTY,
    _FN
};

enum custom_keycodes {
    CTL_QWERTY = SAFE_RANGE,
    TOGGLE_LAYOUT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // Dvorak layer
    [_DVORAK] = LAYOUT_all(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_LBRC,  KC_RBRC,  KC_BSPC, KC_GRV,  KC_HOME,
        KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH,  KC_EQL,   KC_NUBS,          KC_END,
        MO(_FN), KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,  KC_ENT,                     KC_PGUP,
        KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT,                     KC_UP,   KC_PGDN,
        CTL_QWERTY,       KC_LALT,                            KC_SPC,                                      KC_RGUI,            KC_LEFT, KC_DOWN, KC_RGHT
    ),

    // QWERTY Layer
    [_QWERTY] = LAYOUT_all(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_BSPC, KC_GRV,  KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_RBRC, KC_NUBS,          KC_END,
        MO(_FN), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,  KC_ENT,                    KC_PGUP,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,                    KC_UP,   KC_PGDN,
        KC_LCTL,          KC_LALT,                            KC_SPC,                                      KC_RGUI,           KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_FN] = LAYOUT_all(
        KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,  KC_NO,   KC_NO,  KC_NO,
        KC_CAPS, KC_MPLY, KC_MPRV, KC_MNXT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_UP,   KC_NO,   KC_NO,    KC_NO,    KC_NO,   KC_NO,           QK_BOOT,
        KC_NO,   KC_MUTE, KC_VOLD, KC_VOLU, KC_NO,   KC_NO,   KC_NO,   KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,    KC_DEL,   KC_NO,                    KC_NO,
        KC_LSFT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,                      KC_NO,  TOGGLE_LAYOUT,
        KC_NO,            KC_NO,                              KC_NO,                                        KC_NO,            KC_NO,    KC_NO,  KC_NO
    ),
};

// =================== TAPPING ===================
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // When GUI_QWERTY is held down, turn on QWERTY layer and register Command as a mod key
        case CTL_QWERTY:
            if (record->event.pressed) {
                // Turn on QWERTY when Command is pressed
                layer_on(_QWERTY);
                // Register Command as a mod key
                register_mods(MOD_BIT(KC_LCTL)); 
            } else {
                // Turn off QWERTY when Command is released
                layer_off(_QWERTY); 
                // Unregister Command mod key
                unregister_mods(MOD_BIT(KC_LCTL)); 
            }
            // Skip all further processing of this key
            return false;

        case TOGGLE_LAYOUT:
            if (record->event.pressed) {
                // Get the current default layer state
                uint8_t default_layer = get_highest_layer(default_layer_state);
                if (default_layer == _DVORAK) {
                    set_single_persistent_default_layer(_QWERTY);
                } else if (default_layer == _QWERTY){
                    set_single_persistent_default_layer(_DVORAK);
                }
            }
            return false;
    }

    return true;
};