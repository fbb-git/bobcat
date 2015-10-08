#include "sharedpos.ih"

ostream &SharedPos::insert(ostream &out) const
{
    return out << 
                "Maximum possible offset = " << d_maxOffset << "\n"
                "Current offset = " << d_offset << ", located in block " <<
                                                            blockIdx();
}
