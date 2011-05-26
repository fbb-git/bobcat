#include "datetime.ih"

void DateTime::parseFromDayName(istream &in)
{
    in.clear();

    // Sun  Nov  2       13:29:11  2008        - asctime()
    // Sun Jul  5        23:06:10  CEST 2009   - date(1)
    // Sun, 05 Jul  2009 23:06:25  +0200       - date(1) -R

    string day;
    string mon;

    in >> day;

    bool date_R = day.find(',') != string::npos;

    if (date_R)
        in >> d_tm.tm_mday >> mon >> d_tm.tm_year;
    else
        in >> mon >> d_tm.tm_mday;

    d_tm.tm_mon = find(s_month, s_month + 12, mon) - s_month;

    char sep;
    in >> d_tm.tm_hour >> sep >>  
          d_tm.tm_min >> sep >>  
          d_tm.tm_sec;

    if (date_R)
    {
        in.ignore(6);
        return;
    }
        
    if (!(in >> d_tm.tm_year))
    {
        in.clear();                     // extract TZ name first
        string tzName;
        in >> tzName >> d_tm.tm_year;
    }

    // called from parse(); parse() subtracts 1900 from tm_year
}




