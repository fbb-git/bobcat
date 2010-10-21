#include <bobcat/msg>
#include <iostream>
#include <algorithm>
#include <iterator>


using namespace FBB;
using namespace std;

int main(int argc, char **argv)
try
{
    Msg::setDisplay(Msg::FATAL, cerr.rdbuf());

    Msg::setDisplay(Msg::INFO, false);

//    if (argc == 1)
//        msg() << "Non-redirectable: need some arguments" << fatal;
//    else
//    {
//        Msg::setDisplay(true);
//        msg() << "Thanks for providing " << argc << 
//                                " arguments " << info;
//    }

//    string str[] = {"one", "two", "three"};
//    copy(str, str + sizeof(str) / sizeof(string), 
//            ostream_iterator<string>(imsg, " "));
//
    emsg << "This is an error message" << endm;
    imsg << "This is an informational message" << endm;
//    wmsg << "This is a warning message" << endm;
//    fmsg << "This is a fatal message" << endm;
}            
catch(Errno const &e)
{
    cerr << "Exception: " << 
        (e.which() == fmsg.asInt() ? "fmsg" : "unknown") << ": " <<
        e.why() << "\n";

    msg() << "Got an Errno object, but ignoring it" << err;
}
