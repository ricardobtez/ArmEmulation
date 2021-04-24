#include <stdlib.h>
#include <stdio.h>
#include "Cpu.h"
//#include "Armv6_shift.h"

int main()
{
    printf("Armv6_M0Plus emulation\n");
    CPU* cpu = create_cpu();
    reset_cpu(cpu);

    Instruction inst;

    // 0b0000_0xxx_xxxx_xxxx
    cpu->R2 = 4;
    cpu->R3 = 12;
    inst.rawData = 0x0113;
    execute_instruction(cpu, &inst);
}
