//#include <bobcat/process>
#include "../process"

#include <iostream>

using namespace std;
using namespace FBB;

int main()
try
{
    Process gpg(Process::CIN,
    "/usr/bin/gpg --quiet --batch --decrypt");

    gpg.start();
    gpg << cin.rdbuf() << eoi;
}
catch (exception const &err)
{
    cerr << err.what() << endl;
    return 0;
}
catch (int x)
{
    return 0;
}
