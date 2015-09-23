#include "syslogbuf.hh"

Priority Syslogbuf::setPriority(Priority priority)
{
    Priority old = d_priority;
    d_priority = priority;
    return old;
}
