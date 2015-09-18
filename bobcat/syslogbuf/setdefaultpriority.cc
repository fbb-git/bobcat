#include "syslogbuf.hh"

Priority Syslogbuf::setDefaultPriority(Priority priority)
{
    Priority old = d_orgPriority;
    d_orgPriority = priority;
    return old;
}
