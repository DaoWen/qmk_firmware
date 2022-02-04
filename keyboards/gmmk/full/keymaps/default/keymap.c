#include QMK_KEYBOARD_H
#include "rgb_matrix.h"

#ifdef DEBUG_GMMK
#include "printf.h"
#endif

#define _BL 0
#define _FN 1
#define _L2 2
#define _L3 3

#define GUI_LOCK    0x1689

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* The GMMK uses a 7x16 matrix. Some keys are not wired in the matrix at their physical location */

    [_BL] = KEYMAP(     KC_ESC,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,          KC_F10,         KC_F11,     KC_F12,
                        KC_GRV,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,           KC_0,           KC_MINS,    KC_EQL,    KC_NUMLOCK, KC_KP_SLASH, KC_KP_ASTERISK,
                        KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,           KC_P,           KC_LBRC,    KC_RBRC,   KC_KP_7,    KC_KP_8,     KC_KP_9,
                        KC_CAPS,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,           KC_SCLN,        KC_QUOT,    KC_BSLS,   KC_KP_4,    KC_KP_5,     KC_KP_6,
                        KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,         KC_SLSH,        KC_RSFT,    KC_ENT,    KC_KP_1,    KC_KP_2,     KC_KP_3,
                        KC_LCTL,    KC_LGUI,    KC_LALT,    KC_SPC,     KC_RALT,    MO(_FN),    KC_APP,     KC_RCTL,    KC_LEFT,    KC_DOWN,        KC_UP,          KC_RGHT,    KC_BSPC,   KC_KP_0,    KC_KP_DOT,   KC_KP_ENTER,
                        KC_NUBS,    KC_PSCR,    KC_SLCK,    KC_PAUS,    KC_INS,     KC_HOME,    KC_PGUP,    KC_DEL,     KC_END,     KC_PGDN,        KC_KP_MINUS,    KC_KP_PLUS),

    [_FN] = KEYMAP(     RESET,      KC_MYCM,    KC_WSCH,    KC_CALC,    KC_MSEL,    KC_MPRV,    KC_MNXT,    KC_MPLY,    KC_MSTP,    KC_MUTE,        KC_VOLD,        KC_VOLU,    KC_SLEP,
                        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,        KC_TRNS,    RGB_HUI,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                        KC_TRNS,    KC_TRNS,    KC_TRNS,    EEP_RST,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    RGB_SAI,    KC_TRNS,
                        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,        KC_TRNS,    KC_TRNS,    RGB_HUD,    KC_TRNS,    RGB_HUI,
                        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    RGB_SAD,    KC_TRNS,
                        KC_TRNS,    GUI_LOCK,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    RGB_SPD,    RGB_VAD,        RGB_VAI,        RGB_SPI,    KC_SLEP,    KC_TRNS,    RGB_TOG,    KC_TRNS,
                        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    RGB_M_B,    RGB_M_SW,   RGB_MOD,    RGB_M_R,    RGB_M_P,    RGB_RMOD,       KC_TRNS,        KC_TRNS),
    [_L2] = {[0 ... MATRIX_ROWS - 1] = {[0 ... MATRIX_COLS - 1] = KC_TRNS}},
    [_L3] = {[0 ... MATRIX_ROWS - 1] = {[0 ... MATRIX_COLS - 1] = KC_TRNS}}
};

void matrix_init_user(void)
{
}

void matrix_scan_user(void)
{
}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    switch (keycode) {
        case GUI_LOCK:
            /* win lock */
            if (record->event.pressed) {
                keymap_config.raw = eeconfig_read_keymap();
                keymap_config.no_gui = !keymap_config.no_gui;
                eeconfig_update_keymap(keymap_config.raw);
                clear_keyboard();
            }

        return false;
    }

    return true;
}
