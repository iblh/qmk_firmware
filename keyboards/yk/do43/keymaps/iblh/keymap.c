#include QMK_KEYBOARD_H

// enum custom_layers {
//     /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
//     DVORAK
// };
enum layers{
  DVORAK,
  QWERTY,
  NUM,
//   EXTRA,
  FN
};


enum custom_keycodes {
    GUI_QWERTY = SAFE_RANGE,
    GUI_SFT_Z,
    GUI_GRAVE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DVORAK] = LAYOUT(
        KC_ESC,     KC_QUOT,    KC_COMM,      KC_DOT,    KC_P,     KC_Y,      KC_F,       KC_G,       KC_C,      KC_R,      KC_L,    KC_BSPC,
        KC_TAB,     KC_A,       KC_O,         KC_E,      KC_U,     KC_I,      KC_D,       KC_H,       KC_T,      KC_N,      KC_S,
        KC_LSFT,    KC_SCLN,    KC_Q,         KC_J,      KC_K,     KC_X,      KC_B,       KC_M,       KC_W,      KC_V,      KC_Z, 
        KC_LCTL,    KC_LALT,    GUI_QWERTY,   KC_SPC,    KC_TRNS,  MO(NUM),   MO(FN),     KC_RALT,    QK_BOOT
    ),

    [QWERTY] = LAYOUT(
        KC_GRAVE,   KC_Q,       KC_W,         KC_E,      KC_R,     KC_T,      KC_Y,       KC_U,       KC_I,      KC_O,      KC_P,    KC_BSPC,
        KC_TAB,     KC_A,       KC_S,         KC_D,      KC_F,     KC_G,      KC_H,       KC_J,       KC_K,      KC_L,      KC_ENTER,
        KC_LSFT,    KC_Z,       KC_X,         KC_C,      KC_V,     KC_B,      KC_N,       KC_M,       KC_COMM,   KC_DOT,    RSFT_T(KC_SLSH),
        KC_LCTL,    KC_LALT,    KC_LGUI,      KC_SPC,    KC_TRNS,  MO(NUM),   MO(FN),     MO(FN),     QK_BOOT
    ),

    [NUM] = LAYOUT(
        KC_ESC,     KC_1,       KC_2,         KC_3,      KC_4,     KC_5,      KC_7,       KC_8,       KC_9,      KC_0,      KC_LEFT_BRACKET,    KC_RIGHT_BRACKET,
        KC_TAB,     KC_CAPS,    KC_DOWN,      KC_RGHT,   KC_WFWD,  KC_TRNS,   KC_4,       KC_5,       KC_6,      KC_EQUAL,  KC_ENTER,
        KC_LSFT,    KC_SCLN,    KC_C,         KC_V,      KC_TRNS,  KC_TRNS,   KC_1,       KC_2,       KC_3,      KC_MINUS,  KC_RSFT,
        KC_LCTL,    KC_LALT,    KC_LGUI,      KC_SPC,    KC_TRNS,  MO(NUM),   MO(FN),     MO(FN),     QK_BOOT
    ),

    // [EXTRA] = LAYOUT(
    //     KC_ESC,     KC_QUOT,    KC_COMM,    KC_DOT,    KC_P,     KC_Y,      KC_F,       KC_G,       KC_C,      KC_R,    KC_L,    KC_BSPC,
    //     KC_TAB,     KC_A,       KC_O,       KC_E,      KC_U,     KC_I,      KC_D,       KC_H,       KC_T,      KC_N,    KC_S,
    //     KC_LSFT,    KC_SCLN,    KC_Q,       KC_J,      KC_K,     KC_X,      KC_B,       KC_M,       KC_W,      KC_V,    KC_Z, 
    //     KC_LCTL,    KC_LGUI,    KC_LALT,    KC_SPC,    MO(1),    KC_SPC,    KC_LEFT,    KC_LEFT,    QK_BOOT
    // ),

    [FN] = LAYOUT(
        KC_NO,      KC_F1,      KC_F2,        KC_F3,     KC_F4,    KC_F5,     KC_F6,      KC_F7,      KC_UP,      KC_F8,     KC_F9,      KC_F10,
        KC_NO,      KC_NO,      KC_NO,        KC_NO,     KC_RGHT,  KC_WFWD,   KC_PAST,    KC_LEFT,    KC_DOWN,    KC_RIGHT,  KC_DEL,
        KC_LSFT,    GUI_SFT_Z,  KC_TRNS,      KC_TRNS,   KC_TRNS,  KC_TRNS,   KC_0,       KC_1,       KC_2,       KC_3,      KC_PDOT,
        KC_LCTL,    KC_LALT,    KC_LGUI,      KC_SPC,    KC_TRNS,  MO(NUM),   MO(FN),     MO(FN),     QK_BOOT
    )
};


// =================== TAPPING ===================
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // When GUI_QWERTY is held down, turn on QWERTY layer and register Command as a mod key
        case GUI_QWERTY:
            if (record->event.pressed) {
                // Turn on QWERTY when Command is pressed
                layer_on(QWERTY);
                // Register Command as a mod key
                register_mods(MOD_BIT(KC_LGUI)); 
            } else {
                // Turn off QWERTY when Command is released
                layer_off(QWERTY); 
                // Unregister Command mod key
                unregister_mods(MOD_BIT(KC_LGUI)); 
            }
            // Skip all further processing of this key
            return false;
        case GUI_SFT_Z: 
            if (record->event.pressed) {
                // When the keycode is pressed
                register_code(KC_LGUI); // Press Command (GUI)
                register_code(KC_LSFT); // Press Shift
                tap_code(KC_Z);         // Tap 'Z'
                unregister_code(KC_LSFT); // Release Shift
                unregister_code(KC_LGUI); // Release Command (GUI)
            }
            return false; // We handled this keypress
        case GUI_GRAVE:
            if (record->event.pressed) {
                // When the keycode is pressed
                register_code(KC_LGUI); // Press Command (GUI)
                tap_code(KC_GRAVE);         // Tap 'Z'
            }
            return false; // We handled this keypress

    }

    return true;
};


// =================== COMBOS ===================

enum combos {
    LBSPC_SLASH,
    QUOTCOMM_GRAVE,
    QW_GRAVE,
    AS_TAB,
    // AO_TAB,
    NS_MINUS,
    GUISFTX_GUISFTZ,
};

const uint16_t PROGMEM lbsp_combo[] = {KC_L, KC_BSPC, COMBO_END};
const uint16_t PROGMEM quotcomm_combo[] = {KC_QUOT, KC_COMM, COMBO_END};
const uint16_t PROGMEM qw_combo[] = {KC_GRAVE, KC_W, COMBO_END};
const uint16_t PROGMEM tab_s_combo[] = {KC_TAB, KC_S, COMBO_END};
// const uint16_t PROGMEM ao_combo[] = {KC_A, KC_O, COMBO_END};
const uint16_t PROGMEM ns_combo[] = {KC_N, KC_S, COMBO_END};
const uint16_t PROGMEM gui_sft_x_combo[] = {KC_LGUI, LSFT_T(KC_Z), KC_X, COMBO_END};

combo_t key_combos[] = {
    [LBSPC_SLASH] = COMBO(lbsp_combo, KC_SLSH),
    [QUOTCOMM_GRAVE] = COMBO(quotcomm_combo, KC_GRAVE),
    [QW_GRAVE] = COMBO(qw_combo, KC_GRAVE),
    [AS_TAB] = COMBO(tab_s_combo, KC_A),
    // [AO_TAB] = COMBO(ao_combo, KC_TAB),
    [NS_MINUS] = COMBO(ns_combo, KC_MINUS),
    [GUISFTX_GUISFTZ] = COMBO(gui_sft_x_combo, GUI_SFT_Z),
};