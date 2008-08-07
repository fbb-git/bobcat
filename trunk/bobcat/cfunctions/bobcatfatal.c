#include <stdio.h>
#include <stdlib.h>

void bobcat_fatal_(char const *name, char const *lib)
{
    fprintf(stderr, 
        "When linking a program in which %s() is called,\n"
        "specify the %s library before the bobcat library.\n"
        "E.g., use -l%s -lbobcat.\n"
        "Aborting\n", 
            name, lib, lib);

    exit(1);
}
