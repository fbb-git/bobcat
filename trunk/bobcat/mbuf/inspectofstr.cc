#include "mbuf.ih"

void Mbuf::inspectOfstr(string const &name) const
{
    if (not d_ofstr->good())
        throw Errno(1) << "Can't write `" << name << '\''; 
}
