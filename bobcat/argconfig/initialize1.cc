#include "argconfig.ih"

ArgConfig &ArgConfig::initialize(char const *optstring, 
    int argc, char **argv, 
    Comment cType, SearchCasing sType, Indices iType)
{
    if (s_argconfig)
        throw Errno("ArgConfig::initialize(): already initialized");

    s_argconfig = new ArgConfig(optstring, argc, argv, cType, sType, iType);

    s_argconfig->verify();

    return *s_argconfig;
}
