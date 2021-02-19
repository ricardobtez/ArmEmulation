/**
 * \file Armv6_loadstoresingle.h
 * \brief This file contains the declaration of functions for load store single instruction group.
 *
 * \author Ricardo Benitez
 *
 * This file is part of ArmEmulation which is released under MIT Licence.
 * See file LICENSE for full license details.
 **/

#ifndef ARMv6_LOAD_STORE_SINGLE_H
#define ARMv6_LOAD_STORE_SINGLE_H

#include "Armv6_cpu.h"

/// \brief
/// Function to execute load store single group instructions
void execute_load_store_single(CPU* cpu, const Instruction* instruction);

#endif /* ARMv6_LOAD_STORE_SINGLE_H */

