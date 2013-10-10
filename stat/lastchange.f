inline DateTime Stat::lastChange() const
{
    return DateTime(d_stat.st_ctime, DateTime::UTC);
}
