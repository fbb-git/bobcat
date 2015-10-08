#include "cgi.ih"

CGI &CGI::operator=(CGI &&tmp)
{
    fswap(*this, tmp);
    return *this;
}
