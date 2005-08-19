#include "configfile.ih"

void ConfigFile::removeComment(string &line)
{
    unsigned pos;

    if ((pos = line.find_first_of('#')) != string::npos)
        line.erase(pos);            // throw away beyond '#'
}   
