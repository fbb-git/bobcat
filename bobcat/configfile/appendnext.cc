#include "configfile.ih"

void ConfigFile::append_next(istream &istr, string &line)
{
    string next;

    if (!getline(istr, next))           // done if no more lines
        return;

    if (d_rmComment)
        removeComment(next);            // remove comment from next line

                                        // find first non-blank char
    unsigned  pos = next.find_first_not_of(" \t");

    if (pos == string::npos)            // only blank chars?
        return;                         // nothing to add here

    line += next.substr(pos);           // add the line without initial ws.
}   
