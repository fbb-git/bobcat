#include <stdio.h>
#include <stdlib.h>

void _bobcat_fatal(char const *);

int XCloseDisplay()
{
    _bobcat_fatal("XCloseDisplay");
    return 0;
}
