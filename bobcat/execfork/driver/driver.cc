#include <iostream>
#include <bobcat/execfork>

using namespace std;
using namespace FBB;

int main()
{
    ExecFork ef;

    if (ef.execute("/bin/cp driver.cc /tmp"))
        cout << "driver.cc now copied to /tmp\n";
    else
        cout << "could not copy driver.cc to /tmp\n";
}
