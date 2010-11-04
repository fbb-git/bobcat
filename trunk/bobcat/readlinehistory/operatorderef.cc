#include "readlinehistory.ih"

ReadLineHistory::HistoryElement const 
    &ReadLineHistory::const_iterator::operator*() const
{
    return d_element.set(history_list()[d_idx]);
}
