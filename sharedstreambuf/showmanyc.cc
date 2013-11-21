#include "sharedstreambuf.ih"

streamsize SharedStreambuf::showmanyc()
{
    return d_memory.showmanyc();
}
