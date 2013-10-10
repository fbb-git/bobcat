inline std::ostream &SyslogStream::debug(std::ostream &str)
{
    return setPriority(str, DEBUG);
}
