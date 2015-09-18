#include "configfile.hh"

ConfigFile__::ConfigFile__(Comment cType, SearchCasing sType,
                       Indices iType)
:
    d_rmComment(cType == RemoveComment),
    d_caseSensitive(sType == SearchCaseSensitive),
    d_indices(iType == StoreIndices)
{}

ConfigFile::ConfigFile(Comment cType, SearchCasing sType,
                       Indices iType)
:
    d_ptr(new ConfigFile__(cType, sType, iType))
{}

