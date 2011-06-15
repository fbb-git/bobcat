#include "readlinehistory.ih"

ostream &FBB::operator<<(ostream &out, ReadLineHistory const &history)
{
    for_each(
        history.begin(), history.end(), 
        [&](ReadLineHistory::HistoryElement const &he)
        {
            (
                history.d_timestamps ? 
                    ReadLineHistory::insertHistoryElement 
                : 
                    ReadLineHistory::insertLine
            )(he, out);
        }
    );
    return out;
}


