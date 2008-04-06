#include <stdio.h>
#include <stdlib.h>

void bobcat_fatal_(char const *, char const *);

int XCloseDisplay()
{
    bobcat_fatal_("XCloseDisplay", "X");
    return 0;
}
