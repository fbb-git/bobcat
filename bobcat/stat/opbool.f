inline Stat::operator bool() const
{
    return d_errno == 0;
}
