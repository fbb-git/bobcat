#include "user.ih"

#include "../iuo/iuo"

User &User::operator=(User const &&tmp)
{
    static bool called = false;
    deprecated__(called, "User::operator=(User const &&tmp) is");
    fswap(*this, const_cast<User &>(tmp));
    return *this;
}







