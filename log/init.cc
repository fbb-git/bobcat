#include "log.hh"

void Log::init()
{
    d_activeLevel = numeric_limits<size_t>::max();
    setLevel(0);
}
