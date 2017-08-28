#include "qpstreambufbase.ih"

// #include <iostream>

bool QPStreambufBase::filter(char const **srcBegin, char const **srcEnd)
{
    if (d_allDone)
        return false;

    d_buffer.clear();
    d_allDone = (this->*d_action)() == false;   // false: all conversions
                                                //  completed

    *srcBegin = d_buffer.data();                // set the begin and end ptrs
    *srcEnd = *srcBegin + d_buffer.size();

    return d_buffer.size();                     // any chars available: true
}

