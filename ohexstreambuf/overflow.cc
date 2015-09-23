#include "ohexstreambuf.hh"

int OHexStreambuf::overflow(int ch)
{
    out() << setw(2) << ch;
    if (d_width && (d_count += 2) >= d_width)
    {
        d_count = 0;
        out() << '\n';
    }

    return ch;
}

