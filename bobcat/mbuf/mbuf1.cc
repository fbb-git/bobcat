#include "mbuf.ih"

Mbuf::Mbuf()
:
    d_ostr(cout.rdbuf()),
    d_newMsg(true),
    d_showLineNrs(false),
    d_throw(false),
    d_count(0),
    d_lineNr(0),
    d_maxCount(UINT_MAX),
    d_lineExcess(false)
{}
