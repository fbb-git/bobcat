#include "stdextractor.ih"

StdExtractor::StdExtractor(StdMode mode, size_t bufSize)
:
    IUO::ExtractorBase(bufSize),
    d_modeFun(close)
{}

