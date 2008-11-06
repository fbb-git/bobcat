#include "datetime.ih"

void DateTime::parseFromDayName(istream &in)
{
    in.clear();

    string day;
    string mon;

    in >> day >> mon;
    d_tm.tm_mon = find(s_month, s_month + 12, mon) - s_month;

    char sep;
    in >> d_tm.tm_mday >> 
          d_tm.tm_hour >> sep >>  
          d_tm.tm_min >> sep >>  
          d_tm.tm_sec >>
          d_tm.tm_year;

    if (day.find(',') != string::npos)  // Sun, Nov 2 13:29:11 2008 +0100
        in.ignore(6);

    if (!in)        // At the name of he timezone
    {
        in.clear();
        in >> mon >> d_tm.tm_year;
    }

    // called from parse(); parse() will subtract 1900 from tm_year
}
