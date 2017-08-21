#include "csv4180.ih"

bool CSV4180::end()
{
    //cerr << __FILE__ "\n";

    d_last.push_back(move(d_field));

    if (d_nRequired == 0)
        d_nRequired = d_last.size();
    else if (d_last.size() != d_nRequired)
    {
        d_in->setstate(ios::failbit);
        d_setHeader = false;
        return false;
    }

    if (not d_setHeader)
    {
        if ( (this->*d_verifyTypes)() )
            d_data.push_back(move(d_last));
    }
    else 
    {
        d_header = move(d_last);            // setting the header clears 
                                            //  d_last
        (this->*d_dropFields)();
        d_setHeader = false;
    }

    return false;
}





