
#include <stdio.h>
#include "Armv6_cpu.h"

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

struct InstructionPattern_t
{
    uint8_t pattern;
    uint8_t size;
    InstructionGroup_t group;
}InstructionPattern_t;

const struct InstructionPattern_t InstructionPattern[] =
{
    {0x00, 2, SHIFT_GROUP},                 // 0b00xx_xx
    {0x60, 3, LOAD_STORE_SINGLE_GROUP},     // 0b011x_xx
    {0x80, 3, LOAD_STORE_SINGLE_GROUP},     // 0b100x_xx
    {0x41, 4, LOAD_STORE_SINGLE_GROUP},     // 0b0101_xx
    {0xB0, 4, MISCELANIOUS_GROUP},          // 0b1011_xx
    {0xD0, 4, CONDITIONAL_BRANCH_GROUP},    // 0b1101_xx
    {0xA0, 5, GENERATE_RELATIVE_ADD_GROUP}, // 0b1010_0x
    {0xA8, 5, GENERATE_RELATIVE_ADD_GROUP}, // 0b1010_1x
    {0x48, 5, LOAD_STORE_SINGLE_GROUP},     // 0b0100_1x
    {0xC0, 5, LOAD_STORE_MULTIPLE_GROUP},   // 0b1100_0x
    {0xC8, 5, LOAD_STORE_MULTIPLE_GROUP},   // 0b1100_1x
    {0xE0, 5, UNCONDITIONAL_BRANCH_GROUP},  // 0b1101_xx
    {0x80, 6, DATA_PROCESSING_GROUP},       // 0b0100_00
    {0x44, 6, SPECIAL_DATA_GROUP}           // 0b0100_01
};

/// \brief
/// Static function to determine the Instruction group
static InstructionGroup_t decodeInstruction(const Instruction* instruction);

/// \brief
/// Static function to execute shift instructions
static void execute_shift(CPU* cpu, const Instruction* instruction);

/// \brief
/// Static function to execute data processing group instructions
static void execute_data_processing(CPU* cpu, const Instruction* instruction);

/// \brief
/// Static function to execute special data group instructions
static void execute_special_data(CPU* cpu, const Instruction* instruction);

/// \brief
/// Static function to execute load store single group instructions
static void execute_load_store_single(CPU* cpu, const Instruction* instruction);

/// \brief
/// Static function to execute miscelanious group instructions
static void execute_miscelanious(CPU* cpu, const Instruction* instruction);

/// \brief
/// Static function to execute conditional branch group instructions
static void execute_conditional_branch(CPU* cpu, const Instruction* instruction);

void execute(CPU* cpu, const Instruction* instruction)
{
    if (!cpu || !instruction)
    {
        return;
    }

    InstructionGroup_t group = decodeInstruction(instruction);

    switch(group)
    {
        case SHIFT_GROUP:
            execute_shift(cpu, instruction);
            break;

        case DATA_PROCESSING_GROUP:
            execute_data_processing(cpu, instruction);
            break;

        case SPECIAL_DATA_GROUP:
            execute_special_data(cpu, instruction);
            break;

        case LOAD_STORE_SINGLE_GROUP:
            execute_load_store_single(cpu, instruction);
            break;

        case MISCELANIOUS_GROUP:
            execute_miscelanious(cpu, instruction);
            break;

        case CONDITIONAL_BRANCH_GROUP:
            execute_conditional_branch(cpu, instruction);
            break;

        default:
            printf("execute(): Invalid instruction group\n");
            break;
    }
}


InstructionGroup_t decodeInstruction(const Instruction* instruction)
{
    InstructionGroup_t group = INVALID_INSTRUCTION_GROUP;
    uint16_t it = 0;
    const uint16_t MAX_OPCODE_SIZE = 
        InstructionPattern[ sizeof(InstructionPattern) /sizeof(InstructionPattern_t) - 1 ].size + 1;

    while (it < MAX_OPCODE_SIZE)
    {
        // Verify bit by bit from the MSB to the LSB the bit selection
        
        ++it;
    }

    return group;
}

void execute_shift(CPU* cpu, const Instruction* instruction)
{

}

void execute_data_processing(CPU* cpu, const Instruction* instruction)
{

}

void execute_special_data(CPU* cpu, const Instruction* instruction)
{

}

void execute_load_store_single(CPU* cpu, const Instruction* instruction)
{

}

void execute_miscelanious(CPU* cpu, const Instruction* instruction)
{

}

void execute_conditional_branch(CPU* cpu, const Instruction* instruction)
{

}

