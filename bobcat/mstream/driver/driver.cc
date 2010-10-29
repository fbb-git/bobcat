#include <iostream>
#include <algorithm>
#include <iterator>

#include <bobcat/mstream>
#include <bobcat/errno>

using namespace std;
using namespace FBB;

int main(int argc, char **argv)
try
{
    imsg << "Informational: " << endl;
    imsg.off();
    cout << "The i-msg stream is now off. This message should appear once" <<
                                                                        endl;
    imsg << "The i-msg stream is now off. This message should appear once" <<
                                                                        endl;
    imsg << "The i-msg stream is now off. This message should appear once" <<
                                                                        endl;
    cout << "But this message is shown" << endl;

    wmsg << "Warning message" << endl;
    emsg << "Oops, this this is an error (not really)" << endl;
    emsg << "Oops, this goes wrong, too" << endl;

    imsg.on();
    imsg << "And another informational msg: " << emsg.count() << 
            " error messages\n" << flush;

    emsg << "Third error" << endl;
    emsg.setMaxCount(3);

    imsg << "Msg in between" << endl;

    cerr << "(cerr) LineExcess: " << emsg.lineExcess() << ", count = " <<
            emsg.count() << endl;

    emsg << "Fourth error" << endl;

    cerr << "(cerr) LineExcess: " << emsg.lineExcess() << ", count = " <<
            emsg.count() << endl;

    cerr << "Beyond\n";
}            
catch(FBB::Errno const &e)
{
    std::cerr << "Got an Errno object: " << e.why() << '\n';
}
catch(...)
{
    std::cerr << "Got an exception\n";
}






