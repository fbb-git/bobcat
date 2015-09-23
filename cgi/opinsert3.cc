#include "cgi.hh"

CGI &CGI::operator<<(int ch)
{
    if (!d_activated)
    {
        d_escape[static_cast<unsigned char>(ch)] = d_escapeValue;
        d_escape['\\'] = true;
    }
    return *this;
}
