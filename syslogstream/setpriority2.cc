#include "syslogstream.hh"

ostream &SyslogStream::setPriority(ostream &str, Priority value)
{
    Syslogbuf *sb = dynamic_cast<Syslogbuf *>(str.rdbuf());

    if (sb)
        sb->setPriority(value);

    return str;
}
