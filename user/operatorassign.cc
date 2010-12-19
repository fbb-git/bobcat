#include "user.ih"

User &User::operator=(User const &&tmp)
{
    fswap(*this, const_cast<User &>(tmp));
    return *this;
}







