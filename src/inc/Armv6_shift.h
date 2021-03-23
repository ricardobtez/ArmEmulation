/**
 * \file Armv6_shift.h
 * \brief This file contains the declaration of functions for the shift instruction group.
 *
 * \author Ricardo Benitez
 *
 * This file is part of ArmEmulation which is released under MIT Licence.
 * See file LICENSE for full license details.
 **/

#ifndef ARMv6_SHIFT_H
#define ARMv6_SHIFT_H

#include "Cpu.h"

/// \brief
/// Enumeration to denote the mnemonic of the instruction to execute
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

/// \brief
/// Struct with the Logical shift instruction
typedef struct LogicalShift_t
{
    Halfword opcode : 5;
    Halfword imm5 : 5;
    Halfword Rm : 3;
    Halfword Rd : 3;
}LogicalShift_t;

/// \brief
/// Union with all the possible Shift Instructions groups
typedef union ShiftEnum_t
{
    LogicalShift_t logical_shift;
    Halfword rawData;
}ShiftEnum_t;

typedef struct ShiftInstPattern_t
{
    uint8_t pattern;
    uint8_t mask;
    ShiftGroup_t group;
}ShiftInstPattern_t;

/// \brief
/// Function to execute shift instructions
void execute_shift(CPU* cpu, const Instruction* instruction);

/// \brief
/// Execute LSL instructions
void execute_logical_shift(CPU* cpu,
                           const Instruction* instruction,
                           const ShiftGroup_t group);

/// \brief
/// Function to determine the shift Instruction group
ShiftGroup_t decode_shift(const Instruction* instruction);

#endif /* ARMv6_SHIFT_H */

