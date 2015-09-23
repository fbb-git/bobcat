#include "log.hh"

ostream &Log::level(size_t activeLevel)
{
    d_activeLevel = activeLevel;
    setActive(d_level <= d_activeLevel);

    return *this;
}
