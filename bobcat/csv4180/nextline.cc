#include "csv4180.ih"

bool CSV4180::nextLine()
{
    cerr << __FILE__ "\n";

    if (not getline(*d_in, d_str))
        return false;

    d_begin = d_str.begin();
    d_end = d_str.end();

    return true;
}
