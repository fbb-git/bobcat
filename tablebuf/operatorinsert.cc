#include "tablebuf.hh"

                        // displays the table
std::ostream &FBB::operator<<(std::ostream &out, TableBuf &table)
{
    table.sync();
    TableBase &tb = table;
    return out << tb;
}
