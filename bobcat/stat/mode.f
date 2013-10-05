inline size_t Stat::mode() const
{
    return d_stat.st_mode & RWX;
}
