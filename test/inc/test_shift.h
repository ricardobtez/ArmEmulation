/**
 * \file test_shift.h
 * \brief This file contains the test Shift instruction specification for 
 * the Armv6 cpu
 *
 * \author Ricardo Benitez
 *
 * This file is part of ArmEmulation which is released under MIT Licence.
 * See file LICENSE for full license details.
 **/
#ifndef TEST_SHIFT_H
#define TEST_SHIFT_H

#include "test_common.h"

void decode_shift_lsl_imm_small_test(void **state);
void decode_shift_lsr_imm_small_test(void **state);
void execute_shift_lsl_imm_small_test(void **state);

extern const struct CMUnitTest cpu_shift_small_tests[3];

#endif /* TEST_SHIFT_H */

