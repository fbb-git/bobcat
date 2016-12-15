#include "cininserter.ih"

CinInserter::CinInserter(size_t bufSize)
:
    ostream(this),
    d_bufSize(bufSize),
    d_modeFun(close)
{}

