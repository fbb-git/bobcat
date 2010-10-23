#include "mstream.ih"

namespace FBB
{

Mstream emsg(std::cout, UINT_MAX - 1,   "Error");
Mstream fmsg(std::cout, UINT_MAX,       "Fatal", true);
Mstream imsg(std::cout, UINT_MAX);
Mstream wmsg(std::cout, UINT_MAX,       "Warning");

}
