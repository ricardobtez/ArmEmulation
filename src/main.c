#include <stdlib.h>
#include <stdio.h>
#include "Armv6_cpu.h"

#ifdef DEBUG
 #define VALUE      42U
#else
 #define VALUE      69U
#endif

int main()
{
    printf("Value is: %d\n", VALUE);
}
