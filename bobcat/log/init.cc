#include "log.ih"

void Log::init(StaticType type)
{
    d_level = 0;
    d_activeLevel = UINT_MAX;

    if (type == STATIC)
        s_stream = this;
}
