#include "base64streambufbase.hh"

Base64StreambufBase::Base64StreambufBase(std::istream &in, size_t bufSize)
:   
    IFilterStreambuf(bufSize),
    d_in(in)
{}
