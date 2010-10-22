#include "msgbuf.ih"

void Msgbuf::reset(std::ostream *ostr)
{
    reset();
    d_ostr = ostr;
}
