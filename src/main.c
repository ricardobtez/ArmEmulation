#include <stdlib.h>
#include <stdio.h>
#include "Cpu.h"
#include "Armv6_shift.h"

int main()
{
    printf("Armv6_M0Plus emulation\n");
    CPU* cpu = create_cpu();
    reset_cpu(cpu);

    Instruction inst;
    // 0b0000_001x_xxxx_xxxx
    inst.rawData = 0x03FF;;
    ShiftGroup_t group = decode_shift(&inst);
}
