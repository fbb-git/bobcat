#include "csv4180.ih"

bool CSV4180::addDq1()
{
    cerr << __FILE__ "\n";

    d_field += *d_begin++;
    d_state = DQ1;
    return true;
}
