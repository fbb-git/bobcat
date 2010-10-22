#include "msgstream.ih"

namespace FBB
{

MsgStream emsg(std::cout, UINT_MAX - 1,   "Error");
MsgStream fmsg(std::cout, UINT_MAX,       "Fatal", true);
MsgStream imsg(std::cout, UINT_MAX);
MsgStream wmsg(std::cout, UINT_MAX,       "Warning");

}
