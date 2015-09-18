#include "sharedstreambuf.hh"

SharedStreambuf::SharedStreambuf(int id, std::ios::openmode openMode)
:
    d_openMode(openMode),
    d_currentMode(openMode & (ios::in | ios::out)),
    d_memory(id)
{
    if 
    (
        openMode & ios::trunc 
        || 
        (openMode & ios::out and not (openMode & ios::in))
    )
        d_memory.clear();

    setg(0, 0, 0);
    setp(0, 0);
}

