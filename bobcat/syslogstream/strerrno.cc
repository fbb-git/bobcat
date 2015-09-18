#include "syslogstream.hh"

ostream &SyslogStream::strerrno(ostream &str)
{
    return str << strerror(errno);
}
