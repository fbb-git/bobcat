#include "syslogstream.hh"

SyslogStream::SyslogStream(string const &ident, Priority priority, 
                            Facility facility, int option)
:
    Syslogbuf(ident, priority, facility, option),
    std::ostream(this)
{}
