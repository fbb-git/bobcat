#include "configfile.ih"

void ConfigFile::removeComment(string &line)
{
    size_t pos;

    if ((pos = line.find_first_of('#')) != string::npos)
        line.erase(pos);            // throw away beyond '#'
}   
