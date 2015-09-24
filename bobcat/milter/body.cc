#include "milter.ih"

sfsistat Milter::body(unsigned char *text, size_t length)
{
    return CONTINUE;
}
