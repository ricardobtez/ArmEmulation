/**
 * \file Armv6_dataprocessing.h
 * \brief This file contains the declaration of functions for data processing instruction group.
 *
 * \author Ricardo Benitez
 *
 * This file is part of ArmEmulation which is released under MIT Licence.
 * See file LICENSE for full license details.
 **/

#ifndef ARMv6_DATA_PROCESSING_H
#define ARMv6_DATA_PROCESSING_H

#include "Cpu.h"

/// \brief
/// Function to execute data processing group instructions
void execute_data_processing(CPU* cpu, const Instruction* instruction);

#endif /* ARMv6_DATA_PROCESSING_H */

