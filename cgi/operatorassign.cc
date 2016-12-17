#include "cgi.ih"

CGI &CGI::operator=(CGI &&tmp)
{
    swap(tmp);
    return *this;
}
