/*
 * This file is part of the Micro Python project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2021 Dan Halbert for Adafruit Industries
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef MICROPY_INCLUDED_SHARED_MODULE_KEYPAD_SHIFTREGISTERKEYS_H
#define MICROPY_INCLUDED_SHARED_MODULE_KEYPAD_SHIFTREGISTERKEYS_H

#include "py/obj.h"
#include "py/objtuple.h"

#include "common-hal/digitalio/DigitalInOut.h"
#include "shared-module/keypad/__init__.h"
#include "shared-module/keypad/EventQueue.h"

typedef struct {
    KEYPAD_SCANNER_COMMON_FIELDS;
    digitalio_digitalinout_obj_t *clock;
    digitalio_digitalinout_obj_t *latch;
    mp_obj_tuple_t *data_pins;
    mp_uint_t *key_counts;
    mp_uint_t num_key_counts;
    mp_uint_t max_key_count;
    bool value_when_pressed;
    bool value_to_latch;
} keypad_shiftregisterkeys_obj_t;

void keypad_shiftregisterkeys_scan(keypad_shiftregisterkeys_obj_t *self);

#endif  // MICROPY_INCLUDED_SHARED_MODULE_KEYPAD_SHIFTREGISTERKEYS_H
