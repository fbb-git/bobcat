#include "configfile.hh"

bool FBB::operator==(RE_iterator const &lhs, RE_iterator const &rhs)
{
    return lhs.d_idx == rhs.d_idx && lhs.d_vsIter == rhs.d_vsIter;
}

