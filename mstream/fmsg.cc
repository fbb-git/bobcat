#include "mstream.hh"

namespace FBB
{
    Mstream fmsg(std::cout, numeric_limits<size_t>::max(),       "Fatal", true);
}
