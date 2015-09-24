#include "mstream.ih"

namespace FBB
{

std::ostream &noidl(std::ostream &os)
{
    return FBB::noid(os.put('\n'));
}

} // FBB
