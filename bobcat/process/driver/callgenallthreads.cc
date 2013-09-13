// Compile as, e.g., 
//
//          g++ --std=c++11 -pthread -o run callgenallthreads.cc -lbobcat
//
// Run as, e.g.,
//          run './genall 3' < genall.cc

#include <iostream>
#include <thread>

#include <bobcat/process>

using namespace FBB;
using namespace std;

void collect(ostream *outStream, istream *inStream)
{
    *outStream << inStream->rdbuf();
}

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        cout << "provide the path to the program to start as child process\n"
                "provide input to that program on cin\n";

        return 0;
    }

    Process genall(argv[1]);

    genall.start();

    thread outThread(collect, &cout, &genall);
    thread errThread(collect, &cerr, &genall.cerr());

    genall << cin.rdbuf();
    genall.close();

    outThread.join();
    errThread.join();

    genall.waitForChild();

}
