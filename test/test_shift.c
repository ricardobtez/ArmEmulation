/**
 * \file test_shift.c
 * \brief This file contains the test for the Shift Instruction
 *
 * \author Ricardo Benitez
 *
 * This file is part of ArmEmulation which is released under MIT Licence.
 * See file LICENSE for full license details.
 **/

#include "test_shift.h"
#include "Armv6_shift.h"

const struct CMUnitTest cpu_shift_small_tests[] =
{
    cmocka_unit_test(decode_shift_lsl_test),
    cmocka_unit_test(decode_shift_lsr_test)
    //cmocka_unit_test(execute_shift_lsl_test)
};

void decode_shift_lsl_test(void **state)
{
    (void)state;
    Instruction inst;
    // 0b0000_0xxx_xxxx_xxxx
    inst.rawData = 0x07FF;
    ShiftGroup_t group = decode_shift(&inst);
    assert_int_equal(LSL_IM, group);
}

void decode_shift_lsr_test(void **state)
{
    (void)state;
    Instruction inst;
    // 0b0000_1xxx_xxxx_xxxx
    inst.rawData = 0x0FFF;
    ShiftGroup_t group = decode_shift(&inst);
    assert_int_equal(LSR_IM, group);
}

/*void execute_shift_lsl_test(void **state)
{
    (void)state;
    CPU* cpu = create_cpu();
    Instruction inst;
    Word oldSourceRegister;

    reset_cpu(cpu);
    cpu->R2 = 4;
    cpu->R3 = 12;
    oldSourceRegister = cpu->R2;
    // LSL Immediate of 4 to Register R2 to R3
    // 15 14 13 12 11 10  9  8  7  6  5  4  3  2  1  0
    // ^-----LSL----^ ^----imm5----^  ^--Rm-^  ^--Rd-^
    //  0  0  0  0  0  0  0  1  0  0  0  1  0  0  1  1
    inst.rawData = 0x0113;
    execute_instruction(cpu, &inst);

    // Check that the destination changed and source remains the same
    assert_int_equal(16, cpu->R3);
    assert_int_equal(oldSourceRegister, cpu->R2);
}*/

