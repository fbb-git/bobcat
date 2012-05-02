#include "configfile.ih"

ConfigFile::RE_iteratorPair ConfigFile::beginEndRE()
{
    return RE_iteratorPair(d_ptr->endRE(), d_ptr->endRE());
}
