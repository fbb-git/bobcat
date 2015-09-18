#include "milter.hh"

#if SMFI_VERSION > 2

sfsistat Milter::unknown(char const *ptr)
{
    return CONTINUE;
}

#endif
