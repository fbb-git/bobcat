#include "process.ih"

std::istream &Process::childErrStream()
{
    active();
    return d_iChildErr;
}

