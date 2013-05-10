#include "syslogbuf.ih"

Syslogbuf::Syslogbuf(char const *ident, 
                     Priority priority, Facility facility, int option)
:
    Syslogbuf(string(ident), priority, facility, option)
{}
