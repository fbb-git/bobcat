#include <stdio.h>
#include <stdlib.h>

void bobcat_fatal_(char const *name)
{
    fprintf(stderr, "wrong %s called. Aborting\n", name);
    exit(1);
}
