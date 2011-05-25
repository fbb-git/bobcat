#include "milter.ih"

#if SMFI_VERSION > 3

sfsistat Milter::data()
{
    return CONTINUE;
}

#endif
