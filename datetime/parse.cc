#include "datetime.ih"

void DateTime::parse(istream &in)
{
    in >> d_tm.tm_year;

    if (!in)
        parseFromDayName(in);   // expect Sun (etc)
    else                        
    {                           // expect 2008-11-02 13:29:11+01:00
        char sep;
        in >> sep >> d_tm.tm_mon;
        --d_tm.tm_mon;

        in >> sep >> d_tm.tm_mday >> 
                    d_tm.tm_hour >> sep >>  
                    d_tm.tm_min >> sep >>  
                    d_tm.tm_sec;

        in.ignore(6);           // +01:00
    }

    d_ok = in;
    d_errno = 0;

    if (d_ok)
    {
        d_tm.tm_year -= 1900;
        d_time = mktime(&d_tm) + s_currentZoneCorrection; 
    }
}




