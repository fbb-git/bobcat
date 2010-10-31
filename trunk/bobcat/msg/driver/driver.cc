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

    imsg.reset(wmsg);                           // info becomes warning
    imsg << "Info msg as a warning msg" << endm;

    imsg.reset("info.txt");                     // info to info.txt
    imsg << "Info to info.txt" << endm;

    imsg.reset(cout);                           // reset to the original form
    imsg << "Info msg as an info msg" << endm;

    fmsg.reset(cerr);

    Msg::setDisplay(Msg::INFO, false);

    if (argc == 1)
        fmsg << "Non-redirectable: need some arguments" << endm;
    else
    {
        Msg::setDisplay(true);
        imsg << "Thanks for providing " << argc << " arguments " << endm;
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
        (e.which() == fmsg.id() ? "fmsg" : "unknown") << ": " <<
        e.why() << "\n";

    msg() << "Got an Errno object, but ignoring it" << err;
}
