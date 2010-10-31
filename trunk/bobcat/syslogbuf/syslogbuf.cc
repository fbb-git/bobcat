#include "syslogbuf.ih"

namespace FBB
{
    Syslogbuf::Syslogbuf(char const *ident, 
                         Priority priority, Facility facility, int option)
    :
        d_priority(priority),
        d_orgPriority(priority)
    {
        openlog(ident, option, facility);
        setp(0, 0);                         // no buffer
    }
}
