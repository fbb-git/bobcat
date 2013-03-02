/*
                              driver.cc

   $Id: driver.cc,v 1.1.1.1 2005-08-19 15:12:52 frank Exp $

*/

#include <iostream>
#include <bobcat/x2a>

using namespace std;
using namespace FBB;

int main(int argc, char **argv, char **envp)
{
    string si(X2a(12));
    string sd(X2a(12.25));

    cout << si << " " << sd << endl;

    cout << "Two digits behind decimal dot: " << X2a(7, 2) << endl;
    cout << "Two digits behind decimal dot: " << X2a(7.1, 2) << endl;
    cout << "Two digits behind decimal dot: " << X2a(7.0 / 3, 2) << endl;
    cout << "Same,8 characters wide: " << X2a(7.0 / 3, 8, 2) << endl;
    cout << "                        " << "12345678"         << endl;

    return 0;
}

/*
    Output:

    12 12.25
*/
