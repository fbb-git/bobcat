#include "msgstream.ih"

void MsgStream::open(std::string const &name)
{
    d_ofstream.open(name.c_str());
    if (!d_ofstream)
        throw Errno(1) << "Can't write `" << name << '\'';

    d_msgStreambuf.reset(&d_ofstream, d_msgStreambuf.throwing());
}
