/**
 * \file test_cpu.c
 * \brief This file contains the test CPU implementation for the Armv6 cpu
 *
 * \author Ricardo Benitez
 *
 * This file is part of ArmEmulation which is released under MIT Licence.
 * See file LICENSE for full license details.
 **/

#include "test_cpu.h"
#include "Armv6_cpu.h"

/// \brief
/// Array of Unit tests to be run by the program. ADD here
const struct CMUnitTest cpu_small_tests[] =
{
    cmocka_unit_test(create_cpu_test),
    cmocka_unit_test(reset_cpu_test),
    cmocka_unit_test(decode_shift_test),
    cmocka_unit_test(decode_data_processing_test),
    cmocka_unit_test(decode_special_data_test)
};


void create_cpu_test(void **state)
{
    (void)state;
    CPU* cpu = create_cpu();
    assert_non_null(cpu);
}

void reset_cpu_test(void **state)
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

void decode_shift_test(void **state)
{
    (void)state;
    Instruction inst;
    // Create the instruction with 2 Most significant bits as 0
    inst.rawData = 0x3FFF;
    InstructionGroup_t group = decodeInstruction(&inst);
    assert_int_equal(SHIFT_GROUP, group);
}

void decode_data_processing_test(void **state)
{
    (void)state;
    Instruction inst;
    // 0b0100_00xx_xxxx_xxxx
    inst.rawData = 0x43FF;
    InstructionGroup_t group = decodeInstruction(&inst);
    assert_int_equal(DATA_PROCESSING_GROUP, group);
}

void decode_special_data_test(void **state)
{
    (void)state;
    Instruction inst;
    // 0b0100_01xx_xxxx_xxxx
    inst.rawData = 0x47FF;
    InstructionGroup_t group = decodeInstruction(&inst);
    assert_int_equal(SPECIAL_DATA_GROUP, group);
}

