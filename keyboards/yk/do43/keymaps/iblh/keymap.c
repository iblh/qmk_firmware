#include QMK_KEYBOARD_H

// enum custom_layers {
//     /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
//     DVORAK
// };
enum layers{
  DVORAK
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DVORAK] = LAYOUT(
        KC_ESC,     KC_QUOT,    KC_COMM,    KC_DOT,    KC_P,      KC_Y,       KC_F,     KC_G,     KC_C,    KC_R,    KC_L,    KC_BSPC,
        KC_TAB,     KC_A,       KC_O,       KC_E,      KC_U,      KC_I,       KC_D,     KC_H,     KC_T,    KC_N,    KC_S,
        KC_LSFT,    KC_SCLN,    KC_Q,       KC_J,      KC_K,      KC_X,       KC_B,     KC_M,     KC_W,    KC_V,    KC_Z, 
        KC_LCTL,    KC_LGUI,    KC_LALT,    KC_SPC,    MO(1),     KC_SPC,     KC_LEFT,  KC_LEFT,  QK_BOOT
    )

	// KEYMAP(
	// 	KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, 
	// 	KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_ENT, 
	// 	KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_SLSH, KC_UP, KC_DEL, 
	// 	KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, MO(1), KC_SPC, KC_LEFT, KC_DOWN, KC_RGHT),

	// KEYMAP(
	// 	KC_GRV, KC_1, KC_2, KC_3, KC_TRNS, KC_TRNS, BL_TOGG, BL_DEC, BL_INC, BL_STEP, KC_LBRC, KC_RBRC, 
	// 	KC_CAPS, KC_4, KC_5, KC_6, KC_EQL, KC_MINS, KC_TRNS, KC_TRNS, KC_SCLN, KC_QUOT, KC_BSLS, 
	// 	KC_LSFT, KC_7, KC_8, KC_9, KC_PDOT, KC_TRNS, KC_COMM, KC_DOT, KC_QUES, KC_TRNS, TO(2), 
	// 	KC_LCTL, KC_LGUI, KC_LALT, KC_0, KC_TRNS, KC_TRNS, KC_VOLD, KC_MUTE, KC_VOLU),

	// KEYMAP(
	// 	KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, 
	// 	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, TO(0), 
	// 	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_VAI, RGB_VAD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
	// 	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET, KC_TRNS, KC_TRNS, KC_TRNS),

	// KEYMAP(
	// 	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
	// 	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
	// 	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
	// 	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),


};