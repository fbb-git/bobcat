/*
                              driver.cc
*/


#include <iostream>
#include <fstream>
#include <bobcat/multistreambuf>

using namespace std;
using namespace FBB;

int main(int argc, char **argv)
{
    MultiStreambuf  msb(cout);
    ostream         os(&msb);
    ofstream        out("out");

    msb.insert(out, MultiStreambuf::ONCE);

    os << "This is on cout and out" << endl;
    os << "This is on cout only" << endl;

    msb.setOnce();
    os << "This is on cout and out" << endl;
    os << "This is on cout only" << endl;
}
