#include <stdio.h>
#include <stdlib.h>

void _bobcat_fatal(char const *);

int XOpenDisplay()
{
    _bobcat_fatal("XOpenDisplay");
    return 0;
}
