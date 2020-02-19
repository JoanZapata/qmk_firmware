#pragma once

// Since space and shift are the same key with a Mod Tap, tapping " A"
// is inconvenient since the second press is considered like a space.
// "PER_KEY" works by specifying the 'get_tapping_force_hold' function
// in the 'keymap.c' file.
// https://beta.docs.qmk.fm/features/feature_advanced_keycodes#tapping-force-hold
#define TAPPING_FORCE_HOLD_PER_KEY
