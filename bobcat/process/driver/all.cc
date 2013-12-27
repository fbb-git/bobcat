#include <iostream>
#include <thread>

#include <unistd.h>

#include "../process"

using namespace FBB;
using namespace std;

//CODE
void collect(ostream *outStream, streambuf *rdbuf)
{
    *outStream << rdbuf << flush;
}

int main()
{
    string cmd(getcwd(0, 0));
    cmd += "/cincoutcerr";

    Process all(Process::ALL, cmd);

    all.start();

    thread outThread(collect, &cout, all.childOutStream().rdbuf());
    thread errThread(collect, &cerr, all.childErrStream().rdbuf());

    all << cin.rdbuf() << eoi;

    outThread.join();
    errThread.join();
}
//=
