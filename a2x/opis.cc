#include "a2x.hh"

A2x &A2x::operator=(char const *txt)
{
    clear();                    // very important!!! If a previous conversion 
                                // failed, the object will remain useless 
                                // until executing this statement
    str(txt);
    return *this;
}
