
#include <unistd.h>
#include <iostream>
#include <thread>

#include <bobcat/process>
#include <bobcat/stringline>

using namespace FBB;
using namespace std;

void collect(ostream *outStream, istream *inStream)
{
    *outStream << inStream->rdbuf();
}

int main()
{
    Process genall("./genall");

    genall.start();

    thread outThread(collect, &cout, &genall);
    thread errThread(collect, &cerr, &genall.cerr());

    genall << cin.rdbuf();
    genall.close();

    outThread.join();
    errThread.join();

    genall.waitForChild();

}
