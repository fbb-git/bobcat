#include "configfile.ih"

ConfigFile::ConfigFile(Comment cType, SearchCasing sType,
                       Indices iType)
:
    d_rmComment(cType == RemoveComment),
    d_caseSensitive(sType == SearchCaseSensitive),
    d_indices(iType == StoreIndices)
{}
