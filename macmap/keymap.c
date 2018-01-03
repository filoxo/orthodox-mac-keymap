/*
This is the keymap for the keyboard

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
Copyright 2017 Art Ortenburger
Copyright 2018 Carlos Filoteo

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

#include "orthodox.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _DVORAK 2
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  LOWER,
  RAISE,
  ADJUST,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define LS__SPC MT(MOD_LSFT, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = KEYMAP( \
  KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                                                 KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LEFT, XXXXXXX, KC_DOWN,         KC_UP,  XXXXXXX, KC_RIGHT,KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LCTL, KC_LALT, KC_Z,    KC_X,    KC_C,    KC_V,    LOWER,   KC_BSPC, KC_LGUI,         KC_ENT, LS__SPC, RAISE,   KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH \
),

[_COLEMAK] = KEYMAP(\
  KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                                                                 KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC, \
  KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_UP,   XXXXXXX, KC_DOWN,         KC_LEFT,XXXXXXX, KC_RIGHT,KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, \
  KC_LCTL, KC_LALT, KC_Z,    KC_X,    KC_C,    KC_V,    LOWER,   KC_SPACE,KC_BSPC,         KC_DEL, KC_ENT,  RAISE,   KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH \
),

[_DVORAK] = KEYMAP(\
  KC_ESC,  KC_QUOT, KC_COMM, KC_DOT, KC_P,     KC_Y,                                                                 KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC, \
  KC_TAB,  KC_A,    KC_O,    KC_E,   KC_U,     KC_I,    KC_UP,   XXXXXXX, KC_DOWN,         KC_LEFT,XXXXXXX, KC_RIGHT,KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS, \
  KC_LCTL, KC_LALT, KC_SCLN, KC_Q,   KC_J,     KC_K,    LOWER,   KC_SPACE,KC_BSPC,         KC_DEL, KC_ENT,  RAISE,   KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z \
),

[_LOWER] = KEYMAP( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                                                              KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, \
  _______, _______, _______, _______, _______, _______, KC_LCTL, KC_LALT, _______,         _______, KC_RALT, KC_RCTL,_______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, _______, _______,         _______, _______, _______,KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12 \
),

[_RAISE] = KEYMAP( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                                                  KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_DEL,  _______, _______, _______, KC_HOME, KC_END,  _______, XXXXXXX, _______,         _______, XXXXXXX, _______, KC_F6,  KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______,_______, _______, _______, _______, _______ \
),

[_ADJUST] =  KEYMAP( \
  _______, RESET,   _______, _______, _______, _______,                                                               _______, _______, _______, _______, _______, KC_DEL,  \
  _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, _______, XXXXXXX, _______,         _______, XXXXXXX, _______, AG_SWAP, QWERTY , COLEMAK, DVORAK,  _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY  \
)


};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_colemak);
        #endif
        persistent_default_layer_set(1UL<<_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_dvorak);
        #endif
        persistent_default_layer_set(1UL<<_DVORAK);
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
