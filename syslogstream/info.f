inline std::ostream &SyslogStream::info(std::ostream &str)
{
    return setPriority(str, INFO);
}
