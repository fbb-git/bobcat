#include <stdio.h>
#include <stdlib.h>

void _bobcat_fatal(char const *);

int XFlush()
{
    _bobcat_fatal("XFlush");
    return 0;
}
