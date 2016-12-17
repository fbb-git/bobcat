#include "stdextractor.ih"

StdExtractor::StdExtractor(size_t bufSize)
:
    IUO::ExtractorBase(bufSize),
    d_modeFun(noClose)
{}

