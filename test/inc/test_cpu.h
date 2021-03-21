/**
 * \file test_cpu.h
 * \brief This file contains the test CPU specification for the Armv6 cpu
 *
 * \author Ricardo Benitez
 *
 * This file is part of ArmEmulation which is released under MIT Licence.
 * See file LICENSE for full license details.
 **/
#ifndef TEST_CPU_H
#define TEST_CPU_H

#include "test_common.h"

void create_cpu_test(void **state);
void reset_cpu_test(void **state);
void decode_shift_test(void **state);


extern const struct CMUnitTest cpu_small_tests[3];

#endif /* TEST_CPU_H */

