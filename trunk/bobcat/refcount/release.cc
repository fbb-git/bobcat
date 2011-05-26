#include "refcount.ih"

void RefCount::release()
{
    if (--d_refcount == 0)
        delete this;
}
