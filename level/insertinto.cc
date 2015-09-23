#include "level.hh"

std::ostream &level::insertInto(ostream &str, Log &lp) const
{
    LogBuffer *lb = dynamic_cast<LogBuffer *>(lp.rdbuf());

    return 
        !lb->empty() ?                          // the object's message buffer
                                                // must be empty.
            str                                 // if not, ignore the
                                                // manipulator 
        :
            lp.level(d_level);                 // otherwise set the level.
}
