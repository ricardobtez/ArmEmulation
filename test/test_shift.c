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
    cmocka_unit_test(decode_shift_lsl_imm_small_test),
    cmocka_unit_test(decode_shift_lsr_imm_small_test),
    cmocka_unit_test(execute_shift_lsl_imm_small_test),
    cmocka_unit_test(execute_shift_lsr_imm_small_test)
};


/***********************************************************
 * Decode test cases 
 **********************************************************/
void decode_shift_lsl_imm_small_test(void **state)
{
    (void)state;
    Instruction inst;
    // 0b0000_0xxx_xxxx_xxxx
    inst.rawData = 0x07FF;
    ShiftGroup_t group = decode_shift(&inst);
    assert_int_equal(LSL_IM, group);
}

void decode_shift_lsr_imm_small_test(void **state)
{
    (void)state;
    Instruction inst;
    // 0b0000_1xxx_xxxx_xxxx
    inst.rawData = 0x0FFF;
    ShiftGroup_t group = decode_shift(&inst);
    assert_int_equal(LSR_IM, group);
}

void decode_shift_asr_imm_small_test(void **state)
{
    (void)state;
    Instruction inst;
    // 0b0001_0xxx_xxxx_xxxx
    inst.rawData = 0x17FF;
    ShiftGroup_t group = decode_shift(&inst);
    assert_int_equal(ASR_IM, group);
}


/***********************************************************
 * Execute test cases 
 **********************************************************/
void execute_shift_lsl_imm_small_test(void **state)
{
    (void)state;
    CPU* cpu = create_cpu();
    Instruction inst;
    Word oldSourceRegister;

    reset_cpu(cpu);
    cpu->R2 = 4;
    cpu->R3 = 12;
    oldSourceRegister = cpu->R2;
    // LSL Immediate of 4 from Register R2 to R3
    // 15 14 13 12 11 10  9  8  7  6  5  4  3  2  1  0
    // ^-----LSL----^ ^----imm5----^  ^--Rm-^  ^--Rd-^
    //  0  0  0  0  0  0  0  1  0  0  0  1  0  0  1  1
    inst.rawData = 0x0113;
    execute_logical_shift(cpu, &inst, LSL_IM);

    // Check that the destination changed and source remains the same
    assert_int_equal(64, cpu->R3);
    assert_int_equal(oldSourceRegister, cpu->R2);
}

void execute_shift_lsr_imm_small_test(void **state)
{
    (void)state;
    CPU* cpu = create_cpu();
    Instruction inst;
    Word oldSourceRegister;

    reset_cpu(cpu);
    cpu->R4 = 2532;
    cpu->R1 = 540;
    oldSourceRegister = cpu->R4;
    // LSL Immediate of 3 from Register R4 to R1
    // 15 14 13 12 11 10  9  8  7  6  5  4  3  2  1  0
    // ^-----LSL----^ ^----imm5----^  ^--Rm-^  ^--Rd-^
    //  0  0  0  0  0  0  0  0  1  1  1  0  0  0  0  1
    inst.rawData = 0x00E1;
    execute_logical_shift(cpu, &inst, LSR_IM);

    // Check that the destination changed and source remains the same
    assert_int_equal(316, cpu->R1);
    assert_int_equal(oldSourceRegister, cpu->R4);
}

void execute_shift_asr_imm_small_test(void **state)
{
    (void)state;
    CPU* cpu = create_cpu();
    Instruction inst;
    Word oldSourceRegister;

    reset_cpu(cpu);
    cpu->R6 = 420;
    cpu->R0 = 15535;
    oldSourceRegister = cpu->R6;
    // ASR Immediate of 2 from Register R6 to R0
    // 15 14 13 12 11 10  9  8  7  6  5  4  3  2  1  0
    // ^----ASR-----^ ^----imm5----^  ^--Rm-^  ^--Rd-^
    //  0  0  0  1  0  0  0  0  1  0  0  0  0  0  0  0
    inst.rawData = 0x1080;
    execute_logical_shift(cpu, &inst, ASR_IM);

    // Check thea tthe destination changed and source remains the same
    assert_int_equal(105, cpu->R0);
    assert_int_equal(oldSourceRegister, cpu->R6);
}

