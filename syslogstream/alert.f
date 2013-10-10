inline std::ostream &SyslogStream::alert(std::ostream &str)
{
    return setPriority(str, ALERT);
}
