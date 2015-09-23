#include "syslogbuf.hh"

int Syslogbuf::pSync()
{
    if (d_data->buffer.length())
    {
        syslog(d_priority, "%s", d_data->buffer.c_str());
        d_data->buffer.erase();
        d_priority = d_orgPriority;
    }
    return 0;
}
