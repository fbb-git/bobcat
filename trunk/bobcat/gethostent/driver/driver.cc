/*
                              driver.cc
*/

#include "driver.h"

#include <fbb/gethostent.h>
#include <algorithm>
#include <fbb/hostent.h>
#include <iterator>

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
    catch (Errno const &err)
    {
        cout << err.why() << endl;
        return 1;
    }
    return 0;
}


