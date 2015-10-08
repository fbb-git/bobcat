#include "readlinehistory.ih"

ostream &FBB::operator<<(ostream &out, ReadLineHistory const &history)
{
    for (auto &he: history)
        (
            history.d_timestamps ? 
                ReadLineHistory::insertHistoryElement 
            : 
                ReadLineHistory::insertLine
        )(he, out);

    return out;
}


