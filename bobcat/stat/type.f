inline Stat::Type Stat::type() const
{
    return static_cast<Type>(d_stat.st_mode & S_IFMT);
}
