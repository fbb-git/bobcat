#include "datetime.ih"

bool DateTime::breakDown(struct tm *tmStruct, TimeType type, time_t time)
{
    return type == LOCALTIME ?
                localtime_r(&time, tmStruct)
            :
                gmtime_r(&time, tmStruct);
}
