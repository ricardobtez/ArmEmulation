
#include <stdio.h>
#include "Armv6_cpu.h"

enum InstructionGroup_t
{
    SHIFT_GROUP                 = 1;
    DATA_PROCESSING_GROUP       = 2;
    SPECIAL_DATA_GROUP          = 3;
    LOAD_STORE_SINGLE_GROUP     = 4;
    MISCELANIOUS_GROUP          = 5;
    CONDITIONAL_BRANCH_GROUP    = 6;
    INVALID_INSTRUCTION_GROUP;
}InstructionGroup_t;

/// \brief
/// Static function to determine the Instruction group
static InstructionGroup_t decodeInstruction(Instruction* instruction);

/// \brief
/// Static function to execute shift instructions
static void execute_shift(CPU* cpu, Instruction* instruction);

/// \brief
/// Static function to execute data processing group instructions
static void execute_data_processing(CPU* cpu, Instruction* instruction);

/// \brief
/// Static function to execute special data group instructions
static void execute_special_data(CPU* cpu, Instruction* instruction);

/// \brief
/// Static function to execute load store single group instructions
static void execute_load_store_single(CPU* cpu, Instruction* instruction);

/// \brief
/// Static function to execute miscelanious group instructions
static void execute_miscelanious(CPU* cpu, Instruction* instruction);

/// \brief
/// Static function to execute conditional branch group instructions
static void execute_conditional_branch(CPU* cpu, Instruction* instruction);

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
            execute_miscenalanious(cpu, instruction);
            break;

        case CONDITIONAL_BRANCH_GROUP:
            execute_conditional_branch(cpu, instruction);
            break;

        default:
            printf("execute(): Invalid instruction group\n");
            break;
    }
}


InstructionGroup_t decodeInstruction(Instruction* instruction)
{

}

void execute_shift(CPU* cpu, Instruction* instruction)
{

}

void execute_data_processing(CPU* cpu, Instruction* instruction)
{

}

void execute_special_data(CPU* cpu, Instruction* instruction)
{

}

void execute_load_store_single(CPU* cpu, Instruction* instruction)
{

}

void execute_miscelanious(CPU* cpu, Instruction* instruction)
{

}

void execute_conditional_branch(CPU* cpu, Instruction* instruction)
{

}

