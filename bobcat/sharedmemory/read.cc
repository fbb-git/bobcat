#include "sharedmemory.ih"

int SharedMemory::read(char *data, streamsize len)
{
    if (d_pos.eof())
        return -1;

    streamsize begin = d_pos.offset();

//cerr << "read at " << begin << ", len = " << len << '\n';

    while (len != 0)
    {
        int nReceived = readBlock(data, len);

//cerr << "read " <<  nReceived << '\n';

        if (nReceived == -1)
            break;

        len -= nReceived;
        data += nReceived;
        d_pos += nReceived;


//cerr << "Next offset: " << d_pos.offset() << ", len = " << len << '\n';
    }

    return d_pos.offset() - begin;
}







