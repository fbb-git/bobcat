#include "configfile.ih"

bool ConfigFile::hasContent(string const &line)
{
    return (line.find_first_not_of(" \t") != string::npos);
}   
