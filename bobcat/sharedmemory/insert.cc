#include "sharedmemory.ih"

ostream &SharedMemory::insert(ostream &out) const
{
    if (d_sharedSegment == 0)
        return out << "No shared data available";

    out << "ID of shared memory segment: " << d_id << '\n';
    
    if (d_data == 0)
        out << "No shared memory data block attached\n";
    else
        out << "Shared memory block attached at address " << 
                static_cast<void *>(d_data) << ", block index = " <<
                d_pos.blockIdx() << '\n';

    return out << *d_sharedSegment << '\n' <<
                  d_pos;
}
