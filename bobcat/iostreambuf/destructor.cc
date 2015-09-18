#include "iostreambuf.hh"

IOStreambuf::~IOStreambuf()
{
    if (d_out)
        sync();
}
