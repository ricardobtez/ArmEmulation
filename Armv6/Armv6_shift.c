/**
 * \file Armv6_shift.c
 * \brief This file contains the definition for the shift instruction group
 *
 * \author Ricardo Benitez
 *
 * This file is part of ArmEmulation which is released under MIT Licence.
 * See file LICENSE for full license details.
 **/

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



void execute_shift(CPU* cpu, const Instruction* instruction)
{

}

