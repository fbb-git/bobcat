#include "iostreambuf.hh"

int IOStreambuf::pSync()
{
    d_out->flush();
    return !d_out->good();
}
