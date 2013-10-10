inline DateTime Stat::lastModification() const
{
    return DateTime(d_stat.st_mtime, DateTime::UTC);
}
