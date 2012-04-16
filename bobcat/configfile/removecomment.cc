#include "configfile.ih"

void ConfigFile::removeComment(string &line)
{
    size_t pos;

    if 
    (                               // saw #
        (pos = line.find_first_of('#')) != string::npos
        &&                          // but not \#
        pos > 0 && line[pos - 1] != '\\'
    )
        line.erase(pos);            // throw away beyond '#'

    while ((pos = line.find("\\#")) != string::npos)    // replace \# by #
        line.replace(pos, 2, "#");
}   
