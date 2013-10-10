inline std::ostream &SyslogStream::err(std::ostream &str)
{
    return setPriority(str, ERR);
}
