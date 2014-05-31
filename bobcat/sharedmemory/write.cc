#include "sharedmemory.ih"

//#include <iostream>

int SharedMemory::write(char const *data, streamsize len)
{
    if (d_pos.atMaxOffset())
        return -1;

    streamsize begin = d_pos.offset();

//cerr << "write at " << begin << ", len = " << len << '\n';

    while (len != 0)
    {
        int nChars = writeBlock(data, len);       // locks, updates d_offset

//cerr << "wrote " <<  nChars << '\n';

        if (nChars == -1)                         // hit maxOffset()
            break;

        len -= nChars;
        data += nChars;
        d_pos += nChars;

    
        d_sharedSegment->updateNreadable(d_pos.offset());

//cerr << "Next offset: " << d_pos.offset() << ", len = " << len << '\n';
    }

//cerr << ".write wrote " << (d_pos.offset() - begin) << " chars\n";

    return d_pos.offset() - begin;
}
