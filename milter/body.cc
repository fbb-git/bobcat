#include "milter.hh"

sfsistat Milter::body(unsigned char *text, size_t length)
{
    return CONTINUE;
}
