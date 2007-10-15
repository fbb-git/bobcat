#include "multistreambuf.ih"

void MultiStreambuf::setOnce() 
{
    for_each(d_os.begin(), d_os.end(), &stream::setOnce);
}
