#include "multistreambuf.hh"

void MultiStreambuf::setOnce() 
{
    for (auto &os: d_os)
        stream::setOnce(os);
}
