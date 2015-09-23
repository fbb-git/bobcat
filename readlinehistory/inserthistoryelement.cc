#include "readlinehistory.hh"

void ReadLineHistory::insertHistoryElement(HistoryElement const &he,
                                         std::ostream &out)
{
    out << he.line() << '\n' <<
           he.timestamp() << '\n';
}
