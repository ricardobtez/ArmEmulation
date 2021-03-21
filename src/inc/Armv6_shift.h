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
/// Function to execute shift instructions
void execute_shift(CPU* cpu, const Instruction* instruction);

#endif /* ARMv6_SHIFT_H */

