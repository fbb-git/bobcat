<<<<<<< HEAD
#include "mstream.ih"
=======
#include "mstream.hh"
>>>>>>> upstream/4.01.00

namespace FBB
{

std::ostream &noidl(std::ostream &os)
{
    return FBB::noid(os.put('\n'));
}

} // FBB
