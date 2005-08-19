#include "configfile.ih"

ConfigFile::ConfigFile(Comment cType, SearchCasing sType)
:
    d_rmComment(cType == RemoveComment),
    d_caseSensitive(sType == SearchCaseSensitive)
{}
