#include "csv4180.ih"

void CSV4180::dropFields()
{
    size_t pos = d_specs.find('X');
    if (pos == string::npos)                    // no fields to remove
        return;

                                                // first element to keep
    string::const_iterator indicator = d_specs.begin() + pos + 1;

    StrVector::iterator dest = d_header.begin() + pos;

        // dest: points at next el. in d_header to keep,
        // src, indicator: point at next element to inspect in resp. d_header
        //                 and d_spec
    for (
        StrVector::iterator src = dest + 1, end = d_header.end();
            src != end;
                ++indicator, ++src
    )
    {
        if (*indicator != 'X')                  // keep this element
            *dest++ = move(*src);
    }

    d_header.resize(dest - d_header.begin());   // remove superfluous entries
}
