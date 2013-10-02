inline DateTime::Month DateTime::month() const
{
    return static_cast<Month>(d_tm.tm_mon);
}
