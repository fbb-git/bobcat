/*
                              driver.cc
*/

#include <iostream>
#include <string>
#include <bobcat/onekey>

using namespace std;
using namespace FBB;

int main()
{
    try
    {
        OneKey onekey;

        cout << "Usage: 1: next chars are echoed, 0: no echo, q: quits\n";

        while (true)
        {
            char c;
    
            cout << "ready...\n";
            cout << "Got character '" << (c = onekey.get()) << "'\n";

            switch (c)
            {
                case '1':    
                    onekey.setEcho(OneKey::ON);
                break;

                case '0':    
                    onekey.setEcho(OneKey::OFF);
                break;

                case 'q':
                return 0;    
            }
        }
    }
    catch (Errno const &e)
    {
        cout << e.why() << endl;
        return e.which();
    }
}

