#include "syslogbuf.hh"

int Syslogbuf::sync()
{
    return pSync();
}
