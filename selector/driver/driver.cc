#ifndef _INCLUDED_SELECTOR_H_
#include "../selector.h"
#endif

#ifndef _INCLUDED_ERRNO_H_
#include "../../errno/errno.h"
#endif

#ifndef _SYSINC_STRING_
#include <string>
#define _SYSINC_STRING_
#endif

#ifndef _SYSINC_IOSTREAM_
#include <iostream>
#define _SYSINC_IOSTREAM_
#endif

using namespace std;
using namespace FBB;

int main(int argc, char **argv, char **envp)
{
    Selector selector;

    selector.setAlarm(5);               // every 5 secs: alarm fires
    selector.addReadFd(STDIN_FILENO);   // look also at cin

    try
    {
        while (true)
        {
            if (!selector.wait())           // 0: alarm fires
                cout << "Are you still there?" << endl;                
            else
            {
                string s;
                if (!getline(cin, s) || !s.length())
                    return 0;
                cout << "Thank you for: " << s << endl;
            }
        }
    }
    catch (Errno const &e)
    {
        cout << e.why() << endl;
    }
}
