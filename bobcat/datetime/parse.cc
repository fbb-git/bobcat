#include "datetime.ih"

void DateTime::parse(string const &timeStr)
{
    istringstream in(timeStr);

    in >> d_tm.tm_year;

    if (!in)
        parseFromDayName(in);
    else
    {
        char sep;
        in >> sep >> d_tm.tm_mon;
        --d_tm.tm_mon;

        in >> sep >> d_tm.tm_mday >> 
                    d_tm.tm_hour >> sep >>  
                    d_tm.tm_min >> sep >>  
                    d_tm.tm_sec;
    }

    d_tm.tm_year -= 1900;

    d_time = mktime(&d_tm);             // the intended UTC time in seconds
    breakDown();    
}
