inline DateTime::TriVal DateTime::dst() const
{
    return static_cast<TriVal>(d_tm.tm_isdst);  
}
