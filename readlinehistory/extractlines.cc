#include "readlinehistory.ih"

istream &ReadLineHistory::extractLines(istream &in)
{
    string line;
    while (getline(in, line))
        add_history(line.c_str());

    return in;
}
