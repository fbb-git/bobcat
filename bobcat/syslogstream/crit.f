inline std::ostream &SyslogStream::crit(std::ostream &str)
{
    return setPriority(str, CRIT);
}
