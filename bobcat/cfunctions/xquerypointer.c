#include <stdio.h>
#include <stdlib.h>

void bobcat_fatal_(char const *, char const *);

int XQueryPointer()
{
    bobcat_fatal_("XQueryPointer", "X");
    return 0;
}
