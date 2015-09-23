#include "mstream.hh"

namespace FBB
{

std::ostream &endl(std::ostream &os)
{
    return FBB::flush(os.put('\n'));
}

} // FBB
