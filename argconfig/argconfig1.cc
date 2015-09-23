#include "argconfig.hh"

ArgConfig::ArgConfig(char const *optstring, 
    int argc, char **argv,
    Comment cType, SearchCasing sType, Indices iType)
:
    Arg(optstring, argc, argv),
    ConfigFile(cType, sType, iType)
{}


