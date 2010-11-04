#include "readlinehistory.ih"

ReadLineHistory::HistoryElement const 
        &ReadLineHistory::HistoryElement::set(HIST_ENTRY const *element)
{
    d_line = element->line;
    d_timestamp = element->timestamp;
    return *this;
}
