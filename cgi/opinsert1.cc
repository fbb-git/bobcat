#include "cgi.hh"

CGI &CGI::operator<<(string const &accept) 
{
    if (!d_activated)
    {
        istringstream in(accept);
        CGIFSA fsa(d_escape, in, d_escapeValue);
    
        fsa.run();
        d_escape['\\'] = true;
    }

    return *this;
}
