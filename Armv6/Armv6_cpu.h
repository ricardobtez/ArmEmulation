#ifndef ARMv6_CPU_H
#define ARMv6_CPU_H

#include "Armv6_types.h"

/// \brief
/// Application Program Status Register
typedef struct APSR_t
{
    Word RESERVED : 25;
    Word V : 1; // Overflow condition code flag
    Word C : 1; // Carry condition code flag
    Word Z : 1; // Zero condition code flag
    Word N : 1; // Negative condition flag
}APSR_t;

/// \brief
/// Interrupt Program Status Register
typedef struct IPSR_t
{
    Word IPSR : 6;
    Word RESERVED : 26;
}IPSR_t;

/// \brief
/// Execution Program Status Register
typedef struct EPSR_t
{
    Word RESERVED : 23;
    Word T : 1;
    Word RESERVED : 7;
}EPSR_t;

/// \brief
/// See page 187 for reference
typedef union xPSR
{
    APSR_t APSR;
    IPSR_t IPSR;
    EPSR_t EPSR;
}xPSR;

/// \brief
/// Special purpose Mask register
typedef struct Primask_t
{
    Word PM : 1;
    Word RESERVED : 31;
}Primask_t;

/// \brief
/// 2-bit special purpose register
typedef struct Control_t
{
    Byte Control : 2;
    Byte RESERVED : 6;
}Control_t;

/// \brief
//// The CPU registers of the ARMv6-M
typedef struct CPU
{
    // Start of the ARM core registers (R0 - R15
    Word R0; // Start of registers on page b1-186
    Word R1;
    Word R2;
    Word R3;
    Word R4;
    Word R5;
    Word R6;
    Word R7;
    Word R8;
    Word R9;
    Word R10;
    Word R11;
    Word R12; // End of registers on page B1-186

    Word MSP; // Main Stack pointer (R13)
    //short PSP; // Process Stack pointer (banked)
    Word LR; // Link register (R14)

    Word PC; // Program Counter (R15)
    // End of the ARM core registers (R0 - R15)

    // Status registers
    xPSR STATUS;

    // Special purpose registers
    Primask_t PRIMASK;
    Control_t CONTROL; // 2-bit special purpose register
}CPU;

/*
 * Thumb instructions set encoding is a sequence of halfword-aligned halfwords.
 * Each Thumb instruction are either a single 16-bit halfword in that stream,
 * or a 32-bit instruction consisting of two consecutive halfwords in that stream.
 * If bits [15:11] of the halfword being decoded take any of the following values
 * the halfword is the first halfword of a 32-bit instruction:
 * 0b11101
 * 0b11110
 * 0b11111
 * Otherwise, the halfword is a  16-bit instruction
 */

/* opcodes
 * 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0
 * ^-----opcode-----^
 *
 * 00xxxx -> Shift (immediate), add, substract, move, and compare
 * 010000 -> Data processing
 * 010001 -> Special data instructions and branch exchange
 * 01001x -> Load from Literal Pool 
 * 0101xx
 * 011xxx
 * 100xxx -> Load/Store single data item
 * 10100x -> Generate PC relative address
 * 10101x -> Generate SP relative address
 * 1011xx -> Miscelaneous 16 bit instructions
 * 11000x -> Store multiple registers
 * 11001x -> Load multiple registers
 * 1101xx -> Conditional branch
 * 11100x -> Unconditional branch
 */

typedef struct Shift
{
    Halfword predicate : 9;
    Halfword opcode : 5;
    Halfword groupOpcode : 2; 
}Shift;

typedef struct DataProcessing
{
    Halfword predicate : 6;
    Halfword opcode : 4;
    Halfword groupOpcode : 6;
}DataProcessing;

typedef struct SpecialData
{
    Halfword predicate : 6;
    Halfword opcode : 4;
    Halfword groupOpcode : 6;
}SpecialData;

typedef struct LoadStoreSingle
{
    Halfword predicate : 9;
    Halfword opB : 3;
    Halfword opA : 4;
}LoadStoreSingle;

typedef struct Miscelanious
{
    Halfword predicate : 5;
    Halfword opcode : 7; // Hint instruction could be 1111xxx
    Halfword groupOpcode : 4;
}Miscelanious;

typedef struct Hint
{
    Halfword opB : 4;
    Halfword obA : 4;
    Halfword groupOpcode : 8;
}Hint;

typedef struct ConditionalBranch
{
    Halfword predicate : 8;
    Halfword opcode : 4;
    Halfword groupOpcode : 4;
}ConditionalBranch;

typedef union Instruction
{
    // Start 16-bit instructions
    Shift shift;
    DataProcessing dataProcessing;
    SpecialData specialData;
    LoadStoreSingle loadStoreSingle;
    Miscelanious miscelanious;
    Hint hint;
    ConditionalBranch conditionalBranch
    // End 16 bit instructions

    // Start 32-bit instructions
    // End 32-bit instructions
    Halfword rawData;
}Instruction;

/// \brief
/// Execute an execution with corresponding CPU in a single Tick
void execute(CPU* cpu, const Instruction* instruction);


#endif /* ARMv6_CPU_H */

