#include "configfile.hh"

ConfigFile__::ConfigFile__(string const &fname, Comment cType, 
                            SearchCasing sType, Indices iType)
:
    d_rmComment(cType == RemoveComment),
    d_caseSensitive(sType == SearchCaseSensitive),
    d_indices(iType == StoreIndices)
{
    open(fname);
}


ConfigFile::ConfigFile(string const &fname, Comment cType, 
                       SearchCasing sType, Indices iType)
:
    d_ptr(new ConfigFile__(fname, cType, sType, iType))
{}


