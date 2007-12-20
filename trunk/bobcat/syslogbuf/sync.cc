#include "syslogbuf.ih"

int Syslogbuf::sync()
{
    if (d_buffer.length())
    {
        syslog(d_priority, "%s", d_buffer.c_str());
        d_buffer.erase();
        d_priority = d_orgPriority;
    }
    return 0;
}
