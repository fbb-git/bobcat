#include "sharedstreambuf.ih"

SharedStreambuf::SharedStreambuf()
:
    d_openMode(static_cast<ios::openmode>(0)),
    d_currentMode(d_openMode)
{}
