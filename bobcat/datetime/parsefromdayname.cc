#include "datetime.ih"

void DateTime::parseFromDayName(istringstream &in)
{
    string mon;

    in.clear();

    in >> mon >> mon;
    d_tm.tm_mon = find(s_month, s_month + 12, mon) - s_month;

    char sep;
    in >> d_tm.tm_mday >> 
          d_tm.tm_hour >> sep >>  
          d_tm.tm_min >> sep >>  
          d_tm.tm_sec >>
          d_tm.tm_year;

    if (!in)        // At the name of he timezone
    {
        in.clear();
        in >> mon >> d_tm.tm_year;
    }

    // called from parse(); parse() will subtract 1900 from tm_year
}
