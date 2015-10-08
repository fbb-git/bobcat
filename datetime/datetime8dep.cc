#include "datetime.ih"

DateTime::DateTime(string const &timeStr,  int displayZoneShift, int)
:
    d_type(LOCALTIME)
{
    static bool warned = false;
    if (!warned)
    {
        warned = true;
        cerr << "\n"
                "Warning: DateTime(string const &timeStr, "
                                "int displayZoneShift, int utcZoneShift)\n"
                "         This constructor is deprecated and is replaced by:\n"
                "         DateTime(string const &timeStr, "
                                                "int displayZoneShift)\n";
    }

    istringstream in(timeStr);
    parse(in);              // determine timestruct representing hour in UTC

    d_tm2d_tm(displayZoneShift);
}

