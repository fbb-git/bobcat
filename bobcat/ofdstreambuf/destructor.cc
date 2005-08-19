#include "ofdstreambuf.ih"

OFdStreambuf::~OFdStreambuf()
{
    if (d_buffer)
    {
        sync();                                 
        delete d_buffer;
    }
}
    
