#include "datetime.ih"

bool DateTime::setWeekday(Weekday weekday, Relative where)
{
    TimeStruct ts = d_tm;

    int difference = static_cast<int>(weekday) - ts.tm_wday;

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
        throw Exception(1) << 
                            "DateTime::setWeekday(): invalid Relative spec.";
    }

    ts.tm_mday += difference;
    
    return updateTime(ts);
}



