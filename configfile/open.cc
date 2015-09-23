#include "configfile.hh"

void ConfigFile__::open(string const &fname)
{
    ifstream stream;
    Exception::open(stream, fname);

    d_line.clear();                 // clear the vector
    d_index.clear();                // clear the line indices
    d_vsIter.clear();               // clear iterators to matching lines
    d_re.clear();                   // clear a previously set search RE

    d_rawIndex = 0;                 // re-initialize the line-index of the
                                    // original file

    string line;
    while (nextLine(stream, line))  // add the lines to d_line
        d_line.push_back(line);
}

void ConfigFile::open(string const &fname)
{
    d_ptr->open(fname);
}



