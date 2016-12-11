#include "extractorfork.ih"

ExtractorFork::ExtractorFork(size_t bufSize)
:
    std::istream(this),
    d_bufSize(bufSize)
{}

