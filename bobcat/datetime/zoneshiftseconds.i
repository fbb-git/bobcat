inline int DateTime::zoneShiftSeconds(int shiftMinutes)
{
    return  shiftMinutes / 30 * 30 % (12 * 60) * 60;
}
