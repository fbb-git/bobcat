#include <stdio.h>
#include <stdlib.h>

void bobcat_fatal_(char const *, char const *);

int XWarpPointer()
{
    bobcat_fatal_("XWarpPointer", "X");
    return 0;
}
