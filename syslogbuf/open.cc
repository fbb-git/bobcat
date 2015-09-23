#include "syslogbuf.hh"

void Syslogbuf::open(std::string const &ident, 
                     Priority priority, Facility facility, int option)
{
    close();
    d_orgPriority = d_priority = priority;

    reset(ident, facility, option);
}
