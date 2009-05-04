#include "process.ih"

std::istream &Process::cerr()
{
    active();
    return d_childCerr;
}

