#include "csv4180.ih"

bool CSV4180::field()
{
    cerr << __FILE__ "\n";

    ++d_begin;                              // skip the comma

    d_last.push_back(move(d_field));        // add the field to d_last,
                                            //  preparing d_field for the next 
                                            //  field

    d_state = START;
    return true;
}
