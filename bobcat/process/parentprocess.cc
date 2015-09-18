#include "process.hh"

void Process::parentProcess()   // overrides
{
    d_child.pid = pid();
}

