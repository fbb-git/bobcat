#include "readlinehistory.hh"

void ReadLineHistory::insertLine(HistoryElement const &he, std::ostream &out)
{
    out << he.line() << '\n';
}
