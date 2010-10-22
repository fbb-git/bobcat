#include <bobcat/msg>
#include <iostream>
#include <algorithm>
#include <iterator>


using namespace FBB;
using namespace std;

int main(int argc, char **argv)
try
{
    cerr << "Any msg stream operational? " << boolalpha << Msg::display() <<
                                                                    '\n';

    Msg::setDisplay(Msg::INFO, false);          // no info msg
    imsg << "Msg not shown" << endm;

    Msg::setDisplay(true);                      // all are shown again
    imsg << "Info msg" << endm;

    wmsg << "A warning msg" << endm;
    emsg << "An error msg" << endm;

    Msg::setDisplay(Msg::INFO, wmsg);           // info becomes warning
    imsg << "Info msg as a warning msg" << endm;

    Msg::setDisplay(Msg::INFO, "info.txt", UINT_MAX);     // info to info.txt
    imsg << "Info to info.txt" << endm;

    Msg::setDisplay(Msg::INFO, cout, UINT_MAX); // reset to the original form
    imsg << "Info msg as an info msg" << endm;

    Msg::setDisplay(Msg::FATAL, cerr);

    Msg::setDisplay(Msg::INFO, false);

    if (argc == 1)
        msg() << "Non-redirectable: need some arguments" << fatal;
    else
    {
        Msg::setDisplay(true);
        msg() << "Thanks for providing " << argc << 
                                " arguments " << info;
    }

    string str[] = {"one", "two", "three"};
    copy(str, str + sizeof(str) / sizeof(string), 
            ostream_iterator<string>(imsg, " "));

    emsg << "This is an error message" << endm;
    imsg << "This is an informational message" << endm;

    wmsg << "This is a warning message" << endm;

    cout << "Enter the name of a non-existing (unreadable) file: ";
    string fname;
    getline(cin, fname);
    try
    {
        ifstream in;
        Msg::open(in, fname);
    }
    catch(...)
    {
        emsg << fname << " indeed couldn't be read" << endm;
    }

}            
catch(Errno const &e)
{
    cerr << "Exception: " << 
        (e.which() == fmsg.asInt() ? "fmsg" : "unknown") << ": " <<
        e.why() << "\n";

    msg() << "Got an Errno object, but ignoring it" << err;
}
