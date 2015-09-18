#include "process.hh"

std::istream &Process::childErrStream()
{
    active();
    return d_iChildErr;
}

