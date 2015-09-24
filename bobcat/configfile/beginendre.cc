#include "configfile.ih"

ConfigFile::RE_iteratorPair ConfigFile::beginEndRE(std::string const &re)
{
    auto begin = d_ptr->beginRE(re);
    RE_iteratorPair ret(begin, d_ptr->endRE());

    return ret;
}
