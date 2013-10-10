inline int SyslogStream::setMask(Priority p1)
{
    return setMask(maskValue(p1), SINGLE);
}
