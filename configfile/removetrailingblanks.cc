#include "configfile.ih"

                                                // `line' must have content.
void ConfigFile::removeTrailingBlanks(string &line)
{
    line = line.substr(0, line.find_last_not_of(" \t") + 1);
}   
