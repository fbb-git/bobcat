#include "sharedsegment.ih"

int SharedSegment::newData(size_t idx)
{
    int id = newSegment(d_segmentSize, d_access);
 
    d_block[idx].setID(id);

    return id;
}
