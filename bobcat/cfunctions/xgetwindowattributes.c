#include <stdio.h>
#include <stdlib.h>

void bobcat_fatal_(char const *, char const *);

int XGetWindowAttributes()
{
    bobcat_fatal_("XGetWindowAttributes", "X11");
    return 0;
}
