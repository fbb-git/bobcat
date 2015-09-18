#include "argconfig.hh"

ArgConfig &ArgConfig::initialize(char const *optstring, 
    int argc, char **argv, 
    Comment cType, SearchCasing sType, Indices iType)
{
    if (s_argconfig)
        throw Exception() << "ArgConfig::initialize(): already initialized";

    s_argconfig = new ArgConfig(optstring, argc, argv, cType, sType, iType);

    return *s_argconfig;
}
