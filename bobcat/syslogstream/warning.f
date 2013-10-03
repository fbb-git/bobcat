inline std::ostream &SyslogStream::warning(std::ostream &str)
{
    return setPriority(str, WARNING);
}
