#include <stdio.h>
#include <stdlib.h>

void bobcat_fatal_(char const *name)
{
    fprintf(stderr, 
        "When linking, specify the %s library before the bobcat library.\n"
        "E.g., use -l%s -lbobcat.\n"
        "Aborting\n", 
            name, name);

    exit(1);
}
