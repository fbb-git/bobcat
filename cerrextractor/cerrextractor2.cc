#include "cerrextractor.ih"

CerrExtractor::CerrExtractor(StdMode mode, size_t bufSize)
:
    IUO::ExtractorBase(bufSize),
    d_modeFun(close)
{}

