#include "configfile.ih"

void ConfigFile__::trimLeft(string &line)
{
                                                    // remove initial ws.
    string::size_type pos = line.find_first_not_of(" \t");
    if (pos != string::npos)
        line.erase(0, pos);
}
