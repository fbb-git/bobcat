#ifndef _INCLUDED_IOSTREAM_
#include <iostream>
#define _INCLUDED_IOSTREAM_
#endif

#ifndef _INCLUDED_ISTREAM_
#include <istream>
#define _INCLUDED_ISTREAM_
#endif

#ifndef _INCLUDED_RANDBUFFER_H_
#include "../randbuffer.h"
#endif

using namespace std;
using namespace FBB;

int main(int argc, char **argv, char **envp)
{
    if (argc == 1)
    {
        cout << "expect: nruns min max seed\n";
        return 1;
    }

    
    Randbuffer rb(atoi(argv[2]), atoi(argv[3]), atoi(argv[4]));

    istream istr(&rb);

    for (int idx = atoi(argv[1]); idx--; )
    {
        int c;
        if (!(istr >> c))
        {
            cout << "extraction failed\n";
            break;
        }    
        cout << "next: " << c << endl;
    }

    int count = 0;
    while (istr.unget())
        count++;

    cout << "number of successful unget()-calls: " << count << endl;
    istr.clear();
    istr >> count;
    cout << "and read: " << count << endl;
    
    return 0;
}

