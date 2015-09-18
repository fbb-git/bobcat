#include "sharedstreambuf.hh"

streamsize SharedStreambuf::showmanyc()
{
    return d_memory.showmanyc();
}
