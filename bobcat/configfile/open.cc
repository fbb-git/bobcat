#include "configfile.ih"

void ConfigFile::open(string const &fname) throw (Errno)
{
    ifstream stream(fname.c_str());

    if (!stream)
        throw Errno("ConfigFile::open()") << insertable <<
                    ": can't open " << fname << throwable;

    clear();                        // clear the vector

    string line;

    while (nextLine(stream, line))
        push_back(line);
}




