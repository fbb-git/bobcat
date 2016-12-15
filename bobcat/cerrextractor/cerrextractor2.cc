#include "cerrextractor.ih"

CerrExtractor::CerrExtractor(Mode mode, size_t bufSize)
:
    IUO::ExtractorBase(bufSize),
    d_modeFun(close)
{}

