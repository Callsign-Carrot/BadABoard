#include QMK_KEYBOARD_H
#include "print.h"

void gpio_init(uint gpio);

void keyboard_pre_init_kb(void) {
    gpio_init(26);
    gpio_init(27);
    gpio_init(28);
    gpio_init(29);
}

/* enum layer_names {
    _MA, // main layer
    _FN // function layer
}; */

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif 
  return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_all(
        KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,

        KC_GRV,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,        KC_EQL,     KC_BSPC,
        KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_LBRC,        KC_RBRC,    KC_BSLS,
        KC_LSFT,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,        KC_ENT,
        KC_RCTRL,   KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,                    KC_UP,      
        XXXXXXX,    KC_LWIN,    KC_LALT,                            KC_SPC,                                         KC_CAPS,                KC_LEFT,        KC_DOWN,    KC_RGHT,

        KC_MUTE,    KC_VOLD,   KC_VOLU,
        KC_F13,     KC_F14,     KC_F15,
        KC_F16,     KC_F17,     KC_F18,
        KC_F19,     KC_F20,     KC_F21,
        KC_F22,     KC_F23,     KC_F24,
        KC_SLEP,    KC_WAKE,    KC_CALC,

        KC_NUM,     KC_PSLS,    KC_PAST,    KC_PMNS,
        KC_P7,      KC_P8,      KC_P9,      KC_PPLS,
        KC_P4,      KC_P5,      KC_P6,
        KC_P1,      KC_P2,      KC_P3,      
        KC_P0,                  KC_PDOT,    KC_PEQL
    )
};

void keyboard_post_init_user(void) {
    debug_enable=true;
    debug_matrix=true;
    dprint("JHASBDJAS");

    setPinOutput(27);
    setPinOutput(28);
    setPinOutput(29);

    writePinHigh(GP27);
    writePinHigh(GP28);
    writePinHigh(GP29);
};