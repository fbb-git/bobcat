#include "datetime.ih"

DateTime &DateTime::operator+=(TimeStruct const &fields)
{
    d_time += utcCorrection(&fields);
    breakDown();
    return *this;
}
