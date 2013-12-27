//#include <bobcat/process>
#include "../process"

#include <iostream>
#include <string>

using namespace std;
using namespace FBB;

int main()
try
{
    Process sha1sum(Process::CIN | Process::COUT, "/usr/bin/sha1sum");

    sha1sum.start();

    sha1sum << cin.rdbuf() << eoi;

    string line;
    while (getline(sha1sum, line))
        cout << line << '\n';
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
