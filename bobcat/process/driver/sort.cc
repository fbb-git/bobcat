#include <thread>
#include <iostream>

#include "../../processenums/processenums"
#include "../../processdata/processdata.decl"
#include "../process"

using namespace std;
using namespace FBB;

void collect(streambuf *buf)
{
    cout << buf;
}

int main()
try
{
    Process sort(Process::CIN | Process::COUT, "/usr/bin/sort");

    sort.start();

    thread out(collect, sort.childOutStream().rdbuf());

    sort << cin.rdbuf() << eoi;

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
