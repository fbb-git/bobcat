#if SMFI_VERSION > 2

#include "milter.ih"

sfsistat Milter::unknown(char const *ptr)
{
    return CONTINUE;
}

#endif
