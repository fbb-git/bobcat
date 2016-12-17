#include "cininserter.ih"

CinInserter::CinInserter(StdMode mode, size_t bufSize)
:
    ostream(this),
    d_bufSize(bufSize),
    d_modeFun(stdClose)
{}

