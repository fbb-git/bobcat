#include "mstream.ih"

namespace FBB
{

std::ostream &endm(std::ostream &os)
{
    return flushm(os.put('\n'));
}

} // FBB
