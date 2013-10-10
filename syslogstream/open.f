inline void SyslogStream::open(std::string const &ident, Priority priority, 
                               Facility facility, int option)
{
    Syslogbuf::open(ident, priority, facility, option);
}
