#include "configfile.ih"

ConfigFile::ConfigFile(string const &fname, Comment cType, SearchCasing sType)
:
    d_rmComment(cType == RemoveComment),
    d_caseSensitive(sType == SearchCaseSensitive)
{
    open(fname);
}



