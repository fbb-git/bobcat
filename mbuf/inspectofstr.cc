#include "mbuf.hh"

void Mbuf::inspectOfstr(string const &name) const
{
    if (not d_ofstr->good())
        throw Exception(1) << "Can't write `" << name << '\''; 
}
