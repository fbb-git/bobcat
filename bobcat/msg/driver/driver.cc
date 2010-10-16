#include <bobcat/msg>
#include <iostream>

using namespace FBB;
using namespace std;

int main(int argc, char **argv)
try
{
    Msg::setDisplay(Msg::FATAL, cerr.rdbuf());

    if (argc == 1)
        msg() << "Non-redirectable: need some arguments" << fatal;
    else
    {
        Msg::setDisplay(true);
        msg() << "Thanks for providing " << argc << 
                                " arguments " << info;
    }
}            
catch(...)
{
    msg() << "Got an Errno object, but ignoring it" << err;
}
