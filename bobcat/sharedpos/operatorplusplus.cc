#include "sharedpos.hh"

void SharedPos::operator++()
{
    ++d_offset;
    
    update();
}
