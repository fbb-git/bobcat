#include "msgstream.ih"

void MsgStream::reset(std::string const &name, size_t maxCount,
                     string const &tag, bool throwing)
{
    d_ofstream.close();                     // switch streams
    d_ofstream.open(name.c_str());

    if (!d_ofstream)
        throw Errno(1) << "Can't write `" << name << '\'';

    reset(d_ofstream, maxCount, tag, throwing);
                                            // reset the output operations to
                                            // use this stream.
}
