/*
                              driver.cc
*/

#include "driver.h"

#ifndef _INCLUDED_GETHOSTENT_H_
#include <fbb/gethostent.h>
#endif

#ifndef _SYSINC_ALGORITHM_
#include <algorithm>
#define _SYSINC_ALGORITHM_
#endif

#ifndef _INCLUDED_HOSTENT_H_
#include <fbb/hostent.h>
#endif

#ifndef _SYSINC_ITERATOR_
#include <iterator>
#define _SYSINC_ITERATOR_
#endif


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
        for (unsigned idx = 0; idx < he.nAddresses(); idx++)
            cout << he.dottedDecimalAddress(idx) << endl;
    }
    catch (Errno const &err)
    {
        cout << err.what() << endl;
        return 1;
    }
    return 0;
}


