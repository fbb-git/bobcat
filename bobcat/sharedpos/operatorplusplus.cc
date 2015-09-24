#include "sharedpos.ih"

void SharedPos::operator++()
{
    ++d_offset;
    
    update();
}
