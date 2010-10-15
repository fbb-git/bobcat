#include "iostreambuf.ih"

std::ios::pos_type IOStreambuf::ioSeekoff(off_type offset, 
                            std::ios::seekdir way, std::ios::openmode mode)
{
    if (mode == std::ios::in)
    {
        if (d_in->seekg(offset, way))
        {
            setg(&d_buf, &d_buf + 1, &d_buf + 1);
            return d_in->tellg();
        }
    }
    else
    {
        if (d_out->seekp(offset, way))
            return d_out->tellp();
    }
    return -1;
}
