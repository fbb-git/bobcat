#include "user.ih"

#include "../iuo/iuo"

User &User::operator=(User const &&tmp)
{
    static bool called = false;
    deprecated__(called, "User::operator=(User const &&tmp) is "
                        "deprecated. Please recompile this program");
    fswap(*this, const_cast<User &>(tmp));
    return *this;
}







