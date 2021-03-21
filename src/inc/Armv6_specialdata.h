/**
 * \file Armv6_specialdata.h
 * \brief This file contains the declaration of functions for special data instruction group.
 *
 * \author Ricardo Benitez
 *
 * This file is part of ArmEmulation which is released under MIT Licence.
 * See file LICENSE for full license details.
 **/

#ifndef ARMv6_SPECIAL_DATA_H
#define ARMv6_SPECIAL_DATA_H

#include "Cpu.h"

/// \brief
/// Function to execute special data group instructions
void execute_special_data(CPU* cpu, const Instruction* instruction);

#endif /* ARMv6_SPECIAL_DATA_H */

