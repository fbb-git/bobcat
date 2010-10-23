#include "mbuf.ih"

void Mbuf::reset(streambuf *buf, size_t maxCount, string const &tag, 
                   bool throwing)
{
    sync();

    if (d_ofstr->rdbuf() == d_ostr.rdbuf())
        d_ofstr.reset();

    d_ostr.rdbuf(buf);

    d_newMsg = true;
    d_throw = throwing;
    d_maxCount = maxCount;
    setTag(tag);
}
