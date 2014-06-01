#include "sharedmemory.ih"

int SharedMemory::get()
{
    int ret;

    validate();

    map();

    if (d_pos.eof())
        ret = EOF;
    else
    {
        lock(d_pos.blockIdx());
            ret = *ptr();
            ++d_pos;
        unlock(d_pos.blockIdx());
    }

    return ret;    
}
