inline std::ostream &SyslogStream::emerg(std::ostream &str)
{
    return setPriority(str, EMERG);
}
