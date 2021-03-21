/**
 * \file Armv6_conditionalbranch.h
 * \brief This file contains the declaration of functions for conditional branch instruction group.
 *
 * \author Ricardo Benitez
 *
 * This file is part of ArmEmulation which is released under MIT Licence.
 * See file LICENSE for full license details.
 **/

#ifndef ARMv6_CONDITIONAL_BRANCH_H
#define ARMv6_CONDITIONAL_BRANCH_H
#include "Cpu.h"

/// \brief
/// Function to execute conditional branch group instructions
void execute_conditional_branch(CPU* cpu, const Instruction* instruction);

#endif /* ARMv6_CONDITIONAL_BRANCH_H */

