#include "mbuf.ih"

void Mbuf::reset(string const &name, size_t maxCount, string const &tag, 
                   bool throwing)
{
    sync();

    if (d_ofstr->rdbuf() == d_ostr.rdbuf())
        d_ofstr.reset();

    d_ofstr = make_shared<ofstream>(name);
    d_ostr.rdbuf(d_ofstr->rdbuf()),

    d_firstChar = true;
    d_throw = throwing;

    setTag(tag);
    d_maxCount = maxCount;
    d_lineExcess = d_count >= maxCount;

    inspectOfstr(name);
}
