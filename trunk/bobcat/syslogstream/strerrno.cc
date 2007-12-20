#include "syslogstream.ih"

ostream &SyslogStream::strerrno(ostream &str)
{
    return str << strerror(errno);
}
