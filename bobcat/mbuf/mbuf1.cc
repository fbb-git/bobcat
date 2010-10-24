#include "mbuf.ih"

Mbuf::Mbuf()
:
    d_ostr(cout.rdbuf()),

    d_firstChar(true),
    d_throw(false),

    d_count(0),
    d_maxCount(UINT_MAX),
    d_lineExcess(false),

    d_showLineNrs(false),
    d_lineNr(0),
    d_lineTag("Line")
{}
