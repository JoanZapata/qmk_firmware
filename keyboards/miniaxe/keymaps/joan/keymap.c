/* Copyright 2018 ENDO Katsuhiro <ka2hiro@curlybracket.co.jp>
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
#include QMK_KEYBOARD_H

// Defines the keycodes used by our macros in process_record_user
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   W  |   F  |   P  |   G  |           |   J  |   L  |   U  |   Y  |   ;  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   A  |   R  |   S  |   T  |   D  |           |   H  |   N  |   E  |   I  |   O  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |           |   K  |   M  |   ,  |   .  |   /  |
 * `-------------+------+------+------|           |------+------+------+------+------'
 *               | CMD  | LOWER|Ctrl/Enter|       |Spc/Sft|RAISE|Alt/BkSp|
 *               `--------------------'           `--------------------'
 */
[_QWERTY] = LAYOUT( \
  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                 KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,    \
  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                 KC_H,    KC_N,    KC_E,    KC_I,    KC_O, \
  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                 KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, \
                    KC_LGUI, LOWER, MT(MOD_LCTL, KC_ENTER),   MT(MOD_LSFT, KC_SPC), RAISE, MT(MOD_LALT, KC_BSPC)  \
),

/* Raise
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   !  |   @  |   #  |   $  |   %  |           |   ^  |   &  |   *  |   (  |   )  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Tab |   _  |   +  |  |   |  ~   |           |   :  |   "  |   >  |   {  |   }  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Caps|   -  |   =  |  \   |  `   |           |   ;  |   '  |   <  |   [  |   ]  |
 * `-------------+------+------+------|           |------+------+------+------+------'
 *               |      | LOWER|      |           |  Esc | RAISE|      |
 *               `--------------------'           `--------------------'
 */
[_RAISE] = LAYOUT( \
  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, \
  KC_TAB,  KC_UNDS, KC_PLUS, KC_PIPE, KC_TILD,      KC_COLN, KC_DQUO, KC_GT,   KC_LCBR, KC_RCBR, \
  KC_CAPS, KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,       KC_SCLN, KC_QUOT, KC_LT,   KC_LBRC, KC_RBRC, \
                    _______, _______, _______,      KC_ESC,  _______, _______\
),

/* Lower
 *
 * ,----------------------------------.           ,----------------------------------.
 * |      |      |      |      |      |           |      |      |   Up |      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | Shift| Ctrl | Alt  | Cmd  |      |           |      | Left |  Down| Right|      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      |      |           |      |      |      |      |      |
 * `-------------+------+------+------|           |------+------+------+------+------'
 *               |      | LOWER|      |           |      |      |      |
 *               `--------------------'           `--------------------'
 */
[_LOWER] = LAYOUT( \
   _______,  _______,  _______, _______, _______,     _______, _______, KC_UP,   _______, _______, \
   KC_LSFT,  KC_LCTL,  KC_LALT, KC_LGUI, _______,     _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, \
   _______,  _______,  _______, _______, _______,     _______, _______, _______, _______, _______, \
                       _______, _______, _______,     _______, _______, _______                    \
),


/* Adjust (Lower + Raise)
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |           |   F6 |  F7  |  F8  |  F9  |  F10 |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  F11 |  F12 |      |      |      |           |      |      |      |      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | Reset|QWERTY|      |      |      |           | Prev | Next | Vol- | Vol+ | Play |
 * `-------------+------+------+------|           |------+------+------+------+------'
 *               |      | LOWER|      |           |      | RAISE|      |
 *               `--------------------'           `--------------------'
 */
[_ADJUST] =  LAYOUT( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, \
  KC_F11,  KC_F12,  _______, _______, _______,      _______, _______, _______, _______, _______, \
  RESET,   QWERTY,  _______, _______, _______,      KC_MPRV, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY, \
                    _______, _______, _______,      _______,  _______, _______                   \
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        // persistant_default_layer_set(1UL<<_QWERTY);
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

void led_set_user(uint8_t usb_led) {
}
