#include "processdata.hh"

ProcessData::ProcessData(size_t bufSize)
:
    d_bufSize(bufSize == 0 ? 1 : bufSize)
{
    Signal::instance().add(SIGCHLD, *this);
}

