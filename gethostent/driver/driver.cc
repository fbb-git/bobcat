/*
                              driver.cc
*/

#include <iostream>
#include <algorithm>
#include <iterator>

#include <bobcat/hostent>
#include <bobcat/gethostent>

using namespace std;
using namespace FBB;

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        cerr << "Provide a host name or host address to solve\n";
        return 0;
    }

    try
    {
        Hostent he(GetHostent::gethostent(argv[1], argv[1]));

        cout << "Hostname: " << he.hostname() << '\n';

        if (he.beginAlias() != he.endAlias())
        {
            cout << "Aliases:\n";
            copy(he.beginAlias(), he.endAlias(), 
                    ostream_iterator<char const *>(cout, "\n"));
        }

        cout << "Address(es):\n";
        for (size_t idx = 0; idx < he.nAddresses(); idx++)
            cout << he.dottedDecimalAddress(idx) << '\n';
    }
    catch (exception const &err)
    {
        cout << err.what() << '\n';
        return 1;
    }
}


