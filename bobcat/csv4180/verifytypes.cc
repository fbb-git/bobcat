#include "csv4180.ih"

bool CSV4180::verifyTypes()
try
{
                                                // first element to inspect
    string::const_iterator indicator = d_specs.begin();

        // dest: points at next el. in d_header to keep,
        // src, indicator: point at next element to inspect in resp. d_header
        //                 and d_spec
    for (
        StrVector::iterator dest = d_last.begin(), src = dest, 
                            end = d_last.end();
            src != end;
                ++indicator, ++src
    )
    {
        switch (*indicator)
        {
            case 'X':                   // omit
            continue;                   // continue with the next src item

            case 'I':
                stoll(*src);
            break;

            case 'D':
                stold(*src);
            break;             
            
            default:                    // accept all other (just 'S') as-is
            break;
        }
        *dest++ = move(*src);           // accept this element
    }
    return true;
}
catch (...)
{
    d_in->setstate(ios::failbit);
    d_state = ERROR;
    return false;
}        



