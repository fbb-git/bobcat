#include "cgi.hh"

CGI &CGI::operator=(CGI &&tmp)
{
    fswap(*this, tmp);
    return *this;
}
