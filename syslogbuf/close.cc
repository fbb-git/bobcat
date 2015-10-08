#include "syslogbuf.ih"

void Syslogbuf::close()
{
    sync();   
    closelog();
}
