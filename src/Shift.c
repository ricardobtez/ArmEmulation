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
    {0x1C, 0x1C, SUB_IM_8}, // 0b1_11xx
    {0xC0, 0x1F, ADD_R},    // 0b0_1100
    {0x0D, 0x1F, SUB_R},    // 0b0_1101
    {0x0E, 0x1F, ADD_IM_3}, // 0b0_1110
    {0x0F, 0x1F, SUB_IM_3}, // 0b0_1111
};

void execute_shift(CPU* cpu, const Instruction* instruction)
{
    (void)cpu;
    (void)instruction;
    ShiftGroup_t group = decode_shift(instruction);

    switch (group)
    {
        case MOV_R:
            break;

        // Intentional fall through as they are treated by the same function
        case LSL_IM:
        case LSR_IM:
            execute_logical_shift(cpu, instruction, group);
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

ShiftGroup_t decode_shift(const Instruction* instruction)
{
    ShiftGroup_t group = INVALID_MNEMONIC;
    uint16_t it = sizeof(shift_inst_pattern) / sizeof(ShiftInstPattern_t) - 1;
    int32_t maskedInstruction = 0x00;

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

void execute_logical_shift(CPU* cpu,
                           const Instruction* instruction,
                           const ShiftGroup_t group)
{
    ShiftEnum_t inst;
    Word* sourceRegister = NULL;
    Word* destinationRegister = NULL;
    Word temporalVariable = 0;

    inst.rawData = instruction->rawData;

    // The instruction actually is MOV
    if ( (0 == inst.logical_shift.opcode) &&
         (0 == inst.logical_shift.imm5))
    {
        // Call the MOV (register instruction)
    }
    else
    {
        // Gets the address of where the R0...R7 is within the CPU struct
        sourceRegister = (&cpu->R0) + (inst.logical_shift.Rm * sizeof(Word));
        destinationRegister = (&cpu->R0) + (inst.logical_shift.Rd * sizeof(Word));

        switch (group)
        {
            case LSL_IM:
                temporalVariable = (*sourceRegister) >> inst.logical_shift.imm5;
                break;

            case LSR_IM:
                temporalVariable = (*sourceRegister) << inst.logical_shift.imm5;
                break;

            default:
                break;
        }
        *destinationRegister = temporalVariable;
        cpu->STATUS.APSR.N = (unsigned char)(temporalVariable & 0x80000000);
        cpu->STATUS.APSR.Z = (temporalVariable == 0) ? 1 : 0;
        cpu->STATUS.APSR.C = 0;
    }
}

