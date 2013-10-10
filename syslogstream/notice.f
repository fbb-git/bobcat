inline std::ostream &SyslogStream::notice(std::ostream &str)
{
    return setPriority(str, NOTICE);
}
