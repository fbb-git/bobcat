#include "csv4180.ih"

bool CSV4180::err()
{
    //cerr << __FILE__ "\n";

    d_state = ERROR;
    return false;
}
