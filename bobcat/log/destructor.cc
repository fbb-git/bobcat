#include "log.ih"

Log::~Log()
{
    if (s_stream == this)
        s_stream = 0;
}
