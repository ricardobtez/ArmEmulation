/**
 * \file Armv6_memory.h
 * \brief This file contains the declaration of the memory for Armv6 Cortex-M0 plus
 *
 * \author Ricardo Benitez
 *
 * This file is part of ArmEmulation which is released under MIT Licence.
 * See file LICENSE for full license details.
 **/

#ifndef ARMv6_MEMORY_H
#define ARMv6_MEMORY_H

#include "Armv6_types.h"

// The maximum flat address space (2^32 8 bit data)
#define MAX_ADDRESSABLE_MEMORY      (4_294_967_296 * 8)

Byte memory[1024];

#endif /* ARMv6_MEMORY_H */

