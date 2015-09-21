
#include <iostream>
#include <bobcat/exception>
#include <bobcat/mbuf>

using namespace std;
using namespace FBB;
// using namespace FBB::BOBCAT;

int main()
{
    ostream os(cout.rdbuf());

    Mbuf msb(&os);

    Msg ms(msb);

    string s;

    ms << "hello world" << s << 12 << endl;     // explicit flush

    os.setstate(ios::badbit);

    ms << "this should fail" << endl;     // explicit flush


    os.clear();

    ms << "this should be shown" << endl;     // explicit flush


    msb.reset(&cout, true);         // throwing buffer
    try
    {
        ms << "Following this, we throw" << endl;
    }
    catch (exception const &err)
    {
        cout << "Caught Exception exception" << endl;
    }
}




