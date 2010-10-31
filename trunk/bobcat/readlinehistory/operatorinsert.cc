#include "readlinehistory.ih"

ostream &FBB::operator<<(ostream &out, ReadLineHistory const &history)
{
    for_each(history.begin(), history.end(), 
        FnWrap::unary(history.d_timestamps ? 
                            ReadLineHistory::insertHistoryElement 
                        :
                            ReadLineHistory::insertLine,
                        out));

    return out;
}


