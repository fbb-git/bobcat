#include "tablebuf.hh"

namespace FBB
{

std::ostream &rs(std::ostream &out)
{
    TableBuf &tb = dynamic_cast<TableBuf &>(*out.rdbuf());

    tb.overflow(tb.d_rs);
    return out;
}

}
