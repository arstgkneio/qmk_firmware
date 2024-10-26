// key_exclusion.c
#include "key_exclusion.h"
#include "quantum.h"        // Includes necessary headers
#include "action.h"         // For action_t and action kind IDs
#include "action_layer.h"   // For layer functions
#include "matrix.h"         // For matrix scanning functions

bool key_exclusion_enabled = false;  // Start with key exclusion disabled

// Define your key exclusion pairs
typedef struct {
    uint16_t keycode;
    uint16_t exclude_keycode;
} key_exclusion_t;

// List of key exclusion pairs
const key_exclusion_t key_exclusions[] = {
    {KC_R, KC_T},
    {KC_T, KC_R},
    {KC_F, KC_S},
    {KC_S, KC_F},
    // Add more pairs as needed
};

#define KEY_EXCLUSIONS_COUNT (sizeof(key_exclusions) / sizeof(key_exclusion_t))

// Function to check if a keycode is currently pressed
bool is_keycode_pressed(uint16_t keycode) {
    // Iterate over all key positions
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        for (uint8_t col = 0; col < MATRIX_COLS; col++) {
            if (matrix_is_on(row, col)) {
                keypos_t key = (keypos_t){ .row = row, .col = col };
                uint8_t layer = layer_switch_get_layer(key);
                action_t action = action_for_key(layer, key);

                // Extract the keycode from the action
                uint16_t kc = 0;

                if (action.kind.id == ACT_MODS ||
                    action.kind.id == ACT_LMODS ||
                    action.kind.id == ACT_RMODS ||
                    action.kind.id == ACT_MODS_TAP) {
                    kc = action.key.code;
                } else if (action.kind.id == ACT_USAGE) {
                    kc = action.code;
                } else if (action.kind.id == ACT_LAYER_TAP) {
                    kc = action.layer_tap.code;
                } else {
                    continue; // Skip unsupported action kinds
                }

                if (kc == keycode) {
                    return true;
                }
            }
        }
    }
    return false;
}

// Implement the key exclusion logic
bool process_key_exclusion(uint16_t keycode, keyrecord_t *record) {
    if (!key_exclusion_enabled) {
        return true;  // Key exclusion is disabled; allow normal processing
    }

    static uint16_t suppressed_keys[KEY_EXCLUSIONS_COUNT];
    static uint8_t suppressed_count = 0;

    // Check if the keycode is in the exclusion list
    bool is_exclusion_key = false;
    uint16_t exclude_keycode = 0;

    for (uint8_t i = 0; i < KEY_EXCLUSIONS_COUNT; i++) {
        if (keycode == key_exclusions[i].keycode) {
            is_exclusion_key = true;
            exclude_keycode = key_exclusions[i].exclude_keycode;
            break;
        }
    }

    if (!is_exclusion_key) {
        // Keycode is not in the exclusion list, continue normal processing
        return true;
    }

    // Only handle basic keycodes
    if (!IS_BASIC_KEYCODE(keycode)) {
        return true;
    }

    if (record->event.pressed) {
        // On key press
        // If the exclude_keycode is currently pressed, unregister it
        if (is_keycode_pressed(exclude_keycode)) {
            unregister_code16(exclude_keycode);
            // Add to suppressed keys
            if (suppressed_count < KEY_EXCLUSIONS_COUNT) {
                suppressed_keys[suppressed_count++] = exclude_keycode;
            }
        }
        register_code16(keycode);
    } else {
        // On key release
        unregister_code16(keycode);
        // Check if we need to re-register any suppressed keys
        for (uint8_t i = 0; i < suppressed_count; i++) {
            if (suppressed_keys[i] == exclude_keycode) {
                uint16_t suppressed_keycode = suppressed_keys[i];
                // Remove this key from the suppressed keys array
                for (uint8_t j = i; j < suppressed_count - 1; j++) {
                    suppressed_keys[j] = suppressed_keys[j + 1];
                }
                suppressed_count--;

                // Re-register the suppressed key if it's still held down
                if (is_keycode_pressed(suppressed_keycode)) {
                    register_code16(suppressed_keycode);
                }
                break;
            }
        }
    }

    return false; // We've handled the key event for keys in the exclusion list
}
