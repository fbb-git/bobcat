#include "tablebuf.ih"

namespace FBB
{
                        // displays the table
std::ostream &operator<<(std::ostream &out, TableBuf &table)
{
    table.sync();
    TableBase &tb = table;
    return out << tb;
}

} // FBB
