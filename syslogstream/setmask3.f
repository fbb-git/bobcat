template <typename ...Priorities>
inline int SyslogStream::setMask(Priority p1, Priorities ...ps)
{
    return setMask(maskValue(p1, ps ...), SINGLE);
}
