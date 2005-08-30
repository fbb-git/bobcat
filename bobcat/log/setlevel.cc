#include "log.ih"

void Log::setLevel(unsigned newLevel)
{
    d_level = newLevel;
    level(d_activeLevel);
}
