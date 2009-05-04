#include "syslogbuf.ih"

Syslogbuf::~Syslogbuf()
{
    if (d_buffer.length())
        sync();   
                              
    closelog();
}
    
