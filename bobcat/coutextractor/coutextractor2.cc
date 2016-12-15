#include "coutextractor.ih"

CoutExtractor::CoutExtractor(Mode mode, size_t bufSize)
:
    IUO::ExtractorBase(bufSize),
    d_modeFun(close)
{}

