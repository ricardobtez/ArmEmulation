#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "Armv6_cpu.h"

/* A test case that does nothing and succeeds. */
static void null_test_success(void **state)
{
    (void)state; /* unused */
}

static void create_cpu_test(void **state)
{
    (void)state;
    CPU* cpu = create_cpu();
    assert_non_null(cpu);
}

static void reset_cpu_test(void **state)
{
    (void)state;
    CPU* cpu = create_cpu();
    reset_cpu(cpu);
    assert_int_equal(cpu->R0, 0);
    assert_int_equal(cpu->R1, 0);
    assert_int_equal(cpu->R2, 0);
    assert_int_equal(cpu->R3, 0);
    assert_int_equal(cpu->R4, 0);
    assert_int_equal(cpu->R5, 0);
    assert_int_equal(cpu->R6, 0);
    assert_int_equal(cpu->R7, 0);
    assert_int_equal(cpu->R8, 0);
    assert_int_equal(cpu->R9, 0);
    assert_int_equal(cpu->R10, 0);
    assert_int_equal(cpu->R11, 0);
    assert_int_equal(cpu->R12, 0);
    assert_int_equal(cpu->MSP, 0);
    assert_int_equal(cpu->LR, 0);
    assert_int_equal(cpu->PC, 0);
    assert_int_equal(cpu->STATUS.APSR.V, 0);
    assert_int_equal(cpu->PRIMASK.PM, 0);
    assert_int_equal(cpu->CONTROL.Control, 0);
}

/*static void execute_shift_opcode_test(void **state)
{
    (void)state;
    CPU* cpu = create_cpu();
    reset_cpu(cpu);
    // Create the instructio with 2 Most significant bits as 0
    // 0b0011_1111
    Instruction ins = {0x3F};
    execute(cpu, &ins);
}*/

int main(void)
{
    const struct CMUnitTest tests[] =
    {
        cmocka_unit_test(null_test_success),
        cmocka_unit_test(create_cpu_test),
        cmocka_unit_test(reset_cpu_test)
        //cmocka_unit_test(execute_shift_opcode_test)
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
