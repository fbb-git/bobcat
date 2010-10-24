#include "mbuf.ih"

void Mbuf::reset(string const &name, size_t maxCount, string const &tag, 
                   bool throwing)
{
    sync();

    if (d_ofstr->rdbuf() == d_ostr.rdbuf())
        d_ofstr.reset();

    d_ofstr = shared_ptr<ofstream>(new ofstream(name));
    d_ostr.rdbuf(d_ofstr->rdbuf()),

    d_newMsg = true;
    d_throw = throwing;
    d_maxCount = maxCount;
    d_lineExcess = d_count >= maxCount;
    setTag(tag);

    inspectOfstr(name);
}
