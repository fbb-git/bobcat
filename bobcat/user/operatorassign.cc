#include "user.ih"

User &User::operator=(User &&tmp)
{
    fswap(*this, tmp);
    return *this;
}







