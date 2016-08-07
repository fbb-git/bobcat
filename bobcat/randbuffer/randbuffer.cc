#include "randbuffer.ih"

Randbuffer::Randbuffer(int min, int max, long seed)
{
    if (min <= max)
    {
        d_min = min;
        d_max = max;
    }
    else
    {
        d_min = max;
        d_max = min;
    }

    d_max++;

    srandom(static_cast<unsigned int>(seed));
    setg(0, 0, 0);
}
