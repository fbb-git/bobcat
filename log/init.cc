#include "log.ih"

void Log::init()
{
    d_level = 0;
    d_activeLevel = numeric_limits<size_t>::max();
}
