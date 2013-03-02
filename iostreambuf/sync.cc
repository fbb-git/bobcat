#include "iostreambuf.ih"

int IOStreambuf::sync()
{
    d_out->flush();
    return !d_out->good();
}
