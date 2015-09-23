#include "syslogbuf.hh"

Syslogbuf::~Syslogbuf()
{
    close();
}
    
