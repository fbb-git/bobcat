#include "syslogstream.ih"

SyslogStream::SyslogStream(char const *ident, Priority priority, 
                            Facility facility, int option)
:
    Syslogbuf(ident, priority, facility, option),
    std::ostream(this)
{}
