#include "readlinehistory.ih"

namespace FBB
{

std::istream &operator>>(std::istream &in, ReadLineHistory &history)
{
    if (!in)
        return in;

    clear_history();

    if (history.d_timestamps)
        return history.extractTimestamps(in);

    return history.extractLines(in);
}

}
