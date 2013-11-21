#include "sharedstreambuf.ih"

bool SharedStreambuf::mode(ios::openmode flag)
{
    if (not (d_currentMode & flag))
        return false;

    d_currentMode = flag;
    return true;
}
