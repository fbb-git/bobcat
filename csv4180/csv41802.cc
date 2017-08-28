#include "csv4180.ih"

CSV4180::CSV4180(string const &specs, bool header)
:
    d_setHeader(header)
{
    setSpecs(specs);
    d_nRequired = d_specs.length();         // required # fields per line
}
