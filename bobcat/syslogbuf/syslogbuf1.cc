#include "syslogbuf.ih"

Syslogbuf::Syslogbuf(std::string const &ident, 
                     Priority priority, Facility facility, int option)
:
    d_priority(priority),
    d_orgPriority(priority),
    d_data(0)
{
    reset(ident, facility, option);
}













