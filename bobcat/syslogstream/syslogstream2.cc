#include "syslogstream.ih"

SyslogStream::SyslogStream(char const *ident, Priority priority, 
                            Facility facility, int option)
:
    SyslogStream(string(ident == 0 ? "" : ident), priority, facility, option)
{}
