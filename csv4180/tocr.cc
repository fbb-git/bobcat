#include "csv4180.ih"

bool CSV4180::toCr()
{
    //cerr << __FILE__ "\n";

    ++d_begin;
    d_state = CRSTATE;
    return true;
}
