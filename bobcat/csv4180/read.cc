#include "csv4180.ih"

size_t CSV4180::read(istream &in, size_t nLines)
{
    size_t idx = 0;

    if (nLines == 0)
        nLines = ~0;

    for (; idx != nLines; ++idx)        // read all required lines or stop
    {                                   // once reading fails.
        if (not read1(in))
            break;
    }

    if (nLines == static_cast<size_t>(~0))  // at undetermined # lines:
        in.clear();                         //  reset `in' as it may contain
                                            //  additional info
    return d_data.size();
}
