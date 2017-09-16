#include "configfile.ih"

ConfigFile::RE_iteratorPair ConfigFile::beginEndRE()
{
    return const_cast<ConfigFile const *>(this)->beginEndRE();
}
