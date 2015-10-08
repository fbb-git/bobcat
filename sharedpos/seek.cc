#include "sharedpos.ih"

ios::pos_type SharedPos::seek(ios::off_type offset, ios::seekdir way)
{
    if (way == ios::cur)
        offset += d_offset;
    else if (way == ios::end)
        offset += nReadable();

    if (0 <= offset && offset <= d_maxOffset)
    {
        d_offset = offset;
        update();
    }
    else
        offset = -1;

    return offset;
}

