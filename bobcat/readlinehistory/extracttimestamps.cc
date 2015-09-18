#include "readlinehistory.hh"

istream &ReadLineHistory::extractTimestamps(istream &in)
{
    string line;
    string timestamp;
    while (getline(in, line) && getline(in, timestamp))
    {
        add_history(line.c_str());
        add_history_time(timestamp.c_str());
    }

    return in;
}
