#include "configfile.ih"

void ConfigFile::open(string const &fname)
{
    ifstream stream(fname.c_str());

    if (!stream)
        throw Errno("ConfigFile::open()") << insertable <<
                    ": can't open " << fname << throwable;

    clear();                        // clear the vector
    d_index.clear();                // clear the line indices
    d_rawIndex = 0;                 // initialize the line-index of the
                                    // original file

    string line;

    while (nextLine(stream, line))
        push_back(line);
}




