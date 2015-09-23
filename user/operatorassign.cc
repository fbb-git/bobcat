#include "user.hh"

User &User::operator=(User &&tmp)
{
    fswap(*this, tmp);
    return *this;
}







