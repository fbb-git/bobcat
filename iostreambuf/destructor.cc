#include "iostreambuf.ih"

IOStreambuf::~IOStreambuf()
{
    if (d_out)
        sync();
}
