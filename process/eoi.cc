#include "process.ih"

int Process::eoi()
{
    *this << FBB::eoi;
    return exitStatus();
}

