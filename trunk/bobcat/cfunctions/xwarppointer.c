#include <stdio.h>
#include <stdlib.h>

void bobcat_fatal_(char const *, char const *);

int XWarpPointer()
{
    bobcat_fatal_("XWarpPointer", "X11");
    return 0;
}
