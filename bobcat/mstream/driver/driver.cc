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

    wmsg << "Warning message" << endl;
    emsg << "Oops, this goes wrong" << endl;
    emsg << "Oops, this goes wrong, too" << endl;

    imsg.off();
    imsg << "Not shown" << endl;

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






