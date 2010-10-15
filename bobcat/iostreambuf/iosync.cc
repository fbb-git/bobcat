#include "iostreambuf.ih"

int IOStreambuf::pSync()
{
    d_out->flush();
    return !d_out->good();
}
