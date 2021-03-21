#include <stdlib.h>
#include <stdio.h>
#include "Armv6_cpu.h"


int main()
{
    printf("Armv6_M0Plus emulation\n");
    CPU* cpu = create_cpu();
    reset_cpu(cpu);
}
