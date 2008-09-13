#include <bobcat/user>
#include <iostream>

using namespace std;
using namespace FBB;

int main()
{
    User  user;
    user.verify();

    cout << "\n"
        "name       : " << user.name()      << "\n" <<
        "password   : " << user.password()  << "\n" <<
        "user id    : " << user.userid()    << "\n" <<
        "group id   : " << user.groupid()   << "\n" <<
        "real name  : " << user.realname()  << "\n" <<
        "home dir   : " << user.homedir()   << "\n" <<
        "shell      : " << user.shell()     << "\n" << endl;

    return 0;
}
