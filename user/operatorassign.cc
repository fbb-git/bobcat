#include "user.ih"

User &User::operator=(User &&tmp)
{
    fswap(*this, tmp, d_name, d_password, d_realname, d_homedir, d_shell);
    return *this;
}







