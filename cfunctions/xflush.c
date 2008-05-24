#include <stdio.h>
#include <stdlib.h>

void bobcat_fatal_(char const *, char const *);

int XFlush()
{
    bobcat_fatal_("XFlush", "X11");
    return 0;
}
