#pragma once

#include "quantum.h"

bool process_key_exclusion(uint16_t keycode, keyrecord_t *record);

extern bool key_exclusion_enabled;