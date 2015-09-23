#include "log.hh"

void Log::setLevel(size_t newLevel)
{
    d_level = newLevel;
    level(d_activeLevel);
}
