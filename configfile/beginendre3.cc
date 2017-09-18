#include "configfile.ih"

ConfigFile::RE_iteratorPair ConfigFile::beginEndRE(std::string const &re)
{
    return const_cast<ConfigFile const *>(this)->beginEndRE(re);
}
