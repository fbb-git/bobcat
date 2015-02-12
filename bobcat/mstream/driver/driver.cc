#include <iostream>
#include <algorithm>
#include <iterator>

#include <bobcat/mstream>

using namespace std;
using namespace FBB;

int main(int argc, char **argv)
try
{
    cout << sizeof(Mstream) << ' ' << sizeof(Mbuf) << '\n';

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
    emsg << "Oops, this goes wrong, too" << noid;

    imsg.on();
    imsg << "And another informational msg: " << emsg.count() << 
            " error messages\n" << flush;

    emsg << "Third error" << endl;
    emsg.setMaxCount(3);

    imsg << "Msg in between" << endl;

    imsg.setTag("tag");
    imsg << "tagged message" << endl;

    imsg.setTag("label");
    imsg << "labeled message" << endl;

    cerr << "(cerr) LineExcess: " << emsg.lineExcess() << ", count = " <<
            emsg.count() << endl;

    emsg << "Fourth error\n" << noid;       // no id is shown
    emsg << "Fourth error\n" << flush;      // shows id (remove the previous
                                            // statement)

    cerr << "(cerr) LineExcess: " << emsg.lineExcess() << ", count = " <<
            emsg.count() << endl;

    cerr << "Beyond\n";
}            
catch(exception const &e)
{
    std::cerr << "Got a std::exception: " << e.what() << '\n';
}
catch(...)
{
    std::cerr << "Got an exception\n";
}






