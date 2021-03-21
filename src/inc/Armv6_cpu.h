/**
 * \file Armv6_cpu.h
 * \brief This file contains the CPU specification for the Armv6 cpu
 *
 * \author Ricardo Benitez
 *
 * This file is part of ArmEmulation which is released under MIT Licence.
 * See file LICENSE for full license details.
 **/

#ifndef ARMv6_CPU_H
#define ARMv6_CPU_H

#include "Cpu.h"

/// \brief
/// Enumeration with the instruction groups available
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

typedef struct InstructionPattern_t
{
    uint8_t pattern;            // The pattern of the instruction
    uint8_t mask;               // To take into account only valid bits
    InstructionGroup_t group;   // The assigned group of that pattern
}InstructionPattern_t;

/// \brief
/// Static function to determine the Instruction group
InstructionGroup_t decodeInstruction(const Instruction* instruction);

#endif /* ARMv6_CPU_H */

