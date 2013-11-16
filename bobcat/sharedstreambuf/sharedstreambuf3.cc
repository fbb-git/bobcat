#include "sharedstreambuf.ih"

SharedStreambuf::SharedStreambuf(int id, std::ios::openmode openMode)
:
    d_openMode(openMode),
    d_currentMode(openMode & (ios::in | ios::out)),
    d_memory(id)
{}
