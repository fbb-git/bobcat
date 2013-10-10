inline DateTime Stat::lastAccess() const
{
    return DateTime(d_stat.st_atime, DateTime::UTC);
}
