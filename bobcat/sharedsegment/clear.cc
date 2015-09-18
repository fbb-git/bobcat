#include "sharedsegment.hh"

void SharedSegment::clear()
{
    d_nReadable = 0;

    for (auto &block: ranger(d_block, d_block + d_nBlocks))
    {
        int id = block.id();

        if (id != -1)
        {
            deleteSegment(id);
            block.setID(-1);
        }
    }
}
