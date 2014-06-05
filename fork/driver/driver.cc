#include <iostream>
#include <unistd.h>

#include <bobcat/fork>

using namespace std;
using namespace FBB;

class Background: public Fork
{
    public:
        void childProcess()     override;
        void parentProcess()    override;
};

void Background::childProcess()
{
    for (int idx = 0; idx < 3; ++idx)
    {
        cout << "Hello world # " << idx << endl;
        sleep(1);
    }
    throw 0;    // caught in main()
}    

void Background::parentProcess()
{
    cout << "Waiting for the child process to end...\n";

    cout << "The child returns value " << waitForChild() << endl;
}    

int main()
try
{
    Background bg;

    bg.fork();
    cout << "This is from the parent\n";

    return 0;
}
catch(int x)
{
    cout << "The child terminates with: " << x << endl;
    return x;
}


