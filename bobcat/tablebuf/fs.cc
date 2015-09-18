#include "tablebuf.hh"

namespace FBB
{

std::ostream &fs(std::ostream &out)
{
    TableBuf &tb = dynamic_cast<TableBuf &>(*out.rdbuf());

    tb.overflow(tb.d_fs);
    return out;
}

}
