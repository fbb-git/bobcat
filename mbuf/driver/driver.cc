
#include <iostream>
#include <bobcat/exception>
#include <bobcat/mbuf>
#include <bobcat/mstream>

using namespace std;
using namespace FBB;

int main()
{
    Mbuf msb(cout.rdbuf());

    Mstream ms(&msb);

    string s;

    ms << "hello world" << s << 12 << endl;     // explicit flush

    ms.setstate(ios::badbit);

    ms << "this should fail" << endl;           // explicit flush

    ms.clear();

    ms << "this should be shown" << endl;     // explicit flush

    ms.setMaxCount(0);

    try
    {
        ms << "Following this, we throw" << endl;
    }
    catch (exception const &err)
    {
        cerr << "Caught exception" << endl;
    }

    cout << "leaving " << ms.bad() << "\n";

}









