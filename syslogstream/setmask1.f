inline int SyslogStream::setMask(Priority p1, PriorityType upTo)
{
    return setMask(maskValue(p1), upTo);
}
