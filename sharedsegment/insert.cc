#include "sharedsegment.hh"

ostream &SharedSegment::insert(ostream &out) const
{
    out << "Access mode: 0" << oct << d_access << dec << "\n"
            "Information readable until offset " << d_nReadable << "\n"
            "Size of the data segments: " << d_segmentSize << " bytes\n" <<
            d_nBlocks << " data segments may be defined, "
                "with a total capacity of " <<
                static_cast<double>(d_segmentSize) * d_nBlocks / 1024 << "kB";

    bool firstBlock = true;

    for (size_t idx = 0; idx != d_nBlocks; ++idx)
    {
        if (d_block[idx].id() != -1)
        {
            if (firstBlock)
            {
                firstBlock = false;
                out << "\n"
                       "ID(s) of data segments:";
            }
            out << "\n"
                   "    at idx " << idx << ": id = " << d_block[idx].id();
        }
    }

    return out;
}
