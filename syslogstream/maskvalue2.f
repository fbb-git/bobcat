template <typename ...Priorities>
inline int SyslogStream::maskValue(Priority p1, Priorities ...ps)
{
    return ((1 << p1) | maskValue(ps ...));
}
