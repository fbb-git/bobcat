#include "syslogbuf.ih"

Syslogbuf::~Syslogbuf()
{
    close();
}
    
