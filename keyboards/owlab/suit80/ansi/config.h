/* 
Copyright 2021 owlab

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

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x4F53  //0x4F53 OS for owl studio
#define PRODUCT_ID      0x5355  //0x5355 SU for SUIT
#define DEVICE_VER      0x0001 
#define MANUFACTURER    OwLab 
#define PRODUCT         SUIT80

/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 15

/* Keyboard Matrix Assignments */
#define MATRIX_ROW_PINS { E6, B0, B7, D0, D1, D2 }
#define MATRIX_COL_PINS { D5, D4, D6, D7, B4, B5, B6, C6, C7, F4, F7, F6, F5, F1, F0 }

/* COL2ROW, ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5
#define TAPPING_TERM 300

// #define DYNAMIC_KEYMAP_LAYER_COUNT 5
// #define TRANSIENT_EEPROM_SIZE 5120

/* NKRO */
#ifdef NKRO_ENABLE
#         define FORCE_NKRO
#endif