/**
 * \file test_main.c
 * \brief This file contains the main function for the unit tests
 *
 * \author Ricardo Benitez
 *
 * This file is part of ArmEmulation which is released under MIT Licence.
 * See file LICENSE for full license details.
 **/
#include "Cpu.h"
#include "test_common.h"
#include "test_cpu.h"
#include "test_shift.h"

/* A test case that does nothing and succeeds. */
static void null_test_success(void **state)
{
    (void)state; /* unused */
}

int main(void)
{
    int error = 0;
    const struct CMUnitTest tests[] =
    {
        cmocka_unit_test(null_test_success)
    };
    error = cmocka_run_group_tests(tests, NULL, NULL);
    error |= cmocka_run_group_tests(cpu_small_tests, NULL, NULL);
    //error |= cmocka_run_group_tests(cpu_shift_small_tests, NULL, NULL);
    return error;
}
