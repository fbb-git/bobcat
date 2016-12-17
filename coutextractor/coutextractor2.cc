#include "coutextractor.ih"

CoutExtractor::CoutExtractor(StdMode mode, size_t bufSize)
:
    IUO::ExtractorBase(bufSize),
    d_modeFun(close)
{}

