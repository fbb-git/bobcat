#include "sharedpos.hh"

void SharedPos::operator+=(size_t len)
{
    d_offset += len;
    update();
}
