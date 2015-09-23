#include "sharedmemory.hh"

int SharedMemory::readBlock(char *data, size_t len)
{
    if (d_pos.eof())
        return -1;

    streamsize maxReadable = d_sharedSegment->nReadable();

    map();

    streamsize nReadable = d_pos.eos();

//cerr << "eos: " << nReadable << " maxReadable: " << maxReadable;

    if (maxReadable < nReadable)
        nReadable = maxReadable;

    size_t remaining = nReadable - d_pos.offset();

//cerr << " remaining: " << remaining;

    if (remaining < len)
        len = remaining;
    
//cerr << " len = " << len << ", blockIdx = " << d_pos.blockIdx() << 
//" blockOffset = " << d_pos.blockOffset() << '\n';

    lock(d_pos.blockIdx());
        memcpy(data, d_data + d_pos.blockOffset(), len);
//cerr << "-->";
//cerr.write(d_data + d_pos.blockOffset(), len);
//cerr << "<--\n";

    unlock(d_pos.blockIdx());

    return len;
}





