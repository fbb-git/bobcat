#include "process.ih"

void Process::parentProcess()   // overrides
{
    d_child.pid = pid();
}

