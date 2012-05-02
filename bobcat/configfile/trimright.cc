#include "configfile.ih"

void ConfigFile__::trimRight(string &line, bool appendNext)
{
    if (appendNext)
        return;

    size_t pos = line.find_last_not_of(" \t");
    if (pos != string::npos)
        line.resize(pos + 1);
}
