inline void Selector::noAlarm()
{
    d_alarm.tv_sec = d_alarm.tv_usec = -1;
}
