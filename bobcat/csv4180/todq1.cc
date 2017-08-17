#include "csv4180.ih"

bool CSV4180::toDq1()
{
    //cerr << __FILE__ "\n";

    ++d_begin;
    d_state = DQ1;
    return true;
}
