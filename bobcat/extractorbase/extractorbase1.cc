#include "extractorbase.ih"

ExtractorBase::ExtractorBase(size_t bufSize)
:
    istream(this),
    d_bufSize(bufSize)
{}

