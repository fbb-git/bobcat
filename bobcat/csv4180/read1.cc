#include "csv4180.ih"

istream &CSV4180::read1(istream &in)
{
    d_state = START;
    d_in = &in;

    if (not nextLine())
        return in;

    while ((this->*s_fsa[d_state][peek()])())
        ;

    return in;    
}
