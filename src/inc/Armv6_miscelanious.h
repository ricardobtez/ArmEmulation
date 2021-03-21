/**
 * \file Armv6_miscelanious.h
 * \brief This file contains the declaration of functions for miscelanious instruction group.
 *
 * \author Ricardo Benitez
 *
 * This file is part of ArmEmulation which is released under MIT Licence.
 * See file LICENSE for full license details.
 **/

#ifndef ARMv6_MISCELANIOUS_H
#define ARMv6_MISCELANIOUS_H

#include "Cpu.h"

/// \brief
/// Function to execute miscelanious group instructions
void execute_miscelanious(CPU* cpu, const Instruction* instruction);

#endif /* ARMv6_MISCELANIOUS_H */

