#include "configfile.ih"

void ConfigFile::open(string const &fname)
{
    ifstream stream;
    Errno::open(stream, fname);

    d_line.clear();                 // clear the vector
    d_index.clear();                // clear the line indices
    d_vsIter.clear();

    d_rawIndex = 0;                 // initialize the line-index of the
                                    // original file

    string line;

    while (nextLine(stream, line))
        d_line.push_back(line);
}




