/*
                              driver.cc
*/

#include "driver.h"

#ifndef _INCLUDED_HOSTENT_H_
#include <fbb/hostent.h>
#endif
#ifndef _SYSINC_ALGORITHM_
#include <algorithm>
#define _SYSINC_ALGORITHM_
#endif
#ifndef _SYSINC_ITERATOR_
#include <iterator>
#define _SYSINC_ITERATOR_
#endif

using namespace std;
using namespace FBB;


int main(int argc, char **argv, char **envp)
{
    Hostent he(gethostbyname("localhost"));

    {
        Hostent he2(he);

        cout << "The local hostname = " << he2.hostname() << endl;

        cout << "All aliases: " << endl;
        copy(he2.beginAlias(), he2.endAlias(), 
                    ostream_iterator<char const *>(cout, "\n"));


        cout << "Addresses:\n";
        for (unsigned idx = 0; idx < he2.nAddresses(); idx++)
            cout << he2.dottedDecimalAddress(idx) << endl;

        cout << "he2 destroyed\n";
    }
    return 0;
}




