#include "iostreambuf.ih"

int IOStreambuf::ioSync()
{
    d_out->flush();
    return !d_out->good();
}
