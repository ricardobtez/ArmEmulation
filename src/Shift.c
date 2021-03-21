/**
 * \file Armv6_shift.c
 * \brief This file contains the definition for the shift instruction group
 *
 * \author Ricardo Benitez
 *
 * This file is part of ArmEmulation which is released under MIT Licence.
 * See file LICENSE for full license details.
 **/

#include <stdio.h>
#include "Armv6_shift.h"

typedef enum ShiftGroup_t
{
    MOV_R,      // Move Register
    LSL_IM,     // Logical Shift Left
    LSR_IM,     // Logical Shift Right
    ASR_IM,     // Arithmetic Shift Right
    ADD_R,      // Add register
    SUB_R,      // Substract register
    ADD_IM_3,   // Add 3-bit immediate
    SUB_IM_3,   // Substract 3-bit immediate
    MOV_IM,     // Move
    CMP_IM,     // Compare
    ADD_IM_8,   // Add 8-bit immediate
    SUB_IM_8,   // Substract 8-bit immediate
    INVALID_MNEMONIC
}ShiftGroup_t;

struct ShiftInstPattern_t
{
    uint8_t pattern;
    uint8_t mask;
    ShiftGroup_t group;
}ShiftInstPattern_t;

/// \brief
/// Static function to determine the shift Instruction group
static ShiftGroup_t decodeInstruction(const Instruction* instruction);

/// \brief
/// Pattern used with the Shift.opcode struct data element
const struct ShiftInstPattern_t shift_inst_pattern[] =
{
    {0x00, 0x1C, LSL_IM},   // 0b0_00xx
    {0x04, 0x1C, LSR_IM},   // 0b0_01xx
    {0x80, 0x1C, ASR_IM},   // 0b0_10xx
    {0x10, 0x1C, MOV_IM},   // 0b1_00xx
    {0x14, 0x1C, CMP_IM},   // 0b1_01xx
    {0x18, 0x1C, ADD_IM_8}, // 0b1_10xx
    {0x1C, 0x1C, SUB_IM_8},  // 0b1_11xx
    {0xC0, 0x1F, ADD_R},    // 0b0_1100
    {0x0D, 0x1F, SUB_R},    // 0b0_1101
    {0x0E, 0x1F, ADD_IM_3}, // 0b0_1110
    {0x0F, 0x1F, SUB_IM_3}, // 0b0_1111
};

void execute_shift(CPU* cpu, const Instruction* instruction)
{
    (void)cpu;
    (void)instruction;
    ShiftGroup_t group = decodeInstruction(instruction);

    switch (group)
    {
        case MOV_R:
            break;

        case LSL_IM:
            break;

        case LSR_IM:
            break;

        case ASR_IM:
            break;

        case ADD_R:
            break;

        case SUB_R:
            break;

        case ADD_IM_3:
            break;

        case SUB_IM_3:
            break;

        case MOV_IM:
            break;

        case CMP_IM:
            break;

        case ADD_IM_8:
            break;

        case SUB_IM_8:
            break;

        default:
            printf("execute_shift(): Invalid instruction group\n");
            break;
    }
}

ShiftGroup_t decodeInstruction(const Instruction* instruction)
{
    ShiftGroup_t group = INVALID_MNEMONIC;
    uint16_t it = sizeof(shift_inst_pattern) / sizeof(ShiftInstPattern_t) - 1;
    uint8_t maskedInstruction = 0x00;

    while (INVALID_MNEMONIC == group)
    {
        maskedInstruction = instruction->shift.opcode &
                            shift_inst_pattern[it].mask;

        if (shift_inst_pattern[it].pattern == maskedInstruction)
        {
            group = shift_inst_pattern[it].group;
        }
        --it;
    }

    return group;
}

