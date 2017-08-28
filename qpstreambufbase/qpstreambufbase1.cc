#include "qpstreambufbase.ih"

QPStreambufBase::QPStreambufBase(std::istream &in, size_t bufSize)
:   
    IFilterStreambuf(bufSize),
    d_in(in)
{}
