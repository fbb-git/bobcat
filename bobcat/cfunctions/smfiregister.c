#include <stdio.h>
#include <stdlib.h>

void bobcat_fatal_(char const *, char const *);

int smfi_register()
{
    bobcat_fatal("smfi_register", "milter");
    return 0;
}
