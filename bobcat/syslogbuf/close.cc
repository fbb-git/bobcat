#include "syslogbuf.hh"

void Syslogbuf::close()
{
    sync();   
    closelog();
}
