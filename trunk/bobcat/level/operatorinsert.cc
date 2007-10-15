#include "level.ih"

ostream &operator<<(ostream &str, level const &lv)
{
    Log *lp = dynamic_cast<Log *>(&str);        // a Log object is required.

    return !lp ?                                // if not, ignore the manip.
                str
            :
                lv.insertInto(str, *lp);
}
        
