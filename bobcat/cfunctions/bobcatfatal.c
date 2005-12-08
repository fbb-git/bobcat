#include <stdio.h>
#include <stdlib.h>

void _bobcat_fatal(char const *name)
{
    fprintf(stderr, "wrong %s called. Aborting\n", name);
    exit(1);
}
