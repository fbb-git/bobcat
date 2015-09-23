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


int main(int argc, char **argv, char **envp)
{
    if (argc == 1)
    {
        cerr << "Provide a host name or host address to solve\n";
        return 1;
    }

    try
    {
        Hostent he(GetHostent::gethostent(argv[1], argv[1]));
        cout << "Hostname: " << he.hostname() << endl;

        cout << "Aliases:\n";
        copy(he.beginAlias(), he.endAlias(), ostream_iterator<char const
                *>(cout, "\n"));

        cout << "Addresses:\n";
        for (size_t idx = 0; idx < he.nAddresses(); idx++)
            cout << he.dottedDecimalAddress(idx) << endl;
    }
    catch (exception const &err)
    {
        cout << err.what() << endl;
        return 1;
    }
}


