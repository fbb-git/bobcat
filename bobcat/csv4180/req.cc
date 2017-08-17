#include "csv4180.ih"

bool CSV4180::req()
{
    //cerr << __FILE__ "\n";

    if (not nextLine())                 // continue at the next line
    {
        d_state = ERROR;
        return false;
    }

    d_field += '\n';                    // indicate continuation by adding
                                        //  '\n'
    return true;
}
