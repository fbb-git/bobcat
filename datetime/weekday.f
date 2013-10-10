inline DateTime::Weekday DateTime::weekday() const
{
    return static_cast<Weekday>(d_tm.tm_wday);
}
