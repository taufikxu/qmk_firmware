/* Copyright 2016 Jack Humbert
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

// #ifdef TAP_DANCE_ENABLE

#    include <stdbool.h>
#    include <inttypes.h>

typedef struct {
    uint8_t  count;
    uint8_t  oneshot_mods;
    uint8_t  weak_mods;
    uint16_t keycode;
    uint16_t interrupting_keycode;
    uint16_t timer;
    bool     interrupted;
    bool     pressed;
    bool     finished;
    bool     interrupt_others;
} qk_tap_dance_state_t;

#    define TD(n) (QK_TAP_DANCE | ((n)&0xFF))

typedef void (*qk_tap_dance_user_fn_t)(qk_tap_dance_state_t *state, void *user_data);

typedef struct {
    struct {
        qk_tap_dance_user_fn_t on_each_tap;
        qk_tap_dance_user_fn_t on_each_tap_up;
        qk_tap_dance_user_fn_t on_dance_finished;
        qk_tap_dance_user_fn_t on_reset;
    } fn;
    qk_tap_dance_state_t state;
    uint16_t             custom_tapping_term;
    void *               user_data;
} qk_tap_dance_action_t;

typedef struct {
    int32_t kc1;
    int32_t kc2;
    bool kc1_on;
    bool kc2_on;
} qk_tap_dance_pair_t;

typedef struct {
    uint16_t kc;
    uint8_t  layer;
    void (*layer_function)(uint8_t);
} qk_tap_dance_dual_role_t;



void qk_tap_dance_layer_on_each_tap_layer_layer(qk_tap_dance_state_t *state, void *user_data);
void qk_tap_dance_layer_on_each_tap_layer_key(qk_tap_dance_state_t *state, void *user_data);
void qk_tap_dance_layer_on_each_tap_key_layer(qk_tap_dance_state_t *state, void *user_data);
// #define qk_tap_dance_layer_on_each_tap_layer_layer NULL
// #define qk_tap_dance_layer_on_each_tap_layer_key NULL
// #define qk_tap_dance_layer_on_each_tap_key_layer NULL

void qk_tap_dance_layer_on_each_tap_up_layer_layer(qk_tap_dance_state_t *state, void *user_data);
void qk_tap_dance_layer_finished_layer_layer(qk_tap_dance_state_t *state, void *user_data);
void qk_tap_dance_layer_reset_layer_layer(qk_tap_dance_state_t *state, void *user_data);

void qk_tap_dance_layer_on_each_tap_up_layer_key(qk_tap_dance_state_t *state, void *user_data);
void qk_tap_dance_layer_finished_layer_key(qk_tap_dance_state_t *state, void *user_data);
void qk_tap_dance_layer_reset_layer_key(qk_tap_dance_state_t *state, void *user_data);

void qk_tap_dance_layer_on_each_tap_up_key_layer(qk_tap_dance_state_t *state, void *user_data);
void qk_tap_dance_layer_finished_key_layer(qk_tap_dance_state_t *state, void *user_data);
void qk_tap_dance_layer_reset_key_layer(qk_tap_dance_state_t *state, void *user_data);

// #    define ACTION_TAP_DANCE_DOUBLE(kc1, kc2) 
//         { .fn = {qk_tap_dance_pair_on_each_tap, NULL, qk_tap_dance_pair_finished, qk_tap_dance_pair_reset}, .user_data = (void *)&((qk_tap_dance_pair_t){kc1, kc2, false, false}), }

#    define ACTION_TAP_DANCE_TAP_LAYER_HOLD_LAYER(layer1, layer2) \
        { .fn = {qk_tap_dance_layer_on_each_tap_layer_layer, qk_tap_dance_layer_on_each_tap_up_layer_layer, qk_tap_dance_layer_finished_layer_layer, qk_tap_dance_layer_reset_layer_layer}, .user_data = (void *)&((qk_tap_dance_pair_t){layer1, layer2, false, false}), }

#    define ACTION_TAP_DANCE_TAP_KEY_HOLD_LAYER(kc1, layer2) \
        { .fn = {qk_tap_dance_layer_on_each_tap_key_layer, qk_tap_dance_layer_on_each_tap_up_key_layer, qk_tap_dance_layer_finished_key_layer, qk_tap_dance_layer_reset_key_layer}, .user_data = (void *)&((qk_tap_dance_pair_t){kc1, layer2, false, false}), }

#    define ACTION_TAP_DANCE_TAP_LAYER_HOLD_KEY(layer1, kc2) \
        { .fn = {qk_tap_dance_layer_on_each_tap_layer_key, qk_tap_dance_layer_on_each_tap_up_layer_key, qk_tap_dance_layer_finished_layer_key, qk_tap_dance_layer_reset_layer_key}, .user_data = (void *)&((qk_tap_dance_pair_t){layer1, kc2, false, false}), }

// #    define ACTION_TAP_DANCE_DUAL_ROLE(kc, layer) 
//         { .fn = {qk_tap_dance_dual_role_on_each_tap, NULL, qk_tap_dance_dual_role_finished, qk_tap_dance_dual_role_reset}, .user_data = (void *)&((qk_tap_dance_dual_role_t){kc, layer, layer_move}), }

// #    define ACTION_TAP_DANCE_LAYER_TOGGLE(kc, layer) 
//         { .fn = {NULL, qk_tap_dance_dual_role_finished, NULL, qk_tap_dance_dual_role_reset}, .user_data = (void *)&((qk_tap_dance_dual_role_t){kc, layer, layer_invert}), }

// #    define ACTION_TAP_DANCE_LAYER_MOVE(kc, layer) ACTION_TAP_DANCE_DUAL_ROLE(kc, layer)

// #    define ACTION_TAP_DANCE_FN(user_fn)
//         { .fn = {NULL, NULL, user_fn, NULL}, .user_data = NULL, }

// #    define ACTION_TAP_DANCE_FN_ADVANCED(user_fn_on_each_tap, user_fn_on_dance_finished, user_fn_on_dance_reset) 
//         { .fn = {user_fn_on_each_tap, NULL, user_fn_on_dance_finished, user_fn_on_dance_reset}, .user_data = NULL, }

// #    define ACTION_TAP_DANCE_FN_ADVANCED_TIME(user_fn_on_each_tap, user_fn_on_dance_finished, user_fn_on_dance_reset, tap_specific_tapping_term) 
//         { .fn = {user_fn_on_each_tap, NULL, user_fn_on_dance_finished, user_fn_on_dance_reset}, .user_data = NULL, .custom_tapping_term = tap_specific_tapping_term, }

extern qk_tap_dance_action_t tap_dance_actions[];

/* To be used internally */

void preprocess_tap_dance(uint16_t keycode, keyrecord_t *record);
bool process_tap_dance(uint16_t keycode, keyrecord_t *record);
void tap_dance_task(void);
void reset_tap_dance(qk_tap_dance_state_t *state);

// void qk_tap_dance_pair_on_each_tap(qk_tap_dance_state_t *state, void *user_data);
// void qk_tap_dance_pair_finished(qk_tap_dance_state_t *state, void *user_data);
// void qk_tap_dance_pair_reset(qk_tap_dance_state_t *state, void *user_data);

// void qk_tap_dance_dual_role_on_each_tap(qk_tap_dance_state_t *state, void *user_data);
// void qk_tap_dance_dual_role_finished(qk_tap_dance_state_t *state, void *user_data);
// void qk_tap_dance_dual_role_reset(qk_tap_dance_state_t *state, void *user_data);






// #else

// #    define TD(n) KC_NO

// #endif
