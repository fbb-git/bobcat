#include "cerrextractor.ih"

CerrExtractor::CerrExtractor(size_t bufSize)
:
    IUO::ExtractorBase(bufSize),
    d_modeFun(noClose)
{}

