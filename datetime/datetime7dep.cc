#include "datetime.ih"

DateTime::DateTime(string const &timeStr,  TimeType type, int)
:
    d_type(type),
    d_displayZoneShift(0),
    d_dstShift(0)
{
    static bool warned = false;
    if (!warned)
    {
        warned = true;
        cerr << "\n"
                "Warning: DateTime(string const &timeStr, TimeType type, "
                                                        "int utcZoneShift)\n"
                "         This constructor is deprecated and is replaced by:\n"
                "         DateTime(string const &timeStr, TimeType type)\n";
    }

    istringstream in(timeStr);
    parse(in);              // determine timestruct representing hour in UTC


    d_tm2timeType();
}

