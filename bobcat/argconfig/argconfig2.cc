#include "argconfig.ih"

ArgConfig::ArgConfig(char const *optstring, 
    int argc, char **argv, std::string const &fname,
    Comment cType, SearchCasing sType, Indices iType)
:
    Arg(optstring, argc, argv),
    ConfigFile(fname, cType, sType, iType)
{}


