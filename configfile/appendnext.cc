#include "configfile.ih"

unsigned ConfigFile::append_next(istream &istr, string &line)
{
    string next;

    if (!getline(istr, next))           // done if no more lines
        return 0;

    ++d_rawIndex;                       // we're at the next line

    if (d_rmComment)
        removeComment(next);            // remove comment from next line

                                        // find first non-blank char
    unsigned  pos = next.find_first_not_of(" \t");

    if (pos != string::npos)            // any non-blank chars?
        line += next.substr(pos);       // add the line without initial ws.

    return 1;                           // count the continued line
}   
