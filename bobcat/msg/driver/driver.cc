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

    imsg << "This is an informational message" << endl;
    emsg << "This is an error message" << endl;
    wmsg << "This is a warning message" << endl;
    fmsg << "This is a fatal message" << endl;
}            
catch(...)
{
    msg() << "Got an Errno object, but ignoring it" << err;
}
