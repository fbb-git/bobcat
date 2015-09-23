#include "readlinehistory.hh"

istream &FBB::operator>>(istream &in, ReadLineHistory &history)
{
    if (!in)
        return in;

    clear_history();

    if (history.d_timestamps)
        return history.extractTimestamps(in);

    return history.extractLines(in);
}
