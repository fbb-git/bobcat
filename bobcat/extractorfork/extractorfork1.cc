#include "extractorfork.ih"

ExtractorFork::ExtractorFork(size_t bufSize)
:
    istream(this),
    d_bufSize(bufSize)
{}

