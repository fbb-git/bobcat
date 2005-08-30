#include "log.ih"

ostream &Log::level(unsigned activeLevel)
{
    d_activeLevel = activeLevel;
    setActive(d_level <= d_activeLevel);

    return *this;
}
