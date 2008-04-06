#include <stdio.h>
#include <stdlib.h>

void bobcat_fatal_(char const *, char const *);

int XOpenDisplay()
{
    bobcat_fatal_("XOpenDisplay", "X");
    return 0;
}
