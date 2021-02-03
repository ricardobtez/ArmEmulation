/**
 * \file Armv6_cpu.c
 * \brief This file contains the definition for the CPU emulation
 *
 * \author Ricardo Benitez
 *
 * This file is part of ArmEmulation which is released under MIT Licence.
 * See file LICENSE for full license details.
 **/

#include <stdio.h>
#include "Armv6_cpu.h"
#include "Armv6_shift.h"
#include "Armv6_dataprocessing.h"
#include "Armv6_specialdata.h"
#include "Armv6_loadstoresingle.h"
#include "Armv6_miscelanious.h"
#include "Armv6_conditionalbranch.h"

typedef enum InstructionGroup_t
{
    SHIFT_GROUP                 = 1,
    DATA_PROCESSING_GROUP       = 2,
    SPECIAL_DATA_GROUP          = 3,
    LOAD_STORE_SINGLE_GROUP     = 4,
    GENERATE_RELATIVE_ADD_GROUP = 5,
    LOAD_STORE_MULTIPLE_GROUP   = 6,
    MISCELANIOUS_GROUP          = 7,
    CONDITIONAL_BRANCH_GROUP    = 8,
    UNCONDITIONAL_BRANCH_GROUP  = 9,
    INVALID_INSTRUCTION_GROUP
}InstructionGroup_t;

struct InstructionPattern_t
{
    uint8_t pattern;
    uint8_t mask;
    InstructionGroup_t group;
}InstructionPattern_t;

const struct InstructionPattern_t InstructionPattern[] =
{
    {0x00, 0xC0, SHIFT_GROUP},                 // 0b00xx_xx
    {0x60, 0xE0, LOAD_STORE_SINGLE_GROUP},     // 0b011x_xx
    {0x80, 0xE0, LOAD_STORE_SINGLE_GROUP},     // 0b100x_xx
    {0x41, 0xF0, LOAD_STORE_SINGLE_GROUP},     // 0b0101_xx
    {0xB0, 0xF0, MISCELANIOUS_GROUP},          // 0b1011_xx
    {0xD0, 0xF0, CONDITIONAL_BRANCH_GROUP},    // 0b1101_xx
    {0xA0, 0xF8, GENERATE_RELATIVE_ADD_GROUP}, // 0b1010_0x
    {0xA8, 0xF8, GENERATE_RELATIVE_ADD_GROUP}, // 0b1010_1x
    {0x48, 0xF8, LOAD_STORE_SINGLE_GROUP},     // 0b0100_1x
    {0xC0, 0xF8, LOAD_STORE_MULTIPLE_GROUP},   // 0b1100_0x
    {0xC8, 0xF8, LOAD_STORE_MULTIPLE_GROUP},   // 0b1100_1x
    {0xE0, 0xF8, UNCONDITIONAL_BRANCH_GROUP},  // 0b1101_xx
    {0x80, 0xFC, DATA_PROCESSING_GROUP},       // 0b0100_00
    {0x44, 0xFC, SPECIAL_DATA_GROUP}           // 0b0100_01
};

/// \brief
/// Static function to determine the Instruction group
static InstructionGroup_t decodeInstruction(const Instruction* instruction);

void execute(CPU* cpu, const Instruction* instruction)
{
    if (!cpu || !instruction)
    {
        return;
    }

    InstructionGroup_t group = decodeInstruction(instruction);

    switch(group)
    {
        case SHIFT_GROUP:
            execute_shift(cpu, instruction);
            break;

        case DATA_PROCESSING_GROUP:
            execute_data_processing(cpu, instruction);
            break;

        case SPECIAL_DATA_GROUP:
            execute_special_data(cpu, instruction);
            break;

        case LOAD_STORE_SINGLE_GROUP:
            execute_load_store_single(cpu, instruction);
            break;

        case MISCELANIOUS_GROUP:
            execute_miscelanious(cpu, instruction);
            break;

        case CONDITIONAL_BRANCH_GROUP:
            execute_conditional_branch(cpu, instruction);
            break;

        default:
            printf("execute(): Invalid instruction group\n");
            break;
    }
}


InstructionGroup_t decodeInstruction(const Instruction* instruction)
{
    InstructionGroup_t group = INVALID_INSTRUCTION_GROUP;
    uint16_t it = sizeof(InstructionPattern) /sizeof(InstructionPattern_t) - 1;
    uint8_t masked_instruction = 0x0000;

    while (it >= 0 && INVALID_INSTRUCTION_GROUP == group)
    {
        masked_instruction = ((uint8_t)(instruction->rawData >> 8)) & InstructionPattern[it].mask;

        if (masked_instruction == InstructionPattern[it].pattern)
        {
            group = InstructionPattern[it].group;
        }
        --it;
    }

    return group;
}

