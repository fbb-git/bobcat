//#include <bobcat/process>
#include "../process"

#include <thread>
#include <iostream>

using namespace std;
using namespace FBB;

void collect(streambuf *buf)
{
    cout << buf;
}

int main()
try
{
    Process sha1sum(Process::CIN | Process::COUT, "/usr/bin/sha1sum");

    sha1sum.start();

    thread out(collect, sha1sum.childOutStream().rdbuf());

    sha1sum << cin.rdbuf() << eoi;

    out.join();
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
