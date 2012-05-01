#include "configfile.ih"

void ConfigFile__::setSearchCasing(SearchCasing type)
{
    d_caseSensitive = type == SearchCaseSensitive;
}

void ConfigFile::setSearchCasing(SearchCasing type)
{
    d_ptr->setSearchCasing(type);
}

