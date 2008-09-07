#include "datetime.ih"

bool DateTime::setWeekday(WeekDay weekday, Relative where)
{
    if (!d_ok)
        return false;

    struct tm tmStruct = d_tm;

    int difference = static_cast<int>(weekday) - tmStruct.tm_wday;

cout <<         tmStruct.tm_wday << ' ' <<  difference << endl;

    switch (where)
    {
        case NEXT:
            difference += 7;
        break;
        case LAST:
            difference  -= 7;
        break;
        case THIS_WEEK:
        break;
        default:
        throw Errno(1, "DateTime::setWeekday(): invalid Relative spec.");
    }

cout <<         tmStruct.tm_mday << ' ' <<  difference << endl;

    tmStruct.tm_mday += difference;

cout <<         tmStruct.tm_mday << ' ' <<  difference << endl;

    
    return updateTime(&tmStruct);
}

