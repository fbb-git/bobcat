inline DateTime &DateTime::operator-=(time_t seconds)
{
    return operator+=(-seconds);
}
