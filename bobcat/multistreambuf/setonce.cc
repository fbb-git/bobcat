#include "multistreambuf.ih"

void MultiStreambuf::setOnce() 
{
    for (auto &os: d_os)
        stream::setOnce(os);
}
