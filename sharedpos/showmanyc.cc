#include "sharedpos.ih"

streamsize SharedPos::showmanyc() const
{
    streamsize available = nReadable();
                           
    streamsize end = eos();             // offset at end of current segment
    
    if (end > available)                // end cannot exceed writeoffset
        end = available;
    
    return d_offset >= end ? 0 : end - d_offset;
}
