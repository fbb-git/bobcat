#include "datetime.ih"

namespace std
{

istream &operator>>(istream &in, FBB::DateTime &dt)
{
    dt.parse(in);
    return in;    
}

}

