#include "msgstream.ih"

void MsgStream::open(std::string const &name)
{
    d_ofstream.close();                     // switch streams
    d_ofstream.open(name.c_str());

    if (!d_ofstream)
        throw Errno(1) << "Can't write `" << name << '\'';

    Msgbuf::reset(&d_ofstream);             // reset the output operations to
                                            // use this stream.
}
