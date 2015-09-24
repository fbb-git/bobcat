#include "cgi.ih"

CGI &CGI::operator=(CGI const &&tmp)
{
    fswap(*this, const_cast<CGI &>(tmp));
    return *this;
}
