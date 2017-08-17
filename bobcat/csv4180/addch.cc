#include "csv4180.ih"

bool CSV4180::addCh()
{
    cerr << __FILE__ "\n";

    d_field += *d_begin++;
    d_state = CHARSTATE;
    return true;
}
