#include "sharedmemory.ih"

int SharedMemory::writeBlock(char const *data, size_t len)
{
    if (d_pos.atMaxOffset())
        return -1;

    map();

    size_t remaining = d_pos.eos() - d_pos.offset();

//cerr << "eos: " << d_pos.eos() << " remaining: " << remaining;

    if (remaining < len)
        len = remaining;

//cerr << " len = " << len << ", blockIdx = " << d_pos.blockIdx() << '\n';

    lock(d_pos.blockIdx());
        memcpy(d_data + d_pos.blockOffset(), data, len);
    unlock(d_pos.blockIdx());

    return len;
}

