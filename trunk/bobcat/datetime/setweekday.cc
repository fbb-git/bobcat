#include "datetime.ih"

bool DateTime::setWeekday(Weekday weekday, Relative where)
{
    TimeStruct tmStruct = d_tm;

    int difference = static_cast<int>(weekday) - tmStruct.tm_wday;

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

    tmStruct.tm_mday += difference;
    
    return updateTime(&tmStruct);
}
