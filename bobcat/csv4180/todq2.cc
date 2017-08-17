#include "csv4180.ih"

bool CSV4180::toDq2()
{
    //cerr << __FILE__ "\n";

    ++d_begin;
    d_state = DQ2;
    return true;
}
