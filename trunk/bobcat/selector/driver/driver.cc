#include "../selector"
#include "../../errno/errno"

#include <string>
#include <iostream>

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
