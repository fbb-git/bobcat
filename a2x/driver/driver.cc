/*
                              driver.cc

*/

#include <iostream>
#include "../a2x"


using namespace std;
using namespace FBB;

int main(int argc, char **argv)
{
    int x = A2x("12");

    cout << x << endl;

    cout << x << endl;

    A2x a2x("12.50");

    double d;

    d = a2x;

    cout << d << endl;

    A2x("12.345") >> d;

    cout << d << endl;

    cout << "Again: " << A2x("12.345").to<double>() << endl;
    a2x = "err";

    d = a2x;        // d now 0

    cout << d << endl;

    a2x = " a";

    char c = a2x;   // c now 'a'

    cout << c << endl;
}

/*
    Output:

    12
    12.5
    12.345
    0
    a

*/
