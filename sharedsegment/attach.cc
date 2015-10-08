#include "sharedsegment.ih"

void *SharedSegment::attach(int id)
{
    void *ret = shmat(id, 0, 0);

    if (ret == reinterpret_cast<void *>(-1))
        throw Exception() << "Can't attach shared segment segment " << id;

    return ret;
}


